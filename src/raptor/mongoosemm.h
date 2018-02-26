#ifndef MONGOOSEMM_MONGOOSEMM_H
#define MONGOOSEMM_MONGOOSEMM_H

#include "noncopyable.h"
#include "mongoose.h"

#include <memory>
#include <string>
#include <vector>

namespace mongoose
{

class PostData
{
public:
  static std::shared_ptr<PostData> mg_read(mg_connection* conn, size_t maxLen);

  std::string getVar(std::string name);

private:
  std::vector<char> data;
};

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
