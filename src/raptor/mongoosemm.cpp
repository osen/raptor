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

std::shared_ptr<PostData> PostData::mg_read(mg_connection* conn, size_t maxLen)
{
  std::shared_ptr<PostData> rtn = std::make_shared<PostData>();

  rtn->data.resize(maxLen);

  size_t length = ::mg_read(conn, &rtn->data.at(0),
    rtn->data.size() * sizeof(char));

  if(length <= 0) return rtn;

  rtn->data.resize(length / size(char));

  return rtn;
}

std::string PostData::getVar(std::string name)
{
  return "";
}

}
