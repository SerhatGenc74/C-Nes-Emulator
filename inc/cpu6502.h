#include "common.h"
#include "cpu-internal.h"

#ifndef CPU_6520_H
#define CPU_6520_H

extern Instruction lookup_table[256];

//Read data from ram
u8 cpu_read(CPU *cpu,u16 address);

//Write data to 
void cpu_write(CPU *cpu,u16 address,u8 data);

//reset cpu
void cpu_reset(CPU *cpu);

#endif