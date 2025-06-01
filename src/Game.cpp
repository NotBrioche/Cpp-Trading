#include "Game.hpp"
#include <iostream>

Game::Game() {
  this->player = Player("NotBrioche");
  this->day = 0;
}

Player Game::getPlayer() { return player; }
int Game::getDay() { return day; }

void Game::addDays(int days) { this->day += days; }

void Game::showDefaultPage() {
  std::cout << "Day " << this->day << std::endl;
  std::cout << player.getName() << std::endl;
}