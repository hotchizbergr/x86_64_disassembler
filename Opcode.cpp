#include "Opcode.h"
#include "Disassembler.h"
#include "Instruction.h"

void Opcode::Interpret_00_0F(DWORD opcode, Disassembler* d, Instruction* i)
{
	switch (opcode) {
	case 0x00:
		i->m_Mnemonic = MNEMONIC::ADD;
		break;
	case 0x03:
		i->m_Rex = 0x48;
		break;
	}
}

void Opcode::Interpret_10_1F(DWORD opcode, Disassembler* d, Instruction* i)
{
	switch (opcode) {
	case 0x10:
		break;
	}
}

void Opcode::Interpret_20_2F(DWORD opcode, Disassembler* d, Instruction* i)
{
	switch (opcode) {
	case 0x26:
		if (d->Is64Bit())
			break;
		i->m_SegOverride = SEGMENT::ES;
		break;
	case 0x2E:
		if (d->Is64Bit())
			break;
		i->m_SegOverride = SEGMENT::CS;
		break;
	}
}

void Opcode::Interpret_30_3F(DWORD opcode, Disassembler* d, Instruction* i)
{
	switch (opcode) {
	case 0x36:
		if (d->Is64Bit())
			break;
		i->m_SegOverride = SEGMENT::SS;
		break;
	case 0x3E:
		if (d->Is64Bit())
			break;
		i->m_SegOverride = SEGMENT::DS;
		break;
	}
}

void Opcode::Interpret_40_4F(DWORD opcode, Disassembler* d, Instruction* i)
{
	if (d->Is64Bit()) {
		i->m_Rex = opcode; return;
	}
	switch (opcode) {
	case 0x40:
		break;
	}
}

void Opcode::Interpret_50_5F(DWORD opcode, Disassembler* d, Instruction* i)
{

}

void Opcode::Interpret_60_6F(DWORD opcode, Disassembler* d, Instruction* i)
{
	switch (opcode) {
	case 0x64:
		i->m_SegOverride = SEGMENT::FS;
		break;
	case 0x65:
		i->m_SegOverride = SEGMENT::GS;
		break;
	case 0x66:
		i->m_pfx66 = true;
		break;
	case 0x67:
		i->m_pfx67 = true;
		break;
	}
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
	switch (opcode) {
	case 0xF0:
		i->m_pfxF0 = true;
		break;
	case 0xF2:
		i->m_pfxF2 = true;
		break;
	case 0xF3:
		i->m_pfxF3 = true;
		break;
	}
}