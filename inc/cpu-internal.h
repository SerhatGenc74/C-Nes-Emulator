#include "common.h"
#ifndef INTERNAL_H
#define INTERNAL_H

typedef enum 
{
    FLAG_CARRY     = 0x01,
    FLAG_ZERO      = 0x02,
    FLAG_INTERRUPT = 0x04,
    FLAG_DECIMAL   = 0x08,
    FLAG_BREAK     = 0x10,
    FLAG_UNUSED    = 0x20,
    FLAG_OVERFLOW  = 0x40,
    FLAG_NEGATIVE  = 0x80
} Cpu_Flags_t;

typedef enum 
{
    BP_CARRY     = 0,
    BP_ZERO      = 1,
    BP_INTERRUPT = 2,
    BP_DECIMAL   = 3,
    BP_BREAK     = 4,
    BP_UNUSED    = 5,
    BP_OVERFLOW  = 6,
    BP_NEGATIVE  = 7
} Cpu_Flags_BP_t;

typedef struct 
{
word pc;                //Program Counter
byte sp;                //Stack Pointer
byte a,x,y ;            // Registers
byte flag;              //Flags
byte cpu_ram[0x800];   //RAM

} CPU;




typedef struct 
{
    void (*OPCODES)(CPU*);
    
} Instruction;
 


#endif
