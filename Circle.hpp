#include "Shape.hpp"
#ifndef CIRCLE_H
#define CIRCLE_H


class Circle: public Shape
{
private:
    int m_r = 100;
    int m_dx = 0, m_dy = 0;
public:
	Circle();
	Circle(int x, int y, int r, int dx, int dy);
	Circle(int x, int y, int r);

	void setRadius(int r);
	void draw(int) const;
	void undraw() const;
	int distance(const Circle &circle);
	int operator-(const Circle &circle);
	void setLocation(int, int);
 	int randomGenerator(int offset, int max) ;

};



#endif