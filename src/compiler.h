#ifndef clox_compiler_h
#define clox_compiler_h


#include "object.h"
#include "vm.h"


// void compile(const char* source);

// bool compile(const char* source, Chunk* chunk);

ObjFunction* compile(const char* source);
void markCompilerRoot();

#endif
