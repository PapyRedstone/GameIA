#ifndef MINER_HPP
#define MINER_HPP

#include <cassert>
#include <memory>
#include "BaseGameEntity.hpp"

class Miner : public BaseGameEntity {
 private:
  Location mLocation;
  int mGoldCarried;
  int mGoldInBank;
  int mThirst;
  int mFatigue;
  State<Miner>& mState;

 public:
  Miner(int id, State<Miner>& initState);
  virtual ~Miner();
  virtual void update();
  virtual void changeState(State<Miner>& newState);

  void addGold() { mGoldCarried++; }
  int getGoldCarried() const { return mGoldCarried; }
  void putGoldInBank() {
    mGoldInBank += mGoldCarried;
    mGoldCarried = 0;
  }
  int getGoldInBank() { return mGoldInBank; }
  Location getLocation() { return mLocation; }
  void setLocation(Location newLoc) { mLocation = newLoc; }
  int getFatigue() { return mFatigue; }
  void decreaseFatigue() { mFatigue -= 2; }
  int getThirst() { return mThirst; }
  void removeThirst() {
    mThirst = 0;
    mGoldInBank -= 2;
  }
};

#endif
