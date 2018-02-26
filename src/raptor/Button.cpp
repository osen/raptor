#include "Button.h"

namespace raptor
{

std::string Button::serialize()
{
  return "<input type='submit' style='"+generateStyle()+"' value='" + text + "' />";
}

}
