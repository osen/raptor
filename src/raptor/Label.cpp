#include "Label.h"

namespace raptor
{

std::string Label::serialize()
{
  return "<label style='white-space: nowrap; "+generateStyle()+"'>" + text + "</label>";
}

}
