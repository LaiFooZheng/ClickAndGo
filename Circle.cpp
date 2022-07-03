#include "Shape.hpp"
#include "Circle.hpp"
#include "Square.hpp"
#include "graphics.h"

#include <cmath>

Circle::Circle() 
	: m_r(100) {}
Circle::Circle(int x, int y, int r) 
	: Shape(x, y),  m_r(r) {}	
Circle::Circle(int x, int y, int r, int dx, int dy)
	: Shape(x, y, dx, dy),  m_r(r) {}
Circle::Circle(Shape* shapes):m_r(100)
{
	this ->	m_shapes = shapes ;
}


void Circle::setRadius(int r) {m_r = r;}

// Getter
int Circle::getX() {return m_x;}
int Circle::getY() {return m_y;}
int Circle::getR() {return m_r;}

void Circle::drawCircle(int color) const
{
	setcolor(color);
	circle(m_x, m_y, m_r);
}

// void Circle::undrawCircle() const
// {
// 	setcolor(BLACK);
// 	circle(m_x, m_y, m_r);
// }

int Circle::distance(const Circle &circle)
{
  	return sqrt(pow(circle.m_x - m_x, 2) + pow(circle.m_y - m_y, 2));
}

int Circle::operator-(const Circle &circle)
{
  	return distance(circle);
}

void Circle::setLocationCircle(int width, int height)
{
	int offset = height / 6;

    m_x = randomGenerator(m_r,width);
    m_y = randomGenerator(m_r,height) + offset; 
}

void Circle::undraw() const
{
	setcolor(BLACK);
	circle(m_x, m_y, m_r);
}

int displacement(const Circle &c1, const Circle &c2){
	Circle c = c1;
	return c - c2;
}
