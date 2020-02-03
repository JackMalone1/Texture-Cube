#include "Matrix3.h"

Matrix3::Matrix3() : m_a11{0.0},
                     m_a12{ 0.0 },
                     m_a13{ 0.0 },
                     m_a21{ 0.0 },
                     m_a22{ 0.0 },
                     m_a23{ 0.0 },
                     m_a31{ 0.0 },
                     m_a32{ 0.0 }, 
                     m_a33{ 0.0 }
{
}

Matrix3::Matrix3(Vector3 t_rowOne,
	             Vector3 t_rowTwo,
	             Vector3 t_rowThree) : m_a11{ t_rowOne.getX() },
	                                   m_a12{ t_rowOne.getY() },
	                                   m_a13{ t_rowOne.getZ() },
	                                   m_a21{ t_rowTwo.getX() },
	                                   m_a22{ t_rowTwo.getY() },
	                                   m_a23{ t_rowTwo.getZ() },
                                   	   m_a31{ t_rowThree.getX() },
	                                   m_a32{ t_rowThree.getY() },
	                                   m_a33{ t_rowThree.getZ() }
{
}

Matrix3::Matrix3(float t_a11,
	             float t_a12,
	             float t_a13,
	             float t_a21,
	             float t_a22,
	             float t_a23,
	             float t_a31,
	             float t_a32,
	             float t_a33) : m_a11{ t_a11 },
	                             m_a12{ t_a12 },
	                             m_a13{ t_a13 },
	                             m_a21{ t_a21 },
	                             m_a22{ t_a22 },
	                             m_a23{ t_a23 },
	                             m_a31{ t_a31 },
	                             m_a32{ t_a32 },
	                             m_a33{ t_a33 }
{
}

Vector3 Matrix3::operator*(Vector3 t_vec) const
{
	return { static_cast<float>(this->m_a11 * t_vec.getX() + this->m_a12 * t_vec.getY() + this->m_a13 * t_vec.getZ()),
			 static_cast<float>(this->m_a21 * t_vec.getX() + this->m_a22 * t_vec.getY() + this->m_a23 * t_vec.getZ()),
			 static_cast<float>(this->m_a31 * t_vec.getX() + this->m_a32 * t_vec.getY() + this->m_a33 * t_vec.getZ()) };
}

Matrix3 Matrix3::operator+(Matrix3 t_mat) const
{
	return Matrix3(this->m_a11 + t_mat.m_a11,
		           this->m_a12 + t_mat.m_a12, 
		           this->m_a13 + t_mat.m_a13,
		           this->m_a21 + t_mat.m_a21,
		           this->m_a22 + t_mat.m_a22,
		           this->m_a23 + t_mat.m_a23,
		           this->m_a31 + t_mat.m_a31,
		           this->m_a32 + t_mat.m_a32,
		           this->m_a33 + t_mat.m_a33);
}

Matrix3 Matrix3::operator-(Matrix3 t_mat) const
{
	return Matrix3(this->m_a11 - t_mat.m_a11,
		           this->m_a12 - t_mat.m_a12,
		           this->m_a13 - t_mat.m_a13,
		           this->m_a21 - t_mat.m_a21,
		           this->m_a22 - t_mat.m_a22,
		           this->m_a23 - t_mat.m_a23,
		           this->m_a31 - t_mat.m_a31,
		           this->m_a32 - t_mat.m_a32,
		           this->m_a33 - t_mat.m_a33);
}

Matrix3 Matrix3::operator*(double t_k) const
{
	return Matrix3(this->m_a11 * t_k,
		           this->m_a12 * t_k,
		           this->m_a13 * t_k,
		           this->m_a21 * t_k,
		           this->m_a22 * t_k,
		           this->m_a23 * t_k,
		           this->m_a31 * t_k,
		           this->m_a32 * t_k,
	               this->m_a33 * t_k);
}

Matrix3 Matrix3::operator*(Matrix3 t_mat) const
{
	return Matrix3(this->row(0) * t_mat.column(0), this->row(0) * t_mat.column(1), this->row(0) * t_mat.column(2),
		this->row(1) * t_mat.column(0), this->row(1) * t_mat.column(1), this->row(1) * t_mat.column(2),
		this->row(2) * t_mat.column(0), this->row(2) * t_mat.column(1), this->row(2) * t_mat.column(2));
}

Matrix3 Matrix3::operator-() const
{
	return Matrix3( *this * -1 );
}

void Matrix3::operator=(Matrix3 t_mat)
{
	this->m_a11 = t_mat.m_a11;
	this->m_a12 = t_mat.m_a12;
	this->m_a13 = t_mat.m_a13;
	this->m_a21 = t_mat.m_a21;
	this->m_a22 = t_mat.m_a22;
	this->m_a23 = t_mat.m_a23;
	this->m_a31 = t_mat.m_a31;
	this->m_a32 = t_mat.m_a32;
	this->m_a33 = t_mat.m_a33;
}

Matrix3 Matrix3::transpose() const
{
	return Matrix3(this->m_a11, this->m_a21, this->m_a31,
		           this->m_a12, this->m_a22, this->m_a32,
		           this->m_a13, this->m_a23, this->m_a33);
}

