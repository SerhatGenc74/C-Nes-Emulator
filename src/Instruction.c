#include "cpu-internal.h"
#include "cpu6502.h"

//https://www.nesdev.org/wiki/Instruction_reference

void ADC(CPU *cpu)
{
    u16 temp = (u16)cpu->a + (u16)cpu->fetched_data + (u16)(cpu->flag & FLAG_CARRY);

    if (temp > 0xFF)
    {
        cpu->flag |= FLAG_CARRY;
    }
    else
    {
        cpu->flag &= ~FLAG_CARRY;
    }
    if (temp == 0)
    {
        cpu->flag |= FLAG_ZERO;
    }
    else
    {
        cpu->flag &= ~FLAG_ZERO;
    }

    if (temp & FLAG_NEGATIVE)
    {
        cpu->flag |= FLAG_NEGATIVE;
    }
    else
    {
        cpu->flag &= ~FLAG_NEGATIVE;
    }


    if ((temp ^ cpu->a) & (temp ^ cpu->fetched_data) & FLAG_NEGATIVE)   
    {
        cpu->flag |= FLAG_OVERFLOW;
    }
    else
    {
        cpu->flag &= ~FLAG_OVERFLOW;
    }
}

void AND(CPU* cpu)
{

}