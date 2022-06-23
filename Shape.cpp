#include "Shape.hpp"
#include "graphics.h"


Shape::Shape():m_x(0), m_y(0) {}
Shape::Shape(int x, int y) : m_x(x), m_y(y){}

int Shape::randomGenerator(int offset, int max)
{
  int pos = rand() % (max - offset);
  if (pos <= offset)
    return pos + offset;
  return pos;
}