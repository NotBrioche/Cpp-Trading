#ifndef DISPLAY
#define DISPLAY

#include <initializer_list>
#include <string>

enum DisplayAlign {
  LEFT,
  CENTER,
  RIGHT,
  BETWEEN,
};

enum DisplayType { FILL };

class Display {
  int displayWidth = 60;

public:
  Display();

  void print(std::initializer_list<std::string> texts,
             DisplayAlign align = LEFT);

  void print(std::initializer_list<std::string> texts, DisplayType type);
};

#endif