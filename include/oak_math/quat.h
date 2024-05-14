#pragma once

#include "detail/defines.h"
#include "func.h"
#include "vec.h"
#include "mat.h"

namespace oak {

	struct _reflect() Quat {
		Quat() = default;
		Quat(float v);
		Quat(float a, float b, float c, float d);
		Quat(const Vec3& v);

		float x = 0.0f, y = 0.0f, z = 0.0f, w = 0.0f;
	};

	Vec3 operator*(const Quat& a, const Vec3& b);

	float length(Quat const& q);
	Quat normalize(Quat const& q);

	Mat3 to_mat3(const Quat& q);
	Mat4 to_mat4(const Quat& q);
}

// Implementation
namespace oak {

	inline Quat::Quat(float v) : x{ v }, y{ v }, z{ v }, w{ v } {}

	inline Quat::Quat(float a, float b, float c, float d) : x{ a }, y{ b }, z{ c }, w{ d } {}

	inline Quat::Quat(const Vec3& v) {
		Vec3 c{ cos(v.x * 0.5f), cos(v.y * 0.5f), cos(v.z * 0.5f) };
		Vec3 s{ sin(v.x * 0.5f), sin(v.y * 0.5f), sin(v.z * 0.5f) };

		x = s.x * c.y * c.z - c.x * s.y * s.z;
		y = c.x * s.y * c.z + s.x * c.y * s.z;
		z = c.x * c.y * s.z - s.x * s.y * c.z;
		w = c.x * c.y * c.z + s.x * s.y * s.z;
	}

	inline Vec3 operator*(const Quat& a, const Vec3& b) {
		Vec3 qv{ a.x, a.y, a.z };
		Vec3 uv{ cross(qv, b) };
		Vec3 uuv{ cross(qv, uv) };

		return b + ((uv * a.w) + uuv) * 2.0f;
	}

	inline float length(Quat const& q) {
		return sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);
	}

	inline Quat normalize(Quat const& q) {
		auto l = length(q);
		return l == 0.0f ? q : Quat{ q.x / l, q.y / l, q.z / l, q.w / l };
	}

	inline Mat3 to_mat3(const Quat& q) {
		float qxx = q.x * q.x;
		float qyy = q.y * q.y;
		float qzz = q.z * q.z;
		float qxz = q.x * q.z;
		float qxy = q.x * q.y;
		float qyz = q.y * q.z;
		float qwx = q.w * q.x;
		float qwy = q.w * q.y;
		float qwz = q.w * q.z;

		return Mat3{
			Mat3::column_type{ 1.0f - 2.0f * (qyy + qzz), 2.0f * (qxy + qwz), 2.0f * (qxz - qwy) },
			Mat3::column_type{ 2.0f * (qxy - qwz), 1.0f - 2.0f * (qxx + qzz), 2.0f * (qyz + qwx) },
			Mat3::column_type{ 2.0f * (qxz + qwy), 2.0f * (qyz - qwx), 1.0f - 2.0f * (qxx + qyy) }
		};
	}

	inline Mat4 to_mat4(const Quat& q) {
		return Mat4{ to_mat3(q) };
	}

}

