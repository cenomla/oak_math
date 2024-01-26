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

#include "quat.inl"
