#pragma once

#include <Windows.h>
#include <vector>
#include <bitset>
#include "Instruction.h"
#include "Opcode.h"

class Disassembler
{
public:
	Disassembler();
	//
	// Method
	//
	void Run(LPBYTE lpFile, DWORD dwCSraw, DWORD dwCSsize);
	bool Is64Bit() const;

	//
	// Member
	//
	void (*m_oi[0xFF+1])(DWORD, Disassembler*, Instruction*);	// prefix/opcode interpreter
	void (*m_mi[0xFF+1])(BYTE,	Disassembler*, Instruction*);	// modr/m interpreter
	void (*m_si[0xFF+1])(DWORD, Disassembler*, Instruction*);	// sib interpreter

private:
	//
	// Method
	//
	void	Disassemble();
	BYTE	ReadByte();
	DWORD	ReadBytes(int n);

	void HandlePrefix(Instruction&, DWORD);
	void HandleOpcode(Instruction&, DWORD);
	void HandleModRM(Instruction&, DWORD);
	void HandleSIB(Instruction&, DWORD);

	void PrintInstruction(Instruction&, DWORD);

	//
	// Member
	//
	WORD	m_wMachine;
	LPBYTE	m_lpFile;
	DWORD	m_dwCursor;
	DWORD	m_dwCSraw;
	DWORD	m_dwCSsize;

	std::vector<Instruction> m_InstList;
	int				m_nBytes;

	friend class Opcode;
	friend class ModRM;
};

inline bool Disassembler::Is64Bit() const
{
	return m_wMachine == IMAGE_FILE_MACHINE_AMD64;
}

inline BYTE Disassembler::ReadByte()
{
	return m_lpFile[m_dwCursor++];
}

inline void Disassembler::HandlePrefix(Instruction& i, DWORD dw)
{

}

inline void Disassembler::HandleOpcode(Instruction& i, DWORD dw)
{
	(this->m_oi[dw])(dw, this, &i);
}

inline void Disassembler::HandleModRM(Instruction& i, DWORD dw)
{
	(this->m_mi[dw])((BYTE)dw, this, &i);
}

inline void Disassembler::HandleSIB(Instruction& i, DWORD dw)
{
	//(this->m_si[0])(this, &i);
}