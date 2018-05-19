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

	int min(int a, int b) {
		return std::min(a, b);
	}

	int max(int a, int b) {
		return std::max(a, b);
	}

	float min(float a, float b) {
		return std::fmin(a, b);
	}

	float max(float a, float b) {
		return std::fmax(a, b);
	}

	float clamp(float a, float b, float c) {
		return std::fmax(a, std::fmin(b, c));
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

}

