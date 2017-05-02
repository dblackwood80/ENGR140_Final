#include "Matrix.h"

Matrix::Matrix(double m11, double m12, double m13, double m14, double m21, double m22, double m23, double m24, double m31,
	double m32, double m33, double m34, double m41, double m42, double m43, double m44)
{
	this->M11 = m11;
	this->M12 = m12;
	this->M13 = m13;
	this->M14 = m14;
	this->M21 = m21;
	this->M22 = m22;
	this->M23 = m23;
	this->M24 = m24;
	this->M31 = m31;
	this->M32 = m32;
	this->M33 = m33;
	this->M34 = m34;
	this->M41 = m41;
	this->M42 = m42;
	this->M43 = m43;
	this->M44 = m44;
}

Matrix::Matrix()
{

}

Matrix::~Matrix()
{
}

Matrix Matrix::Identity()
{
	return Matrix(1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1);
}

Matrix Matrix::CreateRotationZ(double radians)
{
	Matrix returnMatrix = Matrix().Identity();

	double val1 = (double)cos(radians);
	double val2 = (double)sin(radians);

	returnMatrix.M11 = val1;
	returnMatrix.M12 = val2;
	returnMatrix.M21 = -val2;
	returnMatrix.M22 = val1;

	return returnMatrix;
}
