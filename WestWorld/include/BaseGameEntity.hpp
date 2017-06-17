#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Define.hpp"
#include "State.hpp"

class BaseGameEntity {
 private:
  int mID;

 public:
  BaseGameEntity(int id);
  virtual ~BaseGameEntity();
  virtual void update() = 0;
  int id() { return mID; };
};

#endif
