#include "cpu6502.h"

//https://www.nesdev.org/wiki/CPU_memory_map
u8 cpu_read(CPU *cpu,u16 address)
{
    //INTERNAL RAM
    if (address >= 0x0000 && address <= 0x07FF)
    {
        return cpu->cpu_ram[address % 0x0800];
    }
    //NES PPU registers
    if (address >= 0x2000 && address <= 0x2007)
    {
        return 0x00;    
    }
    //NES APU and I/O registers
    if (address >= 0x4000 && address <= 0x4017)
    {
        
    }
    
}
void cpu_write(CPU* cpu,u16 address,u8 data)
{
     if (address >= 0x0000 && address <= 0x07FF)
    {
        cpu->cpu_ram[address % 0x0800] = data;
    }
    //NES PPU registers
    if (address >= 0x2000 && address <= 0x2007)
    {
        return 0x00;    
    }
    //NES APU and I/O registers
    if (address >= 0x4000 && address <= 0x4017)
    {
        
    }
}

//https://www.nesdev.org/wiki/CPU_power_up_state
void cpu_reset(CPU *cpu)
{
    cpu->a = 0;
    cpu->x = 0;
    cpu->y = 0;

    cpu->sp = 0xFD;
    cpu->pc = 0xFFFC;
    cpu->flag = FLAG_INTERRUPT | FLAG_UNUSED; // Interrupt flag raise 1 and unusde always 1c

    //Program start address
    u8 lo = cpu_read(cpu,0xFFFC);
    u8 hi = cpu_read(cpu,0xFFFD);

    cpu->pc = (hi << 8) | lo;

}
