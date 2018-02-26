#include "HelloForm.h"

void HelloForm::onCreate()
{
  setTitle("Hello World");

  raptor::Button* button = add<raptor::Button>();
  button->setText("Hello World");
  button->setExpand(true);
}
