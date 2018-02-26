#ifndef RAPTOR_CONTAINER_H
#define RAPTOR_CONTAINER_H

#include "Component.h"
#include "zero_initialized.h"

#include <vector>
#include <memory>

namespace raptor
{

class Container : public Component
{
public:
  Container();

  template <typename T>
  T* add()
  {
    std::shared_ptr<T> rtn = std::make_shared<T>();
    children.push_back(rtn);
    std::shared_ptr<Component> base = rtn;

    base->onCreate();

    return rtn.get();
  }

  void setDirection(int direction);

protected:
  std::vector<std::shared_ptr<Component> > children;
  zero_initialized<int> direction;

  virtual std::string serialize();

};

}

#endif
