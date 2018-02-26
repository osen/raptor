#ifndef RAPTOR_FORM_H
#define RAPTOR_FORM_H

#include "Container.h"

#include <string>

namespace raptor
{

class Form : public Container
{
public:
  Form();

  void setTitle(std::string title);
  std::string getTitle();

private:
  std::string serialize();
  std::string title;

};

}

#endif
