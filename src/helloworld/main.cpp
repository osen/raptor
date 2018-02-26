#include "HelloForm.h"

int main(int argc, char* argv[])
{
  raptor::Application app(argc, argv);

  app.run<HelloForm>();

  return 0;
}
