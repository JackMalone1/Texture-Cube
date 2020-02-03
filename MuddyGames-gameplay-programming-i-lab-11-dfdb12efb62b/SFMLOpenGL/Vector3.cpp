#include "Vector3.h"
#include "Matrix3.h"


using namespace gpp;

Vector3::Vector3() : m_x{ 0.0f },
					 m_y{ 0.0f },
					 m_z{ 0.0f }
{
}

Vector3::Vector3(float t_x, float t_y, float t_z) : m_x{ t_x },
												       m_y{ t_y },
													   m_z{ t_z }
{
}

float Vector3::length() const 
{
	return sqrt(lengthSquared());
}

float Vector3::lengthSquared() const 
{
	return pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2);
}

Vector3 Vector3::unit() const
{
	Vector3 vec3;

	if (this->length() > 0.0)
	{
		float length = this->length();
		vec3.m_x = this->m_x / length;
		vec3.m_y = this->m_y / length;
		vec3.m_z = this->m_z / length;
	}

	return vec3;
}

void Vector3::normalise()
{
	this->m_x /= this->length();
	this->m_y /= this->length();
	this->m_z /= this->length();
}



Vector3 Vector3::operator+(Vector3 t_vec) const
{
	return {this->m_x + t_vec.m_x, this->m_y + t_vec.m_y, this->m_z + t_vec.m_z};
}

Vector3 Vector3::operator-(Vector3 t_vec) const
{
	return {this->m_x - t_vec.m_x, this->m_y - t_vec.m_y, this->m_z - t_vec.m_z};
}

Vector3 Vector3::operator-() const
{
	return {-this->m_x, -this->m_y, -this->m_z};
}

float Vector3::operator*(Vector3 t_vec) const
{
	return (this->m_x * t_vec.m_x + this->m_y * t_vec.m_y + this->m_z * t_vec.m_z);
}

Vector3 Vector3::operator*(float t_k) const
{
	return {this->m_x * t_k, this->m_y * t_k, this->m_z * t_k};
}

Vector3 Vector3::operator*(double t_k) const
{
	return { static_cast<float>(this->m_x * t_k),
		     static_cast<float>(this->m_y * t_k),
		     static_cast<float>(this->m_z * t_k)};
}

Vector3 Vector3::operator*(int t_k) const
{
	return {this->m_x * t_k, this->m_y * t_k, this->m_z * t_k};
}

Vector3 Vector3::operator*(Matrix3 t_mat3) const
{
	return { t_mat3.row(0).m_x * this->m_x
		   + t_mat3.row(1).m_x * this->m_y
		   + t_mat3.row(2).m_x * this->m_z,
             t_mat3.row(0).m_y * this->m_x
		   + t_mat3.row(1).m_y * this->m_y
		   + t_mat3.row(2).m_y * this->m_y,
			 t_mat3.row(2).m_z * this->m_x
		   + t_mat3.row(1).m_z * this->m_y
		   + t_mat3.row(2).m_z * this->m_z };
}

Vector3 Vector3::operator^(Vector3 t_vec) const
{
	return { this->m_y * t_vec.m_z - this->m_z * t_vec.m_y, this->m_z * t_vec.m_x - this->m_x * t_vec.m_z, this->m_x * t_vec.m_y - this->m_y * t_vec.m_x };
}

//std::ostream& operator<<(std::ostream& t_out, const Vector3& t_vec)
//{
//	t_out << " X: " << t_vec.getX()<< " Y: " << t_vec.m_y << " Z: " << t_vec.m_z;
//	return t_out;
//}
