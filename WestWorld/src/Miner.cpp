#include "Miner.hpp"

Miner::Miner(int id, State<Miner>& initState)
    : BaseGameEntity(id),
      mLocation{Location::GoldMine},
      mGoldCarried{0},
      mGoldInBank{0},
      mThirst{0},
      mFatigue{0},
      mState{initState} {
  mState.enter(*this);
}

Miner::~Miner() {}

void Miner::changeState(State<Miner>& newState) {
  mState.exit(*this);
  mState = newState;
  mState.enter(*this);
}

void Miner::update() {
  mThirst++;
  mFatigue++;
  mState.execute(*this);
  switch(mLocation){
    case Location::GoldMine:
      std::cout<<"goldMine\n";
      break;
    case Location::Bar:
      std::cout<<"bar\n";
      break;
    case Location::Bank:
      std::cout<<"bank\n";
      break;
    case Location::Home:
      std::cout<<"home\n";
      break;
  }
}
