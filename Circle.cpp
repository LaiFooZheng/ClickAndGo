#include "Circle.hpp"
#include <graphics.h>
#include <cmath>
using namespace std;

Circle::Circle() : m_r(0),  m_dx (0), m_dy(0){}
Circle::Circle(int x, int y, int r, int dx, int dy) : Shape(x , y), m_r(r),  m_dx (dx), m_dy (dy){}
Circle::Circle(int x, int y, int r) : Shape(x , y),  m_r(r) {}



void Circle::setRadius(int r)
{
	m_r = r;
}

void Circle::draw(int color) const
{
	setcolor(color);
	circle(m_x, m_y, m_r);
}

void Circle::undraw() const
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

void Circle::setLocation(int width, int height)
{   
    m_x = randomGenerator(m_r,width);
    m_y = randomGenerator(m_r,height); 
}

