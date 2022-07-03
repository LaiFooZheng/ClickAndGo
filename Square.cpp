#include "Shape.hpp"
#include "Circle.hpp"
#include "Square.hpp"
#include "graphics.h"


Square::Square()
	: Shape(), m_side(0) {}
Square::Square(int side)
	: Shape(), m_side(side) {}
Square::Square(Shape* shapes):m_side(100){
	this ->	m_shapes = shapes ;
}

void Square::setSide(int side) {m_side = side;}

void Square::drawSquare() const
{		
	rectangle(m_x - m_side, m_y - m_side, m_x + m_side, m_y + m_side);
}

void Square::setLocationSquare(Circle &circles, int width, int height)
{   
	int offset = height / 6;

    m_x = randomGenerator(m_side * 2, width);
    m_y = randomGenerator(m_side * 2, height) + offset; 

		if(abs((circles.getX() + m_side) - m_x) <= circles.getR())
		{
			m_x += circles.getR();
		}
		if(abs((circles.getY() + m_side) - m_y) <= circles.getR())
		{
			m_y += circles.getR();
		}		
}

// void Square::undrawSquare() const
// {
// 	rectangle(m_x - m_side, m_y - m_side, m_x + m_side, m_y + m_side);
// }

void Square::undraw() const
{
	rectangle(m_x - m_side, m_y - m_side, m_x + m_side, m_y + m_side);
}