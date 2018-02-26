#include "Form.h"

#include <sstream>

namespace raptor
{

Form::Form()
{
  setExpand(true);
}

void Form::setTitle(std::string title)
{
  this->title = title;
}

std::string Form::getTitle()
{
  return title;
}

std::string Form::serialize()
{
  std::stringstream ss;

  ss << "<form>";
  ss << "<table style='border-collapse: collapse; position: absolute; left: 0px; top: 0px; width: 100%; height: 100%'>";
  ss << "<tr>";

  int leftPadding = 0;
  int rightPadding = 0;
  int topPadding = 0;
  int bottomPadding = 0;
  getPadding(leftPadding, rightPadding, topPadding, bottomPadding);

  //if(!getExpand()) ss << "<td></td>";
  ss << "<td style='";

  if(leftPadding) ss << "padding-left: " << leftPadding << "px";
  if(rightPadding) ss << ";padding-right: " << rightPadding << "px";
  if(topPadding) ss << ";padding-top: " << topPadding << "px";
  if(bottomPadding) ss << ";padding-bottom: " << bottomPadding << "px";
  if(!getExpand()) ss << ";width: 1px";

  ss << "'>";

  ss << Container::serialize();

  ss << "</td>";
  if(!getExpand()) ss << "<td></td>";
  ss << "</tr>";
  ss << "</table>";
  ss << "</form>";

  return ss.str();
}

}
