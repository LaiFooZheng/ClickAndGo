#pragma once

class Circle : public Shape
{
private:
    int m_r;
		Shape* m_shapes ;

public:
	Circle();
	Circle(int x, int y, int r);
	Circle(int x, int y, int r, int dx, int dy);
	Circle(Shape* ) ;
	
	void setRadius(int r);
	int getX();
	int getY();
	int getR();

	void drawCircle(int color) const;
	// void undrawCircle() const;
	
	int distance(const Circle &circle);
	int operator-(const Circle &circle);
	void setLocationCircle(int x, int y);
	friend void displayText(const Circle &circles, char *text) ;

	void undraw() const;
};

int displacement(const Circle &c1, const Circle &c2);