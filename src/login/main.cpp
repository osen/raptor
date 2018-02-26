#include "LoginForm.h"

int main(int argc, char* argv[])
{
  raptor::Application app(argc, argv);

  app.run<LoginForm>();

  return 0;
}
