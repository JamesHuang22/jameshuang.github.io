/* (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

#define NUM_BYTES (8 * 1024) 
#define BYTES_PER_WORD 4
#define NUM_WORDS (NUM_BYTES / BYTES_PER_WORD)
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5
#define R6 6
#define R7 7
#define R8 8
#define R9 9
#define R10 10
#define R11 11
#define R12 12
#define R13 13
#define R14 14
#define R15 15
#define R16 16
#define R17 17

typedef unsigned int Word;

typedef enum { HALT, ADD, SUB, MUL, DIV, MOD, AND, OR, NEG, NOT, EQL, NEQ,
               LT, LE, GT, GE, LI, LW, SW, MOVE, BRANCH, SYSCALL } Op;

typedef enum { VALID, BADOPCODE, BADREG1, BADREG2, BADADDR } Instr_status;

int decode_instruction(Word instruction, unsigned short *const opcode,
                       unsigned int *const imm_or_addr,
                       unsigned short *const reg1,
                       unsigned short *const reg2);
void print_instruction(Word instruction);
int load_program(Word memory[], unsigned int start_addr, const Word program[],
                 unsigned int program_size);
Instr_status valid_instruction(Word word);
