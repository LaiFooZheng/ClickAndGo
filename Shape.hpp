#pragma once

class Shape
{
protected:
	int m_x , m_y;
	int m_dx = 0, m_dy = 0;

public:
	Shape();
	Shape(int x, int y);
	Shape(int x, int y, int dx, int dy);
	int randomGenerator(int offset, int max);

	virtual void undraw() const;
	virtual void draw() const;
	virtual void setLocation() ;
};


