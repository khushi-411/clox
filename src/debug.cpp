#include <stdio.h>
#include <iostream>

#include "debug.h"
#include "value.h"


void disassembleChunk(Chunk* chunk, const char* name) {
  std::cout << "== " << name << " ==\n";
  for (int offset = 0; offset < chunk->count;) {
    offset = disassembleInstruction(chunk, offset);
  }
}


int disassembleInstruction(Chunk* chunk, int offset) {
  std::cout << offset;

  if (offset > 0 && chunk->lines[offset] == chunk->lines[offset - 1]) {
    std::cout << "    |   ";
  } else {
    std::cout << "    ";
    std::cout << chunk->lines[offset];
  }

  uint8_t instruction = chunk->code[offset];
  switch (instruction) {
    case OP_CONSTANT:
      return constantInstruction("OP_CONSTANT", chunk, offset);
    case OP_RETURN:
      return simpleInstruction("OP_RETURN", offset);
    default:
      std::cout << "Unknown opcode " << instruction << "\n";
      return offset + 1;
  }
}


int constantInstruction(const char* name, Chunk* chunk, int offset) {
  uint8_t constant = chunk->code[offset + 1];
  std::cout << "   " << name << " " << constant << " ";
  printValue(chunk->constants.values[constant]);
  std::cout << "\n";
  return offset + 2;
}


int simpleInstruction(const char* name, int offset) {
  std::cout << "  " << name << "\n";
  return offset + 1;
}
