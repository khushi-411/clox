#ifndef clox_debug_h
#define clox_debug_h

#include "chunk.h"


void disassembleChunk(Chunk* chunk, const char* name);
int disassembleInstruction(Chunk* chunk, int offset);
int simpleInstruction(const char* name, int offset);
int constantInstruction(const char* name, Chunk* chunk, int offset);
int byteInstruction(const char* name, Chunk* chunk, int offset);
int jumpInstruction(const char* name, int sign, Chunk* chunk, int offset);


#endif
