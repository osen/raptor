#include <raptor/raptor.h>

class LoginForm : public raptor::Form
{
  void onCreate();

  void createWindow();
  void createLogin(raptor::Container* container);
};
