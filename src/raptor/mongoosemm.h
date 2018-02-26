#ifndef MONGOOSEMM_MONGOOSEMM_H
#define MONGOOSEMM_MONGOOSEMM_H

#include "noncopyable.h"
#include "mongoose.h"

#include <memory>

namespace mongoose
{

class Context
{
public:
  static std::shared_ptr<Context> mg_start(mg_callbacks& callbacks, void* userData, const char** options);
  ~Context();

private:
  noncopyable<mg_context*> ctx;
};

}

#endif
