#ifndef RAPTOR_TEXTCOMPONENT_H
#define RAPTOR_TEXTCOMPONENT_H

#include "Component.h"

#include <string>

namespace raptor
{

class TextComponent : public Component
{
protected:
  std::string text;

public:
  void setText(std::string text);

};

}

#endif
