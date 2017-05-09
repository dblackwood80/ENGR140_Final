#include "Vector2.h"

Vector2::Vector2()
{
}

Vector2::Vector2(float X, float Y)
{
	this->X = X;
	this->Y = Y;
}

Vector2::~Vector2()
{
}

float Vector2::Distance(Vector2 value1, Vector2 value2)
{
	float v1 = value1.X - value2.X, v2 = value1.Y - value2.Y;
	return (float)sqrt((v1 * v1) + (v2 * v2));
}

Vector2 *Vector2::zeroVector()
{
	return new Vector2(0.0f, 0.0f);
}

Vector2 Vector2::operator*(double scaleFactor)
{
	return Vector2(X * scaleFactor, Y * scaleFactor);
}

bool Vector2::operator!=(Vector2 value1)
{
	return (X != value1.X) || (Y != value1.Y);
}

void Vector2::Normalize()
{
	double val = 1.0f / (double)sqrt((X * X) + (Y * Y));
	X *= val;
	Y *= val;
}

Vector2 Vector2::Transform(Vector2 position, Matrix matrix)
{
	//Transform( position, matrix, position);



	return Vector2((position.X * matrix.M11) + (position.Y * matrix.M21) + matrix.M41,
		(position.X * matrix.M12) + (position.Y * matrix.M22) + matrix.M42);
}

Vector2 Vector2::Subtract(Vector2 value1, Vector2 value2)
{
	value1.X -= value2.X;
	value1.Y -= value2.Y;
	return value1;
}

Vector2::Vector2(double value)
{
	this->X = value;
	this->Y = value;
}

void Vector2::Transform(Vector2 position, Matrix matrix, Vector2 result)
{
	result = Vector2((position.X * matrix.M11) + (position.Y * matrix.M21) + matrix.M41,
		(position.X * matrix.M12) + (position.Y * matrix.M22) + matrix.M42);
}


Vector2 Vector2::operator -(Vector2 value)// not right look ate enemy.cpp updates
{
	value.X = -value.X;
	value.Y = -value.Y;
	return value;
}

Vector2 Vector2::operator +(float value)
{
	X += value;
	Y += value;
	return Vector2(X, Y);
}

Vector2 Vector2::operator +(Vector2 value)
{
	value.X += X;
	value.Y += Y;
	return value;
}

Vector2 Vector2::Multiply(Vector2 value1, double scaleFactor)
{
	value1.X *= scaleFactor;
	value1.Y *= scaleFactor;
	return value1;
}

Vector2 Vector2::operator +=(Vector2 value1) //doesnt work
{
	X = X + value1.X;
	Y = Y + value1.Y;

	return Vector2(X, Y);
}

bool Vector2::operator ==(Vector2 value1)
{
	return (X == value1.X) || (Y == value1.Y);
}

float Vector2::convertX(float x)
{
	// Converting window coordinates [0..width] x [0..height] to [-1..1] x [-1..1]
	x = (2.0f*(x / float(768))) - 1.0f;

	return x;
}

float Vector2::convertY(float y)
{
	y = 1.0f - (2.0f*(y / float(768)));
	// Take care of issue in Windows where y coordinate is a little off
#if defined WIN32
	y -= 0.03f;
#endif

	return y;
}
