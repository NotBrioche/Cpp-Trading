#ifndef PLAYER
#define PLAYER

#include "Item.hpp"
#include <string>
#include <vector>

class Player {
protected:
  std::string name;
  int gold;
  std::vector<Item> items;

public:
  Player(std::string name);

  std::string getName();
  int getGold();
  std::vector<Item> getItems();

  void addGold(int gold);

  void addItem(Item item);
  void removeItem(Item item);
};

#endif