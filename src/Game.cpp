#include "Game.hpp"
#include "Display.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>

Game::Game() {
  this->player = Player("NotBrioche");
  this->day = 0;
}

Player Game::getPlayer() { return player; }
int Game::getDay() { return day; }

void Game::addDays(int days) { this->day += days; }

void Game::showDefaultPage() {
  auto d = Display();
  system("clear");

  d.print({"Day " + std::to_string(this->day)}, CENTER);
  d.print({"-"}, FILL);
  d.print({this->player.getName(), "Weapon merchant"}, BETWEEN);
  d.print({std::to_string(this->player.getGold()) + " gold", "BOB"}, BETWEEN);
  d.print({});
  d.print({"i) Inventory"});
  d.print({});
  d.print({"t) Propose trade"});
  d.print({"w) Walk by"});
  d.print({});

  std::string input;

  std::cout << "Choice : ";
  std::getline(std::cin, input);

  switch (input[0]) {
  case 'i':
    showPlayerInventoryPage();
    break;
  case 't':
    std::cout << "Trade" << std::endl;
    break;
  case 'w':
    showWalkingPage(3);
    break;
  }
}

void Game::showPlayerInventoryPage() {
  auto d = Display();
  system("clear");

  d.print({player.getName()});
  d.print({"-"}, FILL);

  if (player.getItems().size() < 1) {
    d.print({"No items in your inventory"});
  } else {
    for (auto item : player.getItems()) {
      d.print({item.getName(), std::to_string(item.getPrice())}, BETWEEN);
    }
  }

  d.print({});
  d.print({"Press enter to continue"});

  std::string input;
  std::getline(std::cin, input);

  showDefaultPage();
}

void Game::showWalkingPage(int seconds) {
  system("clear");

  // Chat GPT
  const std::string baseText = "Walking";

  for (int i = 0; i <= seconds; ++i) {
    std::cout << "\r" << baseText;
    for (int j = 0; j < i; ++j) {
      std::cout << ".";
    }
    std::cout << "    ";
    std::cout.flush();

    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  showDefaultPage();
}