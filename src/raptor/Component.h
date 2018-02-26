#ifndef RAPTOR_COMPONENT_H
#define RAPTOR_COMPONENT_H

#include "zero_initialized.h"

#include <string>

namespace raptor
{

class Component
{
public:
  virtual std::string serialize() = 0;
  virtual void onCreate();

  void setExpand(bool expand);
  bool getExpand();

  void setBorderWidth(int width);

  void setPadding(int padding);
  void setPadding(int left, int right, int top, int bottom);
  void getPadding(int& left, int& right, int& top, int& bottom);

  void setWidth(int width);

protected:
  zero_initialized<bool> expand;
  zero_initialized<int> borderWidth;
  zero_initialized<int> leftPadding;
  zero_initialized<int> rightPadding;
  zero_initialized<int> topPadding;
  zero_initialized<int> bottomPadding;
  zero_initialized<int> width;

  std::string generateStyle();

};

}

#endif
