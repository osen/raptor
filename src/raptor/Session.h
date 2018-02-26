#include <memory>

namespace raptor
{

class Form;

class Session
{
public:
  void lock();
  void unlock();
  void setForm(std::shared_ptr<Form> form);

private:
  // Unique unique;
  std::shared_ptr<Form> form;
};

}
