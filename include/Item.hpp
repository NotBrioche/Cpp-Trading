#ifndef ITEM
#define ITEM

#include <string>

class Item {
protected:
  std::string name;
  int price;

public:
  Item(std::string name, int price);

  std::string getName();
  int getPrice();
};

#endif