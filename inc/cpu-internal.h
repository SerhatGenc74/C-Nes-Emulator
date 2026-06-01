#include "common.h"
#ifndef INTERNAL_H
#define INTERNAL_H

typedef enum
{
    FLAG_CARRY = 0x01,
    FLAG_ZERO = 0x02,
    FLAG_INTERRUPT = 0x04,
    FLAG_DECIMAL = 0x08,
    FLAG_BREAK = 0x10,
    FLAG_UNUSED = 0x20,
    FLAG_OVERFLOW = 0x40,
    FLAG_NEGATIVE = 0x80
} Cpu_Flags_t;

typedef enum
{
    BP_CARRY = 0,
    BP_ZERO = 1,
    BP_INTERRUPT = 2,
    BP_DECIMAL = 3,
    BP_BREAK = 4,
    BP_UNUSED = 5,
    BP_OVERFLOW = 6,
    BP_NEGATIVE = 7
} Cpu_Flags_BP_t;

typedef struct
{
    u16 pc;            // Program Counter
    u8 sp;             // Stack Pointer
    u8 a, x, y;        // Registers
    u8 flag;           // Flags
    u8 cpu_ram[0x800]; // RAM

    u8 fetched_data;
    u16 address_abs;
} CPU;

typedef struct
{
    char name[4];
    void (*operate)(CPU *);  // OPERATION CODE
    void (*addrmode)(CPU *); // ADDRESS MODE
    u8 cycle;

} Instruction;

#endif
