#include "common.h"
#include "cpu-internal.h"

#ifndef CPU_6520_H
#define CPU_6520_H

//Read data from ram
byte cpu_read(CPU *cpu,word address);

//Write data to 
void cpu_write(CPU *cpu,word address,byte data);

//reset cpu
void cpu_reset(CPU *cpu);

#endif