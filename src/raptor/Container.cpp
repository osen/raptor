#include "Container.h"

#include <sstream>

namespace raptor
{

Container::Container()
{
  //setExpand(true);
}

void Container::setDirection(int direction)
{
  this->direction = direction;
}

std::string Container::serialize()
{
  std::stringstream ss;

  ss << "<table style='border-collapse: collapse; width: 100%; height: 100%; " << generateStyle() << "'>";

  if(direction == 0)
  {
    ss << "<tr>";
  }

  bool createExpander = true;

  for(size_t i = 0; i < children.size(); i++)
  {
    Component& c = *children.at(i);

    if(direction == 1)
    {
/*
      if(!c.getExpand())
      {
        ss << "<tr style='height: 1px'>";
      }
      else
      {
*/
        ss << "<tr>";
/*
      }
*/
    }

    ss << "<td style='text-align: center";

/*
    if(direction == 0)
    {
      ss << "; height: 100%";
    }
    else
    {
      ss << "; width: 100%";
    }
*/

    if(!c.getExpand())
    {
      if(direction == 0)
      {
        ss << "; width: 1px";
      }
      else
      {
        ss << "; height: 1px";
      }
    }
    else
    {
      createExpander = false;
    }

    c.getPadding(leftPadding, rightPadding, topPadding, bottomPadding);

    ss << ";padding-left: " << leftPadding << "px";
    ss << ";padding-right: " << rightPadding << "px";
    ss << ";padding-top: " << topPadding << "px";
    ss << ";padding-bottom: " << bottomPadding << "px";

    ss << "'>";
    ss << c.serialize();
    ss << "</td>";

    if(direction == 1)
    {
      ss << "</tr>";
    }
  }

  if(createExpander && getExpand())
  {
    if(direction == 0)
    {
      ss << "<td></td>";
    }
    else
    {
      ss << "<tr><td></td></tr>";
    }
  }

  if(direction == 0)
  {
    ss << "</tr>";
  }

  ss << "</table>";

  return ss.str();
}

}
