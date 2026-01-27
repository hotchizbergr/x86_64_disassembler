#pragma once
#include <Windows.h>
#include <map>
#include "Instruction.h"

class Disassembler;
class Instruction;

class ModRM
{
public:
	static void Interpret_00_0F(BYTE, Disassembler*, Instruction*);
	static void Interpret_10_1F(BYTE, Disassembler*, Instruction*);
	static void Interpret_20_2F(BYTE, Disassembler*, Instruction*);
	static void Interpret_30_3F(BYTE, Disassembler*, Instruction*);
	static void Interpret_40_4F(BYTE, Disassembler*, Instruction*);
	static void Interpret_50_5F(BYTE, Disassembler*, Instruction*);
	static void Interpret_60_6F(BYTE, Disassembler*, Instruction*);
	static void Interpret_70_7F(BYTE, Disassembler*, Instruction*);
	static void Interpret_80_8F(BYTE, Disassembler*, Instruction*);
	static void Interpret_90_9F(BYTE, Disassembler*, Instruction*);
	static void Interpret_A0_AF(BYTE, Disassembler*, Instruction*);
	static void Interpret_B0_BF(BYTE, Disassembler*, Instruction*);
	static void Interpret_C0_CF(BYTE, Disassembler*, Instruction*);
	static void Interpret_D0_DF(BYTE, Disassembler*, Instruction*);
	static void Interpret_E0_EF(BYTE, Disassembler*, Instruction*);
	static void Interpret_F0_FF(BYTE, Disassembler*, Instruction*);
};