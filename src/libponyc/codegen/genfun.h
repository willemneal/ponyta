#ifndef CODEGEN_GENFUN_H
#define CODEGEN_GENFUN_H

#include "codegen.h"
#include "gentype.h"

LLVMValueRef genfun_proto(compile_t* c, gentype_t* g, const char *name,
  ast_t* typeargs);

LLVMValueRef genfun_fun(compile_t* c, gentype_t* g, const char *name,
  ast_t* typeargs);

LLVMValueRef genfun_be(compile_t* c, gentype_t* g, const char *name,
  ast_t* typeargs, int index);

LLVMValueRef genfun_new(compile_t* c, gentype_t* g, const char *name,
  ast_t* typeargs);

LLVMValueRef genfun_newbe(compile_t* c, gentype_t* g, const char *name,
  ast_t* typeargs, int index);

LLVMValueRef genfun_newdata(compile_t* c, gentype_t* g, const char *name,
  ast_t* typeargs);

LLVMValueRef genfun_box(compile_t* c, gentype_t* g);

bool genfun_methods(compile_t* c, gentype_t* g);

#endif