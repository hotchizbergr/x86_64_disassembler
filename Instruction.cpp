#include "Instruction.h"

bool Instruction::IsPrefix(BYTE b)
{
	bool legacy = (b == 0x26)	// SEG=ES (in 64-bit, ignored)
		|| (b == 0x2E)			// SEG=CS (in 64-bit, ignored)
		|| (b == 0x36)			// SEG=SS (in 64-bit, ignored)
		|| (b == 0x3E)			// SEG=DS (in 64-bit, ignored)
		|| (b == 0x64)			// SEG=FS
		|| (b == 0x65)			// SEG=GS
		|| (b == 0x66)			// operand size
		|| (b == 0x67)			// address size
		|| (b == 0xF0)			// LOCK
		|| (b == 0xF2)			// REPNE XACQUIRE
		|| (b == 0xF3);			// REP/REPE XRELEASE

	bool rex = (b == 0x40)		// REX
		|| (b == 0x41)			// REX.B
		|| (b == 0x42)			// REX.X
		|| (b == 0x43)			// REX.XB
		|| (b == 0x44)			// REX.R
		|| (b == 0x45)			// REX.RB
		|| (b == 0x46)			// REX.RX
		|| (b == 0x47)			// REX.RXB
		|| (b == 0x48)			// REX.W
		|| (b == 0x49)			// REX.WB
		|| (b == 0x4A)			// REX.WX
		|| (b == 0x4B)			// REX.WXB
		|| (b == 0x4C)			// REX.WR
		|| (b == 0x4D)			// REX.WRB
		|| (b == 0x4E)			// REX.WRX
		|| (b == 0x4F);			// REX.WRXB

	return legacy || rex;
}

Instruction::Instruction()
	: m_Prefix(0)
	, m_Opcode(0)
	, m_pfx66(false)
	, m_pfx67(false)
	, m_pfxF0(false)
	, m_pfxF2(false)
	, m_pfxF3(false)
	, m_SegOverride(SEGMENT::NONE)
	, m_Mnemonic(MNEMONIC::NONE)
	, m_Displacement(0)
	, m_Immediate(0)
	, m_Size(0)
{
}