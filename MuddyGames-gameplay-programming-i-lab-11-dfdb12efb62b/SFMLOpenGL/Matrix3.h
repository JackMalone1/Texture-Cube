#pragma once
#include "Vector3.h"
using namespace gpp;
class Matrix3
{
public:
	Matrix3();
	Matrix3(Vector3 t_rowOne,
		    Vector3 t_rowTwo,
		    Vector3 t_rowThree);
	Matrix3(float t_a11,
		float t_a12,
		float t_a13,
		float t_a21,
		float t_a22,
		float t_a23,
		float t_a31,
		float t_a32,
		float t_a33);

	Vector3 operator*(Vector3 t_vec) const;
	Matrix3 operator+(Matrix3 t_mat) const;
	Matrix3 operator-(Matrix3 t_mat) const;
	Matrix3 operator*(double t_k) const;
	Matrix3 operator*(Matrix3 t_mat) const;
	Matrix3 operator-() const;
	void operator=(Matrix3 t_mat);

	Matrix3 transpose() const;

	Matrix3 inverse() const;

	Matrix3 rotation(int t_rot) const;

	Matrix3 rotationX(double t_angle) const;
	Matrix3 rotationY(double t_angle) const;
	Matrix3 rotationZ(double t_angle) const;

	Matrix3 translation(double t_dx, double t_dy) const;

	Matrix3 scale(double t_dx, double t_dy) const;
	Matrix3 scale3D(double t_dx) const;

	double determinent() const;
	Vector3 row(int t_i) const;
	Vector3 column(int t_i) const;

	friend std::ostream& operator<<(std::ostream& t_out, const Matrix3& t_quaternion);
private:
	float m_a11;
	float m_a12;
	float m_a13;
	float m_a21;
	float m_a22;
	float m_a23;
	float m_a31;
	float m_a32;
	float m_a33;

	double const PI{ 3.14159265358979323846 };
};

