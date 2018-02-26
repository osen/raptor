#include "TextBox.h"

namespace raptor
{

std::string TextBox::serialize()
{
  std::string type;

  if(password)
  {
    type = "password";
  }
  else
  {
    type = "text";
  }

  return "<input type='" + type + "' style='"+generateStyle()+"' value='" + text + "' />";
}


void TextBox::setPassword(bool password)
{
  this->password = password;
}

bool TextBox::getPassword()
{
  return password;
}

}
