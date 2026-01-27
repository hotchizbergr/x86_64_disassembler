#pragma once

#include <Windows.h>
#include <string>
#include <map>
#include "Opcode.h"

enum class MNEMONIC
{
	NON = -1,
	MOV,
	ADD,
	SUB,
	INC,
	DEC,
	XOR,
	CMP,
	JMP,
	JNE,
	TST
};

enum class REGISTER
{
	NON = -1,
	AL,
	AH,
	BL,
	BH,
	CL,
	CH,
	DL,
	DH,
	AX,
	BX,
	CX,
	DX,
	SI,
	DI,
	EAX,
	EBX,
	ECX,
	EDX,
	RAX,
	RBX,
	RCX,
	RDX,
	ESI,
	EDI,
	RSI,
	RDI,
	EBP,
	ESP,
	RBP,
	RSP
};

enum INSTRUCTION
{
	PREFIX,
	OPCODE,
	MODRM,
	SIB,
	DISPLACEMENT,
	IMMEDIATE,
	COUNT
};

class Instruction
{
public:
	Instruction();

	MNEMONIC GetMnemonic();
	REGISTER GetOperand1();
	REGISTER GetOperand2();

	std::string GetMnemonicName();
	std::string GetOperand1Name();
	std::string GetOperand2Name();

	int			m_dwSize;

private:
	BYTE		m_cPrefix;
	DWORD		m_dwOpcode;
	BYTE		m_cModRM;
	BYTE		m_cSIB;

	MNEMONIC	m_Mnemonic;
	REGISTER	m_Operand1;
	REGISTER	m_Operand2;
	BOOL		m_bIsDisplacementValid;
	DWORD		m_dwDisplacement;
	BOOL		m_bIsImmediateValid;
	DWORD		m_dwImmediate;

	//DWORD		m_dwSize;

	std::map<MNEMONIC, std::string> m_MnemonicMap;
	std::map<REGISTER, std::string> m_OperandMap;

	friend class Opcode;
	friend class ModRM;
};

inline MNEMONIC Instruction::GetMnemonic()
{
	return m_Mnemonic;
}

inline REGISTER Instruction::GetOperand1()
{
	return m_Operand1;
}

inline REGISTER Instruction::GetOperand2()
{
	return m_Operand2;
}

inline std::string Instruction::GetMnemonicName()
{
	return m_MnemonicMap[m_Mnemonic];
}

inline std::string Instruction::GetOperand1Name()
{
	return m_OperandMap[m_Operand1];
}

inline std::string Instruction::GetOperand2Name()
{
	return m_OperandMap[m_Operand2];
}