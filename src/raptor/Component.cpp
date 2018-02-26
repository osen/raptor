#include "Component.h"

#include <sstream>

namespace raptor
{

void Component::onCreate() { }


void Component::setExpand(bool expand)
{
  this->expand = expand;
}

bool Component::getExpand()
{
  return expand;
}

std::string Component::generateStyle()
{
  std::stringstream ss;

  if(borderWidth > 0) ss << "border: " << borderWidth << "px solid;";
  //if(leftPadding > 0) ss << "padding-left: " << leftPadding << "px;";
  //if(rightPadding > 0) ss << "padding-right: " << rightPadding << "px;";
  //if(topPadding > 0) ss << "padding-top: " << topPadding << "px;";
  //if(bottomPadding > 0) ss << "padding-bottom: " << bottomPadding << "px;";
  //ss << "width: 100%; height: 100%";
  if(width > 0) ss << "width: " << width << "px;";

  return ss.str();
}

void Component::setPadding(int left, int right, int top, int bottom)
{
  leftPadding = left;
  rightPadding = right;
  topPadding = top;
  bottomPadding = bottom;
}

void Component::setPadding(int padding)
{
  leftPadding = padding;
  rightPadding = padding;
  topPadding = padding;
  bottomPadding = padding;
}

void Component::getPadding(int& left, int& right, int& top, int& bottom)
{
  left = leftPadding;
  right = rightPadding;
  top = topPadding;
  bottom = bottomPadding;
}

void Component::setBorderWidth(int width)
{
  this->borderWidth = width;
}

void Component::setWidth(int width)
{
  this->width = width;
}

}
