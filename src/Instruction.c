#include "cpu-internal.h"
#include "cpu6502.h"

// https://www.nesdev.org/wiki/Instruction_reference

// Add with Carry
void ADC(CPU *cpu)
{
    u16 result = (u16)cpu->a + (u16)cpu->fetched_data + (u16)(cpu->flag & FLAG_CARRY);

    if (result > 0xFF)
    {
        cpu->flag |= FLAG_CARRY;
    }
    else
    {
        cpu->flag &= ~FLAG_CARRY;
    }
    if (result == 0)
    {
        cpu->flag |= FLAG_ZERO;
    }
    else
    {
        cpu->flag &= ~FLAG_ZERO;
    }

    if (result & FLAG_NEGATIVE)
    {
        cpu->flag |= FLAG_NEGATIVE;
    }
    else
    {
        cpu->flag &= ~FLAG_NEGATIVE;
    }

    if ((result ^ cpu->a) & (result ^ cpu->fetched_data) & FLAG_NEGATIVE)
    {
        cpu->flag |= FLAG_OVERFLOW;
    }
    else
    {
        cpu->flag &= ~FLAG_OVERFLOW;
    }
    // Can make (u8)result
    cpu->a = result & 0x00F;
}

// Bitwise AND
void AND(CPU *cpu)
{
    u16 result = (u16)cpu->a & (u16)cpu->fetched_data;
    if (result == 0)
    {
        cpu->flag |= FLAG_ZERO;
    }
    else
    {
        cpu->flag &= ~FLAG_ZERO;
    }

    if (result & FLAG_NEGATIVE)
    {
        cpu->flag |= FLAG_NEGATIVE;
    }
    else
    {
        cpu->flag &= ~FLAG_NEGATIVE;
    }

    cpu->a = result & 0x00FF;
}

// Arithmetic Shift Left
void ASL(CPU *cpu)
{
    u16 result = (u16)cpu->fetched_data << 1;

    if (result > 0x00FF)
    {
        cpu->flag |= FLAG_CARRY;
    }
    else
    {
        cpu->flag &= ~FLAG_CARRY;
    }
    if (result == 0)
    {
        cpu->flag |= FLAG_ZERO;
    }
    else
    {
        cpu->flag &= ~FLAG_ZERO;
    }
    if (result & FLAG_NEGATIVE)
    {
        cpu->flag |= FLAG_NEGATIVE;
    }
    else
    {
        cpu->flag &= ~FLAG_NEGATIVE;
    }

    // If addrmode ACCUMULATOR
    if (lookup_table[cpu->opcode].addrmode == &ACC)
    {
        cpu->a = result & 0x00FF;
    }
    // Other ADDRMODE
    else
    {
        cpu_write(cpu, cpu->address_abs, (u8)result);
    }
}
// Branch if Carry Clear
void BCC(CPU *cpu)
{
    if ((cpu->flag & FLAG_CARRY) == 0)
    {
        int8_t offset = (int8_t)cpu->fetched_data;

        cpu->pc = cpu->pc + offset;
    }
}
// Branch if Carry Set
void BCS(CPU *cpu)
{

    if (cpu->flag & FLAG_CARRY)
    {
        int8_t offset = (int8_t)cpu->fetched_data;

        cpu->pc = cpu->pc + offset;
    }
}
void BEQ(CPU *cpu)
{
    if (cpu->flag & FLAG_ZERO)
    {
        
        int8_t offset = (int8_t)cpu->fetched_data;

        cpu->pc = cpu->pc + offset;
    }
    
}
void BIT(CPU *cpu)
{
    u8 result = cpu->a & cpu->fetched_data;
    if (result == 0)
    {
        cpu->flag |= FLAG_ZERO;
    }
    else
    {
        cpu->flag &= ~FLAG_ZERO;
    }
    if (result & FLAG_OVERFLOW)
    {
          cpu->flag |= FLAG_OVERFLOW;
    }
    else
    {
        cpu->flag &= ~FLAG_OVERFLOW;
    }
    if (result & FLAG_NEGATIVE)
    {
        cpu->flag |= FLAG_NEGATIVE;
    }
    else
    {
        cpu->flag &= ~FLAG_NEGATIVE;
    }
    
    
}
void BMI(CPU *cpu)
{
    if (cpu->flag & FLAG_NEGATIVE)
    {
        
        int8_t offset = (int8_t)cpu->fetched_data;

        cpu->pc = cpu->pc + offset;
    }
    
}
void BNE(CPU *cpu)
{
    if (cpu->flag & FLAG_ZERO)
    {
        
        int8_t offset = (int8_t)cpu->fetched_data;

        cpu->pc = cpu->pc + offset;
    }
    
}
void BPL(CPU *cpu)
{
    if (cpu->flag & FLAG_ZERO)
    {
        
        int8_t offset = (int8_t)cpu->fetched_data;

        cpu->pc = cpu->pc + offset;
    }
    
}
void BRK(CPU *cpu)
{
}
void BVC(CPU *cpu)
{
    if ((cpu->flag & FLAG_OVERFLOW) == 0)
    {
        int8_t offset = (int8_t)cpu->fetched_data;

        cpu->pc = cpu->pc + offset;
    }
    
}
void BVS(CPU *cpu)
{
    if (cpu->flag & FLAG_OVERFLOW)
    {
        int8_t offset = (int8_t)cpu->fetched_data;

        cpu->pc = cpu->pc + offset;
    }
    
}
void CLC(CPU *cpu)
{
    cpu->flag &= ~FLAG_CARRY;
}
void CLD(CPU *cpu)
{
    cpu->flag &= ~FLAG_DECIMAL;
}
void CLI(CPU *cpu)
{
    cpu->flag &= ~FLAG_INTERRUPT;

}
void CLV(CPU *cpu)
{
    cpu->flag &= ~FLAG_OVERFLOW;

}
void CMP(CPU *cpu)
{
    
}
void CPX(CPU *cpu)
{
   
}
void CPY(CPU *cpu)
{
}
void DEC(CPU *cpu)
{
}
void DEX(CPU *cpu)
{
}
void DEY(CPU *cpu)
{
}

void EOR(CPU *cpu)
{
}
void INC(CPU *cpu)
{
}
void INX(CPU *cpu)
{
}
void INY(CPU *cpu)
{
}
void JMP(CPU *cpu)
{
}
void JSR(CPU *cpu)
{
}
void LDA(CPU *cpu)
{
}
void LDX(CPU *cpu)
{
}
void LDY(CPU *cpu)
{
}
void LSR(CPU *cpu)
{
}

void NOP(CPU *cpu)
{
}
void ORA(CPU *cpu)
{
}
void PHA(CPU *cpu)
{
}

void PHP(CPU *cpu)
{
}
void PLA(CPU *cpu)
{
}

void PLP(CPU *cpu)
{
}
void ROL(CPU *cpu)
{
}

void ROR(CPU *cpu)
{
}
void RTI(CPU *cpu)
{
}
void RTS(CPU *cpu)
{
}

void SBC(CPU *cpu)
{
}
void SEC(CPU *cpu)
{
}
void SED(CPU *cpu)
{
}

void SEI(CPU *cpu)
{
}

void STA(CPU *cpu)
{
}
void STX(CPU *cpu)
{
}
void STY(CPU *cpu)
{
}
void TAX(CPU *cpu)
{
}
void TAY(CPU *cpu)
{
}
void TSX(CPU *cpu)
{
}
void TXA(CPU *cpu)
{
}
void TXS(CPU *cpu)
{
}
void TYA(CPU *cpu)
{
}
