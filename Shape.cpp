#include <graphics.h>
#include <cmath>
#include "Shape.hpp"
#include "Circle.hpp"
#include "Square.hpp"
#include "GameManager.hpp"

// Parent Shape
Shape::Shape()
	: m_x(0), m_y(0), m_dx (0), m_dy(0) {}
Shape::Shape(int x, int y)
	: m_x(x), m_y(y) {}
Shape::Shape(int x, int y, int dx, int dy)
	: m_x(x), m_y(y), m_dx (dx), m_dy (dy) {}

int Shape::randomGenerator(int offset, int max)
{
	int pos = rand() % (max - offset);
	if (pos <= offset)
		return pos + offset;
	return pos;
}


void Shape::undraw() const{};
void Shape::draw() const{};
void Shape::setLocation(){};




