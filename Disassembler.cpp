#include "Disassembler.h"
#include "Opcode.h"
#include "ModRM.h"
#include "Util.h"
#include <iostream>
#include <iomanip>
#include <map>

#define OPCODE_INTERPRETER_INIT(s, e, f) for (int i = s; i <= e; ++i) m_oi[i] = f;
#define MODRM_INTERPRETER_INIT(s, e, f) for (int i = s; i <= e; ++i) m_mi[i] = f;

void Disassembler::Run(LPBYTE lpFile, DWORD dwCSraw, DWORD dwCSsize)
{
	m_lpFile	= lpFile + dwCSraw;
	m_dwCSraw	= dwCSraw;
	m_dwCSsize	= dwCSsize;
	m_dwCursor	= 0;

	m_Parse = std::bitset<8>(0);

	while (m_dwCursor <= m_dwCSsize)
		Disassemble();
}

void Disassembler::Disassemble()
{
	m_Parse.set(PREFIX, true);
	m_nBytes = 1;

	Instruction inst;

	// 1. legacy prefix

	// 2. rex prefix

	// 3. opcode

	// 4. modr/m

	// 5. sib

	// 6. displacement

	// 7. immediate

	//while (m_Parse.any()) {
	//	Instruction inst;
	//	DWORD dwStart = m_dwCursor, bytes = ReadBytes(m_nBytes);
	//	for (int i = PREFIX; i <= IMMEDIATE; ++i) {
	//		if (!m_Parse.test(i) || m_ih[i] == nullptr)
	//			continue;
	//		(this->*m_ih[i])(inst, ReadBytes(m_nBytes));
	//		inst.m_dwSize += m_nBytes;
	//		m_Parse.set(i, false);
	//	}
	//	PrintInstruction(inst, dwStart);
	//}
}

DWORD Disassembler::ReadBytes(int n)
{
	if (n > sizeof(DWORD))
		return 0;

	BYTE temp[sizeof(DWORD)] = { 0 };
	DWORD dwRet = 0;
	for (int i = 0; i < n; ++i)
		temp[i] = ReadByte();
	CopyMemory(&dwRet, temp, n);

	return dwRet;
}

void Disassembler::PrintInstruction(Instruction& inst, DWORD dwStart)
{
	// 1. print raw
	std::cout << std::uppercase << std::hex << std::setfill('0') <<
		std::setw(16) << static_cast<unsigned>(dwStart) << '\t';

	// 2. print instruction
	for (int i = 0; i < inst.m_dwSize; ++i) {
		std::cout << std::uppercase << std::hex << std::setfill('0') <<
			std::setw(2) << static_cast<unsigned>(m_lpFile[i]);
	}
	std::cout << '\t';

	// 3. print mnemonic
	std::cout << inst.GetMnemonicName();
	auto op1 = inst.GetOperand1();
	if (inst.GetOperand1() != REGISTER::NON)
		std::cout << ' ' << inst.GetOperand1Name();
	if (inst.GetOperand2() != REGISTER::NON)
		std::cout << ", " << inst.GetOperand2Name();
	std::cout << '\n';
}

Disassembler::Disassembler() :
	m_ih {
		nullptr,
		&Disassembler::HandlePrefix,
		&Disassembler::HandleOpcode,
		&Disassembler::HandleModRM,
		&Disassembler::HandleSIB
	}
{
	OPCODE_INTERPRETER_INIT(0x00, 0x0F, Opcode::Interpret_00_0F);
	OPCODE_INTERPRETER_INIT(0x10, 0x1F, Opcode::Interpret_10_1F);
	OPCODE_INTERPRETER_INIT(0x20, 0x2F, Opcode::Interpret_20_2F);
	OPCODE_INTERPRETER_INIT(0x30, 0x3F, Opcode::Interpret_30_3F);
	OPCODE_INTERPRETER_INIT(0x40, 0x4F, Opcode::Interpret_40_4F);
	OPCODE_INTERPRETER_INIT(0x50, 0x5F, Opcode::Interpret_50_5F);
	OPCODE_INTERPRETER_INIT(0x60, 0x6F, Opcode::Interpret_60_6F);
	OPCODE_INTERPRETER_INIT(0x70, 0x7F, Opcode::Interpret_70_7F);
	OPCODE_INTERPRETER_INIT(0x80, 0x8F, Opcode::Interpret_80_8F);
	OPCODE_INTERPRETER_INIT(0x90, 0x9F, Opcode::Interpret_90_9F);
	OPCODE_INTERPRETER_INIT(0xA0, 0xAF, Opcode::Interpret_A0_AF);
	OPCODE_INTERPRETER_INIT(0xB0, 0xBF, Opcode::Interpret_B0_BF);
	OPCODE_INTERPRETER_INIT(0xC0, 0xCF, Opcode::Interpret_C0_CF);
	OPCODE_INTERPRETER_INIT(0xD0, 0xDF, Opcode::Interpret_D0_DF);
	OPCODE_INTERPRETER_INIT(0xE0, 0xEF, Opcode::Interpret_E0_EF);
	OPCODE_INTERPRETER_INIT(0xF0, 0xFF, Opcode::Interpret_F0_FF);

	MODRM_INTERPRETER_INIT(0x00, 0x0F, ModRM::Interpret_00_0F);
	MODRM_INTERPRETER_INIT(0x10, 0x1F, ModRM::Interpret_10_1F);
	MODRM_INTERPRETER_INIT(0x20, 0x2F, ModRM::Interpret_20_2F);
	MODRM_INTERPRETER_INIT(0x30, 0x3F, ModRM::Interpret_30_3F);
	MODRM_INTERPRETER_INIT(0x40, 0x4F, ModRM::Interpret_40_4F);
	MODRM_INTERPRETER_INIT(0x50, 0x5F, ModRM::Interpret_50_5F);
	MODRM_INTERPRETER_INIT(0x60, 0x6F, ModRM::Interpret_60_6F);
	MODRM_INTERPRETER_INIT(0x70, 0x7F, ModRM::Interpret_70_7F);
	MODRM_INTERPRETER_INIT(0x80, 0x8F, ModRM::Interpret_80_8F);
	MODRM_INTERPRETER_INIT(0x90, 0x9F, ModRM::Interpret_90_9F);
	MODRM_INTERPRETER_INIT(0xA0, 0xAF, ModRM::Interpret_A0_AF);
	MODRM_INTERPRETER_INIT(0xB0, 0xBF, ModRM::Interpret_B0_BF);
	MODRM_INTERPRETER_INIT(0xC0, 0xCF, ModRM::Interpret_C0_CF);
	MODRM_INTERPRETER_INIT(0xD0, 0xDF, ModRM::Interpret_D0_DF);
	MODRM_INTERPRETER_INIT(0xE0, 0xEF, ModRM::Interpret_E0_EF);
	MODRM_INTERPRETER_INIT(0xF0, 0xFF, ModRM::Interpret_F0_FF);
}