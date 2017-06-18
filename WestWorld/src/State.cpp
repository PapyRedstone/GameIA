#include "State.hpp"
#include "Miner.hpp"

void DigGold::execute(Miner& entity) {
  std::cout << entity.id() << " : Picking up a nugget\n";
  entity.addGold();
  if (entity.getGoldCarried() > 4) {
    VisitBank nS;
    entity.changeState(nS);
    return;
  } else if (entity.getThirst() > 5) {
    TakeShoot nS;
    entity.changeState(nS);
    return;
  }
}

void DigGold::enter(Miner& entity) {
  std::cout << entity.id() << " : Going to the gold mine.\n";
  entity.setLocation(Location::GoldMine);
}

void DigGold::exit(Miner& entity) {
  std::cout << entity.id() << " : Enough for now, I'm leaving the mine.\n";
}

void VisitBank::execute(Miner& entity) {
  std::cout << entity.id() << " : Deposit Gold\n";
  entity.getGoldInBank();
  if (entity.getGoldInBank() > 10) {
    GoHome nS;
    entity.changeState(nS);
    return;
  } else {
    DigGold nS;
    entity.changeState(nS);
  }
}

void VisitBank::enter(Miner& entity) {
  std::cout << entity.id() << " : Going to save up gold.\n";
  entity.setLocation(Location::Bank);
}

void VisitBank::exit(Miner& entity) {
  std::cout << entity.id() << " : Leaving the bank.\n";
}

void GoHome::execute(Miner& entity) {
  std::cout << entity.id() << " : ZZZZ\n";
  entity.decreaseFatigue(); 
  if (entity.getFatigue() <= 0) {
    DigGold nS;
    entity.changeState(nS);
    return;
  }
}

void GoHome::enter(Miner& entity) {
  std::cout << entity.id() << " : Home sweet home.\n";
  entity.setLocation(Location::Home);
}

void GoHome::exit(Miner& entity) {
  std::cout << entity.id() << " : Time to get richer.\n";
}

void TakeShoot::execute(Miner& entity) {
  std::cout << entity.id() << " : Taking a drink\n";
  entity.removeThirst();
  if (entity.getThirst() <= 0) {
    DigGold nS;
    entity.changeState(nS);
    return;
  }
}

void TakeShoot::enter(Miner& entity) {
  std::cout << entity.id() << " : Time to have a drink.\n";
  entity.setLocation(Location::Bar);
}

void TakeShoot::exit(Miner& entity) {
  std::cout << entity.id() << " : Enough drink for now.\n";
}
