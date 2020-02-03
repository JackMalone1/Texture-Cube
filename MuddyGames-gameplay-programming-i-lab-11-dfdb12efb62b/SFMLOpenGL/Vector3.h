#pragma once
#include <math.h>
#include <iostream>
#include <string>

class Matrix3;

namespace gpp
{
	class Vector3
	{
	public:
		float getX() { return m_x; } const
		float getY() { return m_y; } const
		float getZ() { return m_z; } const
		void setX(float t_x) { m_x = t_x; }
		void setY(float t_y) { m_y = t_y; }
		void setZ(float t_z) { m_z = t_z; }

		Vector3();
		Vector3(float t_x, float t_y, float t_z);


		float length() const;
		float lengthSquared() const;
		Vector3 unit() const;
		void normalise();
		Vector3 rotate(int t_angle);

		Vector3 operator+(Vector3 t_vec) const;
		Vector3 operator-(Vector3 t_vec) const;
		Vector3 operator-() const;
		float operator*(Vector3 t_vec) const;
		Vector3 operator*(float t_k) const;
		Vector3 operator*(double t_k) const;
		Vector3 operator*(int t_k) const;
		Vector3 operator*(Matrix3 t_mat3) const;
		Vector3 operator^(Vector3 t_vec) const;

		friend std::ostream& operator<<(std::ostream& t_out, const Vector3& t_vec);
	private:
		float m_x;
		float m_y;
		float m_z;
	};
}


