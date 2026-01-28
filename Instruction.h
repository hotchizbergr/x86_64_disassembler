#pragma once

#include <Windows.h>
#include <WinDNS.h>
#include <string>
#include <map>
#include "REX.h"
#include "Opcode.h"
#include "ModRM.h"
#include "SIB.h"
#include "Basic.h"

class Instruction
{
public:
	Instruction();
	//
	// Method
	//
	static bool IsPrefix(BYTE);

	//
	// Member
	//
	int		m_Size;

private:
	//
	// Member
	//
	BYTE	m_Prefix;
	REX		m_Rex;
	DWORD	m_Opcode;
	ModRM	m_ModRM;
	SIB		m_SIB;

	bool	m_pfx66;
	bool	m_pfx67;
	bool	m_pfxF0;
	bool	m_pfxF2;
	bool	m_pfxF3;

	SEGMENT		m_SegOverride;
	MNEMONIC	m_Mnemonic;
	QWORD		m_Operand1;
	QWORD		m_Operand2;
	QWORD		m_Displacement;
	QWORD		m_Immediate;

	//DWORD		m_dwSize;
	//std::map<MNEMONIC, std::string> m_MnemonicMap;

	friend class Opcode;
	friend class ModRM;
};