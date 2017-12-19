#ifndef INCLUDED_VECTOR2_H
#define INCLUDED_VECTOR2_H

class Vector2 {

public:
	Vector2();
	Vector2(int aX, int aY);
	Vector2(double aX, double aY);

	void operator+=(const Vector2 &a);
	void operator-=(const Vector2 &a);
	void operator=(const Vector2 &a);
	void operator*=(double &a);
	double x;
	double y;
};

#endif