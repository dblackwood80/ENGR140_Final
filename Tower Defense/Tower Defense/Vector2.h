#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>
#include <deque>
#include "Matrix.h"

class Vector2
{
public:
	float X, Y;

public:
	Vector2();
	Vector2(float X, float Y);
	~Vector2();
	float Distance(Vector2 value1, Vector2 value2);
	Vector2 *zeroVector();
	Vector2 operator *(double scaleFactor);

	bool operator!=(Vector2 value1);

	void Normalize();

	Vector2 Transform(Vector2 position, Matrix matrix);

	Vector2 Subtract(Vector2 value1, Vector2 value2);

	Vector2(double value);

	void Transform(Vector2 position, Matrix matrix, Vector2 result);

	Vector2 operator-(Vector2 value);

	Vector2 Multiply(Vector2 value1, double scaleFactor);

	Vector2 operator+=(Vector2 value1);

	bool operator==(Vector2 value1);

	float convertX(float x);
	float convertY(float y);
};

#endif // !VECTOR2_H
