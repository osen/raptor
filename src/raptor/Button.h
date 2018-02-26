#include "TextComponent.h"

#include <string>

namespace raptor
{

class Button : public TextComponent
{
protected:
  std::string serialize();

};

}
