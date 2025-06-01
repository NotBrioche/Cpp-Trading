#ifndef MERCHANT
#define MERCHANT

#include "Item.hpp"
#include <vector>

enum MerchantType {
  GREEDY,
  FAIR,
  NORMAL,
  BUYER,
  SELLER,
};

class Merchant {
protected:
  std::vector<Item> items;
  MerchantType type;

public:
  Merchant(MerchantType type);

  std::vector<Item> getItems();
  MerchantType getType();

  void addItem(Item item);
  void removeItem(Item item);
};
#endif