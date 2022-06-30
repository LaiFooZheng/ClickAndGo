#pragma once

class Square : public Shape
{
private:
	int m_side;
public: 
	Square();
	Square(int side);

	void setSide(int side); 
	void drawSquare() const;
	// void undrawSquare()  const ;
	void setLocationSquare(Circle &, int, int);

	void undraw() const ;
};