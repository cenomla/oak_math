#pragma once

#include "detail/defines.h"
#include "mat.h"

namespace oak {

	struct _reflect(oak::catagory::math) OAK_MATH_API Quat {
		Quat() = default;
		Quat(float v);
		Quat(float a, float b, float c, float d);
		Quat(const Vec3& v);

		float x = 0.0f, y = 0.0f, z = 0.0f, w = 0.0f;
	};

	OAK_MATH_API Vec3 operator*(const Quat& a, const Vec3& b);

	OAK_MATH_API float length(Quat const& q);
	OAK_MATH_API Quat normalize(Quat const& q);

	OAK_MATH_API Mat3 toMat3(const Quat& q);
	OAK_MATH_API Mat4 toMat4(const Quat& q);
}

