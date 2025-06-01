#include "Player.hpp"
#include <algorithm>

Player::Player() {}

Player::Player(std::string name) {
  this->name = name;
  this->gold = 0;
  this->items = std::vector<Item>();
}

std::string Player::getName() { return name; }
int Player::getGold() { return gold; }
std::vector<Item> Player::getItems() { return items; }

void Player::addGold(int gold) { this->gold += gold; }

void Player::addItem(Item item) { items.push_back(item); }
void Player::removeItem(Item item) {
  items.erase(std::find(items.begin(), items.end(), item));
}