#pragma once

class Square : public Shape
{
private:
	int m_side;
	Shape* m_shapes ;
public: 
	Square();
	Square(int side);
	Square(Shape* ) ;

	void setSide(int side); 
	void drawSquare() const;
	// void undrawSquare()  const ;
	void setLocationSquare(Circle &, int, int);

	void undraw() const ;
};