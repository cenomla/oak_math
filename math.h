#pragma once

#include "func.h"
#include "vec.h"
#include "mat.h"
#include "quat.h"

namespace oak {
	
	namespace catagory {
		struct math;
	}

	using Ivec2 = math::Ivec2;
	using Ivec3 = math::Ivec3;
	using Ivec4 = math::Ivec4;

	using Vec2 = math::Vec2;
	using Vec3 = math::Vec3;
	using Vec4 = math::Vec4;

	using Mat2 = math::Mat2;
	using Mat3 = math::Mat3;
	using Mat4 = math::Mat4;

	using Quat = math::Quat;
}
