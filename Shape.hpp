#pragma once

class Shape
{
protected:
	int m_x , m_y;
	int m_dx = 0, m_dy = 0;

	// Circle* m_circles ;
	// Square* m_Squares ;

public:
	Shape();
	Shape(int x, int y);
	Shape(int x, int y, int dx, int dy);
	// Shape(Circle*) ;
	// Shape(Square*) ;
	int randomGenerator(int offset, int max);

	virtual void undraw() const;

};


