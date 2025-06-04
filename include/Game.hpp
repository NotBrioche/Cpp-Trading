#ifndef GAME
#define GAME

#include "Player.hpp"

class Game {
protected:
  Player player;
  int day;

public:
  Game();

  Player getPlayer();
  int getDay();

  void addDays(int days);

  void showDefaultPage();
  void showPlayerInventoryPage();
  void showWalkingPage(int seconds);
};

#endif