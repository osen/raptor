#include "TextBox.h"

namespace raptor
{

TextBox::TextBox()
{

}

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

  std::string widthStyle;

  if(width == 0)
  {
    widthStyle = ";width: 10em";
  }

  return "<input name='fred' type='" + type + "' style='"+generateStyle()+widthStyle+"' value='" + text + "' />";
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
