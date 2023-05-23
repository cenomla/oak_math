#define OAK_MATH_EXPORT_SYMBOLS

#include <oak_math/func.h>

#include <math.h>

namespace oak {

	float radians(float deg) {
		return deg / 180.0f * pi;
	}

	float floor(float v) {
		return ::floorf(v);
	}

	float ceil(float v) {
		return ::ceilf(v);
	}

	float round(float v) {
		return ::roundf(v);
	}

	float pow(float v, float e) {
		return ::powf(v, e);
	}

	float exp(float v) {
		return ::expf(v);
	}

	float exp2(float v) {
		return ::exp2f(v);
	}

	float ln(float v) {
		return ::logf(v);
	}

	float log2(float v) {
		return ::log2f(v);
	}

	float sin(float a) {
		return ::sinf(a);
	}

	float cos(float a) {
		return ::cosf(a);
	}

	float tan(float a) {
		return ::tanf(a);
	}

	float asin(float a) {
		return ::asinf(a);
	}

	float acos(float a) {
		return ::acosf(a);
	}

	float atan(float a) {
		return ::atanf(a);
	}

	float atan2(float x, float y) {
		return ::atan2f(x, y);
	}

	float sqrt(float x) {
		return ::sqrtf(x);
	}

	float fast_inv_sqrt(float x) {
		float xhalf = 0.5f * x;
		int v;
		for (int i = 0; i < 4; ++i) {
			reinterpret_cast<char*>(&v)[i] = reinterpret_cast<char*>(&x)[i];
		}
		v = 0x5f3759df - (v >> 1);
		for (int i = 0; i < 4; ++i) {
			reinterpret_cast<char*>(&x)[i] = reinterpret_cast<char*>(&v)[i];
		}
		return x * (1.5f - xhalf * x * x);
	}

	bool is_finite(float x) {
		return isfinite(x);
	}

	double floor(double v) {
		return ::floor(v);
	}

}

