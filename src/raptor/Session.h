#include <memory>
#include <string>

namespace raptor
{

class Form;

class Session
{
public:
  void lock();
  void unlock();
  void setForm(std::shared_ptr<Form> form);
  std::shared_ptr<Form> getForm();
  std::string getId();

private:
  // Unique unique;
  std::shared_ptr<Form> form;
};

}
