#include "ModRM.h"
#include "Disassembler.h"
#include "Instruction.h"
#include "Opcode.h"

ModRM::ModRM()
	: mod(0)
	, reg(0)
	, rm(0)
	, hasDisp8(false)
	, hasDisp32(false)
	, hasSIB(false)
{
}

ModRM& ModRM::operator=(const BYTE& modrm)
{
    rm  = modrm & 0x7;
    reg = (modrm >> 3) & 0x7;
    mod = (modrm >> 6) & 0x3;

    if (mod < 3 && rm == 4)
        hasSIB = true;

    switch (mod) {
    case 0:
        hasDisp8 = false;
        hasDisp32 = false;
        break;
    case 1:
        hasDisp8 = true;
        hasDisp32 = false;
        break;
    case 2:
        hasDisp8 = false;
        hasDisp32 = true;
        break;
    case 3:
        hasDisp8 = false;
        hasDisp32 = false;
        break;
    }

    if (mod == 0 && rm == 5) {
        hasDisp8 = false;
        hasDisp32 = true;
    }

    return *this;
}

void ModRM::Interpret_00_0F(BYTE modrm, Disassembler* d, Instruction* i)
{

}

void ModRM::Interpret_10_1F(BYTE modrm, Disassembler* d, Instruction* i)
{

}

void ModRM::Interpret_20_2F(BYTE modrm, Disassembler* d, Instruction* i)
{

}

void ModRM::Interpret_30_3F(BYTE modrm, Disassembler* d, Instruction* i)
{

}

void ModRM::Interpret_40_4F(BYTE modrm, Disassembler* d, Instruction* i)
{

}

void ModRM::Interpret_50_5F(BYTE modrm, Disassembler* d, Instruction* i)
{

}

void ModRM::Interpret_60_6F(BYTE modrm, Disassembler* d, Instruction* i)
{

}

void ModRM::Interpret_70_7F(BYTE modrm, Disassembler* d, Instruction* i)
{

}

void ModRM::Interpret_80_8F(BYTE modrm, Disassembler* d, Instruction* i)
{

}

void ModRM::Interpret_90_9F(BYTE modrm, Disassembler* d, Instruction* i)
{

}

void ModRM::Interpret_A0_AF(BYTE modrm, Disassembler* d, Instruction* i)
{

}

void ModRM::Interpret_B0_BF(BYTE modrm, Disassembler* d, Instruction* i)
{

}

void ModRM::Interpret_C0_CF(BYTE modrm, Disassembler* d, Instruction* i)
{

}

void ModRM::Interpret_D0_DF(BYTE modrm, Disassembler* d, Instruction* i)
{

}

void ModRM::Interpret_E0_EF(BYTE modrm, Disassembler* d, Instruction* i)
{

}

void ModRM::Interpret_F0_FF(BYTE modrm, Disassembler* d, Instruction* i)
{

}