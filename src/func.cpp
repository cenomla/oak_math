#include "oak_math/func.h"

#include <cmath>

namespace oak {

	float radians(float deg) {
		return deg / 180.0f * pi;
	}

	float floor(float v) {
		return std::floor(v);
	}

	float ceil(float v) {
		return std::ceil(v);
	}

	float round(float v) {
		return std::roundf(v);
	}

	int abs(int v) {
		return std::abs(v);
	}

	float abs(float v) {
		return std::fabs(v);
	}

	float log2(float v) {
		return std::log2f(v);
	}

	float sin(float a) {
		return std::sin(a);
	}

	float cos(float a) {
		return std::cos(a);
	}

	float tan(float a) {
		return std::tan(a);
	}

	float atan2(float x, float y) {
		return std::atan2(x, y);
	}

	float sqrt(float x) {
		return std::sqrt(x);
	}

	float fast_inv_sqrt(float x) {
		float xhalf = 0.5f * x;
		int v;
		for (int i = 0; i < 4; i++) {
			((char*)&v)[i] = ((char*)&x)[i];
		}
		v = 0x5f3759df - (v >> 1);
		for (int i = 0; i < 4; i++) {
			((char*)&x)[i] = ((char*)&v)[i];
		}
		return x * (1.5f - xhalf * x * x);
	}

	bool is_finite(float x) {
		return std::isfinite(x);
	}

}

