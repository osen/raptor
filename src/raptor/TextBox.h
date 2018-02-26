#include "TextComponent.h"
#include "zero_initialized.h"

#include <string>

namespace raptor
{

class TextBox : public TextComponent
{
private:
  zero_initialized<bool> password;

protected:
  std::string serialize();

public:
  void setPassword(bool password);
  bool getPassword();

};

}
