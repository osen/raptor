#include "TextComponent.h"

#include <string>

namespace raptor
{

class Label : public TextComponent
{
protected:
  std::string serialize();

};

}