Matrix3 Matrix3::inverse() const
{
	if (this->determinent() == 0)
	{
		return Matrix3();
	}
	else
	{
		double scale = 1 / this->determinent();
		return Matrix3(scale * (this->m_a22 * this->m_a33 - this->m_a23 * this->m_a32),
			scale * (this->m_a13 * this->m_a32 - this->m_a12 * this->m_a33),
			scale * (this->m_a12 * this->m_a23 - this->m_a13 * this->m_a22),
			scale * (this->m_a23 * this->m_a31 - this->m_a21 * this->m_a33),
			scale * (this->m_a11 * this->m_a33 - this->m_a13 * this->m_a31),
			scale * (this->m_a13 * this->m_a21 - this->m_a11 * this->m_a23),
			scale * (this->m_a21 * this->m_a32 - this->m_a22 * this->m_a31),
			scale * (this->m_a12 * this->m_a31 - this->m_a11 * this->m_a32),
			scale * (this->m_a11 * this->m_a22 - this->m_a12 * this->m_a21));
	}
}

Matrix3 Matrix3::rotation(int t_rot) const
{
	double angleToRadians = PI / 180 * t_rot;
	return Matrix3(cos(angleToRadians), sin(angleToRadians), 0.0,
		           -sin(angleToRadians), cos(angleToRadians), 0.0,
		           0.0, 0.0, 1.0);
}

Matrix3 Matrix3::rotationX(double t_angle) const
{
	double angleToRadians = PI / 180 * t_angle;

	return Matrix3(1,
		           0,
		           0,
		           0,
		           cos(angleToRadians),
		           -sin(angleToRadians),
		           0,
		           sin(angleToRadians),
		           cos(angleToRadians));
}

Matrix3 Matrix3::rotationY(double t_angle) const
{
	double angleToRadians = PI / 180 * t_angle;

	return Matrix3(cos(angleToRadians),
		           0,
		           sin(angleToRadians),
		           0,
		           1,
		           0,
		           -sin(angleToRadians),
		           0,
		           cos(angleToRadians));
}

Matrix3 Matrix3::rotationZ(double t_angle) const
{

	Matrix3 rotationZ;
	double angleRadians = PI / 180 * t_angle;
	//row one
	rotationZ.m_a11 = cos(angleRadians);
	rotationZ.m_a12 = -sin(angleRadians);
	rotationZ.m_a13 = 0;
	//row two
	rotationZ.m_a21 = sin(angleRadians);
	rotationZ.m_a22 = cos(angleRadians);
	rotationZ.m_a23 = 0;
	//row three
	rotationZ.m_a31 = 0;
	rotationZ.m_a32 = 0;
	rotationZ.m_a33 = 1;
	return rotationZ;
}

Matrix3 Matrix3::translation(double t_dx, double t_dy) const
{
	return Matrix3(1,
		           0,
		           t_dx,
		           0,
		           1,
		           t_dy,
		           0,
		           0,
		           1);
}

Matrix3 Matrix3::scale(double t_dx, double t_dy) const
{
	return Matrix3(t_dx / 100.0,
		           0,
		           0,
		           0,
		           t_dy / 100.0,
		           0,
		           0,
		           0,
		           1);
}

Matrix3 Matrix3::scale3D(double t_dx) const
{

	return Matrix3(t_dx / 100.0,
		           0,
		           0,
		           0,
		           t_dx / 100.0,
		           0,
		           0,
		           0,
		           t_dx / 100.0);
}

double Matrix3::determinent() const
{
	return this->m_a11 
		* this->m_a22
		* this->m_a33
		- this->m_a11
		* this->m_a32
		* this->m_a23
		+ this->m_a21
		* this->m_a32
		* this->m_a13
		- this->m_a31
		* this->m_a22 
		* this->m_a13
		+ this->m_a31
		* this->m_a12
		* this->m_a23 
		- this->m_a21 
		* this->m_a12 
		* this->m_a33;
}

Vector3 Matrix3::row(int i) const
{
	switch (i)
	{
	case 0:
		return { static_cast<float>(this->m_a11), static_cast<float>(this->m_a12), static_cast<float>(this->m_a13) };
		break;
	case 1:
		return { static_cast<float>(this->m_a21), static_cast<float>(this->m_a22), static_cast<float>(this->m_a23) };
		break;
	case 2:
		return { static_cast<float>(this->m_a31), static_cast<float>(this->m_a32), static_cast<float>(this->m_a33) };
		break;
	}
}

Vector3 Matrix3::column(int t_i) const
{
	switch (t_i)
	{
	case 0:
		return { static_cast<float>(this->m_a11), static_cast<float>(this->m_a21), static_cast<float>(this->m_a31) };
		break;
	case 1:
		return { static_cast<float>(this->m_a12), static_cast<float>(this->m_a22), static_cast<float>(this->m_a32) };
		break;
	case 2:
		return { static_cast<float>(this->m_a13), static_cast<float>(this->m_a23), static_cast<float>(this->m_a33) };
		break;
	}
}

std::ostream& operator<<(std::ostream& t_out, const Matrix3& t_matrix)
{
	t_out << "(" << t_matrix.m_a11 << ", " << t_matrix.m_a12 << ", " << t_matrix.m_a13 << ")" << std::endl;
	t_out << "(" << t_matrix.m_a21 << ", " << t_matrix.m_a22 << ", " << t_matrix.m_a23 << ")" << std::endl;
	t_out << "(" << t_matrix.m_a31 << ", " << t_matrix.m_a32 << ", " << t_matrix.m_a33 << ")" << std::endl;
	return t_out;
}
