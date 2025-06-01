#include "Merchant.hpp"
#include <algorithm>

Merchant::Merchant(MerchantType type) { this->type = type; }

std::vector<Item> Merchant::getItems() { return items; }
MerchantType Merchant::getType() { return type; }

void Merchant::addItem(Item item) { items.push_back(item); }
void Merchant::removeItem(Item item) {
  items.erase(std::find(items.begin(), items.end(), item));
}