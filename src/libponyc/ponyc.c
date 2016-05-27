#include "ponyc.h"
#include "ast/error.h"
#include "codegen/codegen.h"
#include "pkg/package.h"
#include "evaluate/evaluate.h"

bool ponyc_init(pass_opt_t* options)
{
  if (!codegen_init(options))
    return false;

  if (!package_init(options))
    return false;

  return true;
}

void ponyc_shutdown(pass_opt_t* options)
{
  errors_print(options->check.errors);
  package_done();
  codegen_shutdown(options);
  methodtab_done();
  eval_cache_done();
  stringtab_done();
}
