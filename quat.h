#pragma once

#include "mat.h"

namespace oak::math {

	struct _reflect(oak::catagory::math) Quat {
		Quat() = default;
		Quat(float v);
		Quat(float a, float b, float c, float d);
		Quat(const Vec3& v);

		float x = 0.0f, y = 0.0f, z = 0.0f, w = 0.0f;
	};

	Vec3 operator*(const Quat& a, const Vec3& b);

	Mat3 toMat3(const Quat& q);
	Mat4 toMat4(const Quat& q);
}
