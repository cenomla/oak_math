#include "util.h"

#include <cmath>

namespace oak::math {

	float radians(float deg) {
		return deg / 180.0f * pi();
	}

	float pi() {
		return 3.14159265358979f;
	}

	float abs(float v) {
		return std::fabs(v);
	}

}
