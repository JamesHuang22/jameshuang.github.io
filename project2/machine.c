#include <stdio.h>
#include "machine.h"

int decode_instruction(Word instruction, unsigned short *const opcode,
                       unsigned int *const imm_or_addr,
                       unsigned short *const reg1,
                       unsigned short *const reg2)
{
  if ( opcode == 0 || imm_or_addr == 0 || reg1 == 0 || reg2 == 0 ){
    return 0;
  }
  *opcode = (instruction & 0xF8000000 ) >> 27 ;
  *imm_or_addr = (instruction & 0x7FFFC00) >> 10;
  *reg1 = (instruction & 0x3E0) >> 5; 
  *reg2 = instruction & 0x1F;
  return 1;

}
void print_instruction(Word instruction){ 
  unsigned int opcode;
  char *const opCode_arr [] = {"halt","add","sub","mul","div","mod","and",
             "or","neg","not","eql","neq","lt","le","gt","ge","li","lw",
             "sw","move","branch","syscall"};
  if(valid_instruction(instruction)!= VALID){
    return;
  }
  
  opcode = (instruction & 0xF8000000 ) >> 27;
  if(opcode == 0 || opcode == 21){
      printf("%s\n", opCode_arr[opcode]);
    }
  if(opcode > 0 && opcode < 21){
    printf("%s", opCode_arr[opcode]);
    if(opcode == 20){
      printf("\t%04d\n",(instruction & 0x7FFFC00) >> 10);
    }
    if(opcode >= 1 && opcode <=19){
      printf("\tR%02d\n", (instruction & 0x3E0) >> 5);
    }
    if((opcode >= 1 && opcode <= 7) || (opcode >= 10 && opcode <=15) || opcode ==19){
      printf(" R");
      printf("%02d\n", instruction & 0x1F);
    }
    if(opcode >= 16 && opcode <=18){
      printf(" ");
      printf("%04d\n",(instruction & 0x7FFFC00) >> 10);
    }
  }
}

int load_program(Word memory[], unsigned int start_addr, const Word program[],
                 unsigned int program_size){
  Word temp;
  int i = 0;
  if(memory == 0 || program == 0){
    return 0;
  }
  if(program_size > sizeof(memory)/sizeof(memory[0])){
    return 0;
  }
  if(start_addr %4 != 0 || start_addr > sizeof(memory)){
    return 0;
  }   
  for (i = start_addr; i < program_size; i++){
    unsigned int addr_imm;
    addr_imm = (program[i] & 0x7FFFC00) >> 10;
    addr_imm += start_addr;
    if(addr_imm > 8191){
      return 0;
    }
    else{
      temp = (program[i] &(~ (0x7FFFC00))) | (addr_imm << 10);
    
      if (valid_instruction(temp) != VALID)
  return 0;
      else
  memory[i + start_addr/4] = temp; 
    }
  }
  return 1;
}

Instr_status valid_instruction(Word word){
  unsigned int option_code, reg_1,reg_2,addre_imm;
  option_code = (word & 0xF8000000 ) >> 27;
  reg_1 = (word & 0x3E0) >> 5;
  reg_2 = word & 0x1F;
  addre_imm = (word & 0x7FFFC00) >> 10;
  if ( option_code > 21 || option_code < 0){
    return BADOPCODE;
  }else if (reg_1 > 17 || reg_1 <0) {
    return BADREG1;
  }else if (reg_2 > 17 || reg_2 <0){
    return BADREG1;
  }else if (addre_imm > 8191 || addre_imm < 0 || addre_imm %4 != 0){
    return BADADDR;
  }
  else 
    return VALID;
}
