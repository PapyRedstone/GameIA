#ifndef STATE_HPP
#define STATE_HPP

#include <memory>
#include <iostream>

class Miner;

template<class entType>
class State {
 private:
 public:
  virtual void execute(entType&) = 0;
  virtual void enter(entType&) = 0;
  virtual void exit(entType&) = 0;
};

class DigGold: public State<Miner>{
  virtual void execute(Miner& entity);
  virtual void enter(Miner& entity);
  virtual void exit(Miner& entity);
};

class VisitBank: public State<Miner>{
  virtual void execute(Miner& entity);
  virtual void enter(Miner& entity);
  virtual void exit(Miner& entity);
};

class GoHome: public State<Miner>{
  virtual void execute(Miner& entity);
  virtual void enter(Miner& entity);
  virtual void exit(Miner& entity);
};

class TakeShoot: public State<Miner>{
  virtual void execute(Miner& entity);
  virtual void enter(Miner& entity);
  virtual void exit(Miner& entity);
};

#endif
