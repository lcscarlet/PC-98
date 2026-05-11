#include <stdint.h>
#include <stdio.h>

#define MEMORY_SIZE 65536 // 64KB of memory, which is the maximum for a 16-bit address space

typedef struct {
	uint16_t ax; // Accumulator
	uint16_t bx; // Base
	uint16_t cx; // Counter
	uint16_t dx; // Data
	uint16_t ip; // Instruction pointer
	uint8_t  flags; // Our flags, of course!

} CPU_State;

uint8_t memory[MEMORY_SIZE]; // Our memory

uint8_t fetch_byte(CPU_State* cpu) {
	return memory[cpu->ip++];
}

uint16_t fetch_word(CPU_State* cpu) {
	uint16_t low = fetch_byte(cpu);
	uint16_t high = fetch_byte(cpu);
	return (high << 8) | low;
}



int main() {
	CPU_State cpu = { 0 }; //Initalize to zero

	//Manual memory test
	memory[0] = 0x41; // Hex code for letter 'A'
	memory[1] = 0x42; // 'B'
	memory[2] = 0x43; // 'C'

	cpu.ip = 0;

	printf("%c", fetch_byte(&cpu));
	printf("%c", fetch_byte(&cpu));
	printf("%c\n", fetch_byte(&cpu));

	return 0;
}