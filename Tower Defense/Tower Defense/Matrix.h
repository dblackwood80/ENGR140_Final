#ifndef MATRIX_H
#define MATRIX_H

#include <cmath>

class Matrix
{
public:
	 double M11;
	 double M12;
	 double M13;
	 double M14;
	 double M21;
	 double M22;
	 double M23;
	 double M24;
	 double M31;
	 double M32;
	 double M33;
	 double M34;
	 double M41;
	 double M42;
	 double M43;
	 double M44;



public:
	Matrix(double m11, double m12, double m13, double m14, double m21, double m22, double m23, double m24, double m31,
		double m32, double m33, double m34, double m41, double m42, double m43, double m44);
	Matrix();
	~Matrix();

	Matrix Identity();

	Matrix CreateRotationZ(double radians);


};

#endif // !MATRIX_H
