#pragma once

enum class MNEMONIC
{
	NONE = -1,
	MOV,
	ADD,
	SUB,
	INC,
	DEC,
	XOR,
	CMP,
	JMP,
	JNE,
	TEST
};

enum class REGISTER_08
{
	NONE = -1,
	AL,
	CL,
	DL,
	BL,
	AH,
	CH,
	DH,
	BH,
	R8B,
	R9B,
	R10B,
	R11B,
	R12B,
	R13B,
	R14B,
	R15B
};

enum class REGISTER_16
{
	NONE = -1,
	AX,
	CX,
	DX,
	BX,
	SP,
	BP,
	SI,
	DI,
	R8W,
	R9W,
	R10W,
	R11W,
	R12W,
	R13W,
	R14W,
	R15W
};

enum class REGISTER_32
{
	NONE = -1,
	EAX,
	ECX,
	EDX,
	EBX,
	ESP,
	EBP,
	ESI,
	EDI,
	R8D,
	R9D,
	R10D,
	R11D,
	R12D,
	R13D,
	R14D,
	R15D
};

enum class REGISTER_64
{
	NONE = -1,
	RAX,
	RCX,
	RDX,
	RBX,
	RSP,
	RBP,
	RSI,
	RDI,
	R8,
	R9,
	R10,
	R11,
	R12,
	R13,
	R14,
	R15
};

enum class SEGMENT
{
	NONE = -1,
	CS,	// code segment
	DS,	// data segment
	SS,	// stack segment
	ES,
	FS,
	GS
};