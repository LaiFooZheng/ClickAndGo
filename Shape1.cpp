#include <graphics.h>
#include <cmath>
#include "Shape1.hpp"
#include <iostream>

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
	: Shape(), m_r(100) {}
Circle::Circle(int x, int y, int r) 
	: Shape(x, y),  m_r(r) {}	
Circle::Circle(int x, int y, int r, int dx, int dy)
	: Shape(x, y, dx, dy),  m_r(r) {}

void Circle::setRadius(int r)
{
	m_r = r;
}
//getter
int Circle::getX(){return m_x ;}
int Circle::getY(){return m_y ;}
int Circle::getR(){return m_r ;}

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

void drawing(Circle &circles, Square &squares, int width , int playheight, int color, char* text)
{
	circles.undrawCircle();
	squares.undrawSquare() ;
	displayText(circles, text);

	circles.setLocationCircle(width, playheight);
	squares.setLocationSquare(circles, width, playheight);

	circles.drawCircle(color);
	squares.drawSquare();
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

//Square Shape

Square::Square()
	: Shape(), side(0) {}
Square::Square(int side_)
	: Shape(), side(side_){}

void Square::set_Side(int side_) {side = side_ ;}
void Square::drawSquare() const
{		
		// int x = m_x ;
		// int y = m_y ;
		// int s = side ;
		std::cout << "draw triangle"  ;
		// setcolor(WHITE) ;
		rectangle(m_x - side, m_y - side, m_x + side, m_y + side) ;
}
void Square::setLocationSquare(Circle &circles, int width, int height)
{   
	int offset = height/ 8;

    m_x = randomGenerator(side * 2,width);
    m_y = randomGenerator(side * 2,height) + offset; 

		if(abs(circles.getX() - m_x) <= circles.getR()){
			m_x += circles.getR() ;
		}
		if(abs(circles.getY() - m_y) <= circles.getR()){
			m_y += circles.getR() ;
		}
			
}

void Square::undrawSquare() const
{
	// setcolor(BLACK);
	rectangle(m_x - side, m_y - side, m_x + side, m_y + side) ;
}