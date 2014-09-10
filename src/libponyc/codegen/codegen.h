#ifndef CODEGEN_H
#define CODEGEN_H

#include "colour.h"
#include "../ast/ast.h"

#include <llvm-c/Core.h>
#include <llvm-c/Target.h>
#include <llvm-c/Transforms/PassManagerBuilder.h>
#include <llvm-c/Analysis.h>

// Missing from C API.
char* LLVMGetHostCPUName();

#define GEN_NOVALUE ((LLVMValueRef)1)

typedef struct compile_context_t
{
  LLVMValueRef fun;
  LLVMBasicBlockRef restore_builder;

  struct compile_context_t* prev;
} compile_context_t;

typedef struct compile_t
{
  painter_t* painter;
  const char* filename;
  uint32_t next_type_id;

  char* triple;
  LLVMModuleRef module;
  LLVMTargetDataRef target_data;

  LLVMBuilderRef builder;
  LLVMPassManagerRef fpm;
  LLVMPassManagerBuilderRef pmb;

  LLVMTypeRef void_ptr;
  LLVMTypeRef descriptor_type;
  LLVMTypeRef descriptor_ptr;
  LLVMTypeRef object_type;
  LLVMTypeRef object_ptr;
  LLVMTypeRef msg_type;
  LLVMTypeRef msg_ptr;
  LLVMTypeRef actor_pad;
  LLVMTypeRef trace_type;
  LLVMTypeRef trace_fn;
  LLVMTypeRef dispatch_type;
  LLVMTypeRef dispatch_fn;
  LLVMTypeRef final_fn;

  LLVMValueRef personality;

  compile_context_t* context;
} compile_t;

bool codegen(ast_t* program, int opt, bool print_llvm);

LLVMValueRef codegen_addfun(compile_t*c, const char* name, LLVMTypeRef type);

void codegen_startfun(compile_t* c, LLVMValueRef fun);

void codegen_pausefun(compile_t* c);

void codegen_finishfun(compile_t* c);

#endif