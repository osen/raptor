#include "Container.h"
#include "Form.h"
#include "mongoosemm.h"
#include "Session.h"

#include <memory>
#include <vector>

namespace raptor
{

class ApplicationStartInfo
{
public:
  virtual std::shared_ptr<Form> createForm() = 0;

};

template <typename T>
class TApplicationStartInfo : public ApplicationStartInfo
{
private:
  std::shared_ptr<Form> createForm()
  {
    std::shared_ptr<Form> rtn = std::make_shared<T>();
    std::shared_ptr<Component> base = rtn;
    base->onCreate();

    return rtn;
  }

};

class Application
{
public:
  Application(int argc, char* argv[]);

  template <typename T>
  void run()
  {
    startInfo = std::make_shared<TApplicationStartInfo<T> >();

    process();
  }

private:
  static int begin_request_handler(struct mg_connection* conn);

  std::shared_ptr<ApplicationStartInfo> startInfo;
  std::vector<std::shared_ptr<Session> > sessions;

  void process();

};

}
