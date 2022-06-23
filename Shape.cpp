#include <graphics.h>
#include <cmath>
#include "Shape.hpp"

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

// Circle Shape
Circle::Circle() 
	: m_r(100) {}
Circle::Circle(int x, int y, int r) 
	: Shape(x, y),  m_r(r) {}	
Circle::Circle(int x, int y, int r, int dx, int dy)
	: Shape(x, y, dx, dy),  m_r(r) {}

void Circle::setRadius(int r)
{
	m_r = r;
}

void Circle::drawCircle(int color) const
{
	setcolor(color);
	circle(m_x, m_y, m_r);
}

void Circle::undrawCircle() const
{
	setcolor(BLACK);
	circle(m_x, m_y, m_r);
}

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
	int offset = height/ 8;

    m_x = randomGenerator(m_r,width);
    m_y = randomGenerator(m_r,height) + offset; 
}

int displacement(const Circle &c1, const Circle &c2){
	Circle c = c1;
	return c - c2;
}

void Drawing(Circle &circles, int width , int playheight, int color)
{
	circles.undrawCircle();
	circles.setLocationCircle(width, playheight);
	circles.drawCircle(color);
}

// Triangle Shape
void Triangle::drawTriangle() const
{
	line(m_x - 150, m_y, m_x + 150, m_y);
	line(m_x - 150, m_y, m_x , m_y + 150);
	line(m_x + 150, m_y, m_x , m_y + 150);

}

void Triangle::setLocationTriangle(int width, int height)
{   
    m_x = randomGenerator(100,width);
    m_y = randomGenerator(100,height); 
}

