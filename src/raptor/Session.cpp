#include "Session.h"

namespace raptor
{

std::string Session::getId()
{
  return "";
}


void Session::setForm(std::shared_ptr<Form> form)
{
  this->form = form;
}

std::shared_ptr<Form> Session::getForm()
{
  return form;
}

}
