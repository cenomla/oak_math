#include "func.h"

#include <cmath>

namespace oak::math {

	float radians(float deg) {
		return deg / 180.0f * pi();
	}

	float pi() {
		return 3.14159265358979f;
	}

	float floor(float v) {
		return std::floor(v);
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

}
