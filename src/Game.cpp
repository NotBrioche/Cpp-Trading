#include "Game.hpp"
#include "Display.hpp"
#include <string>

Game::Game() {
  this->player = Player("NotBrioche");
  this->day = 0;
}

Player Game::getPlayer() { return player; }
int Game::getDay() { return day; }

void Game::addDays(int days) { this->day += days; }

void Game::showDefaultPage() {
  auto d = Display();

  d.print({"Day " + std::to_string(this->day)}, CENTER);
  d.print({"-"}, FILL);
  d.print({this->player.getName(), "BOB"}, BETWEEN);
  d.print({std::to_string(this->player.getGold()) + " gold"});
  d.print({});
  d.print({"Inventory"});
  d.print({});
  d.print({"Propose trade"});
  d.print({"Walk by"});
}