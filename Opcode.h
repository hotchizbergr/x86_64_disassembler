#pragma once
#include <Windows.h>

class Disassembler;
class Instruction;

class Opcode
{
public:
	static void Interpret_00_0F(DWORD, Disassembler*, Instruction*);
	static void Interpret_10_1F(DWORD, Disassembler*, Instruction*);
	static void Interpret_20_2F(DWORD, Disassembler*, Instruction*);
	static void Interpret_30_3F(DWORD, Disassembler*, Instruction*);
	static void Interpret_40_4F(DWORD, Disassembler*, Instruction*);
	static void Interpret_50_5F(DWORD, Disassembler*, Instruction*);
	static void Interpret_60_6F(DWORD, Disassembler*, Instruction*);
	static void Interpret_70_7F(DWORD, Disassembler*, Instruction*);
	static void Interpret_80_8F(DWORD, Disassembler*, Instruction*);
	static void Interpret_90_9F(DWORD, Disassembler*, Instruction*);
	static void Interpret_A0_AF(DWORD, Disassembler*, Instruction*);
	static void Interpret_B0_BF(DWORD, Disassembler*, Instruction*);
	static void Interpret_C0_CF(DWORD, Disassembler*, Instruction*);
	static void Interpret_D0_DF(DWORD, Disassembler*, Instruction*);
	static void Interpret_E0_EF(DWORD, Disassembler*, Instruction*);
	static void Interpret_F0_FF(DWORD, Disassembler*, Instruction*);
};