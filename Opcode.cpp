#include "Opcode.h"
#include "Disassembler.h"
#include "Instruction.h"

void Opcode::Interpret_00_0F(DWORD opcode, Disassembler* d, Instruction* i)
{
	switch (opcode) {
	case 0x00:
		i->m_Mnemonic = MNEMONIC::ADD;
		break;
	case 0x01:
		break;
	case 0x02:
		break;
	case 0x03:
		break;
	case 0x04:
		break;
	case 0x05:
		break;
	case 0x06:
		break;
	case 0x07:
		break;
	case 0x08:
		break;
	case 0x09:
		break;
	case 0x0A:
		break;
	case 0x0B:
		break;
	case 0x0C:
		break;
	case 0x0D:
		break;
	case 0x0E:
		break;
	case 0x0F:
		break;
	}
	d->m_Parse.set(INSTRUCTION::MODRM, true);
	d->m_nBytes = 1;
}

void Opcode::Interpret_10_1F(DWORD opcode, Disassembler* d, Instruction* i)
{
	switch (opcode) {
	case 0x10:
		break;
	case 0x11:
		break;
	case 0x12:
		break;
	case 0x13:
		break;
	case 0x14:
		break;
	case 0x15:
		break;
	case 0x16:
		break;
	case 0x17:
		break;
	case 0x18:
		break;
	case 0x19:
		break;
	case 0x1A:
		break;
	case 0x1B:
		break;
	case 0x1C:
		break;
	case 0x1D:
		break;
	case 0x1E:
		break;
	case 0x1F:
		break;
	}
}

void Opcode::Interpret_20_2F(DWORD opcode, Disassembler* d, Instruction* i)
{

}

void Opcode::Interpret_30_3F(DWORD opcode, Disassembler* d, Instruction* i)
{

}

void Opcode::Interpret_40_4F(DWORD opcode, Disassembler* d, Instruction* i)
{

}

void Opcode::Interpret_50_5F(DWORD opcode, Disassembler* d, Instruction* i)
{

}

void Opcode::Interpret_60_6F(DWORD opcode, Disassembler* d, Instruction* i)
{

}

void Opcode::Interpret_70_7F(DWORD opcode, Disassembler* d, Instruction* i)
{

}

void Opcode::Interpret_80_8F(DWORD opcode, Disassembler* d, Instruction* i)
{

}

void Opcode::Interpret_90_9F(DWORD opcode, Disassembler* d, Instruction* i)
{

}

void Opcode::Interpret_A0_AF(DWORD opcode, Disassembler* d, Instruction* i)
{

}

void Opcode::Interpret_B0_BF(DWORD opcode, Disassembler* d, Instruction* i)
{

}

void Opcode::Interpret_C0_CF(DWORD opcode, Disassembler* d, Instruction* i)
{

}

void Opcode::Interpret_D0_DF(DWORD opcode, Disassembler* d, Instruction* i)
{

}

void Opcode::Interpret_E0_EF(DWORD opcode, Disassembler* d, Instruction* i)
{

}

void Opcode::Interpret_F0_FF(DWORD opcode, Disassembler* d, Instruction* i)
{

}