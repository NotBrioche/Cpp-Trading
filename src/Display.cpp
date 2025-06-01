#include "Display.hpp"
#include <iostream>
#include <vector>

Display::Display() {}

void Display::print(std::initializer_list<std::string> texts,
                    DisplayAlign align) {
  switch (align) {
  case LEFT:
    break;
  case CENTER: {
    int spaceLeft = this->displayWidth;

    for (auto &text : texts) {
      spaceLeft -= text.length();
    }

    std::cout << std::string(spaceLeft / 2, ' ');
    break;
  }
  case RIGHT: {
    int spaceLeft = this->displayWidth;

    for (auto &text : texts) {
      spaceLeft -= text.length();
    }

    std::cout << std::string(spaceLeft, ' ');
    break;
  }
  case BETWEEN: {
    int spaceLeft = this->displayWidth;

    for (auto &text : texts) {
      spaceLeft -= text.length();
    }
    try {
      int numberSpaces = texts.size() - 1;
      if (numberSpaces < 1) {
        throw -1;
      }
      spaceLeft /= numberSpaces;
    } catch (int e) {
      spaceLeft = 0;
    }

    for (auto &text : texts) {
      std::cout << text << std::string(spaceLeft, ' ');
    }
    std::cout << std::endl;

    return;
  }
  }

  for (auto &text : texts) {
    std::cout << text << " ";
  }
  std::cout << std::endl;
  return;
}

void Display::print(std::initializer_list<std::string> texts,
                    DisplayType type) {
  switch (type) {
  case FILL: {
    std::vector<std::string> list = texts;

    for (auto i = 0; i < this->displayWidth; i++) {
      std::cout << list[i % list.size()];
    }
    std::cout << std::endl;
    break;
  }
  }
}