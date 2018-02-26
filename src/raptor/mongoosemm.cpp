#include "mongoosemm.h"

namespace mongoose
{

std::shared_ptr<Context> Context::mg_start(mg_callbacks& callbacks, void* userData, const char** options)
{
  std::shared_ptr<Context> rtn(new mongoose::Context());
  rtn->ctx = ::mg_start(&callbacks, userData, options);

  return rtn;
}

Context::~Context()
{
  if(ctx)
  {
    mg_stop(ctx);
  }
}

}
