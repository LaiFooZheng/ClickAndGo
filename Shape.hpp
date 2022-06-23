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
};

class Circle : public Shape
{
private:
    int m_r;

public:
	Circle();
	Circle(int x, int y, int r);
	Circle(int x, int y, int r, int dx, int dy);
	
	void setRadius(int r);
	void drawCircle(int color) const;
	void undrawCircle() const;
	
	int distance(const Circle &circle);
	int operator-(const Circle &circle);
	void setLocationCircle(int x, int y);
};