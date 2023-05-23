#pragma once

#include "detail/defines.h"

namespace oak {

	constexpr float pi = 3.1415926f;
	constexpr float e = 2.7182818f;

	OAK_MATH_API float to_radians(float deg);
	OAK_MATH_API float floor(float v);
	OAK_MATH_API float ceil(float v);
	OAK_MATH_API float round(float v);
	OAK_MATH_API float pow(float v, float e);
	OAK_MATH_API float exp(float v);
	OAK_MATH_API float exp2(float v);
	OAK_MATH_API float ln(float v);
	OAK_MATH_API float log2(float v);
	OAK_MATH_API float sin(float a);
	OAK_MATH_API float cos(float a);
	OAK_MATH_API float tan(float a);
	OAK_MATH_API float asin(float a);
	OAK_MATH_API float acos(float a);
	OAK_MATH_API float atan(float a);
	OAK_MATH_API float atan2(float x, float y);
	OAK_MATH_API float sqrt(float x);
	OAK_MATH_API float fast_inv_sqrt(float x);
	OAK_MATH_API bool is_finite(float x);

	OAK_MATH_API double floor(double v);

	template<typename T>
	constexpr T sign(T v) {
		return (v > T{ 0 }) - (v < T{ 0 });
	}

	template<typename T>
	constexpr T non_zero_sign(T v) {
		return (v >= T{ 0 }) - (v < T{ 0 });
	}

	template<typename T>
	constexpr T abs(T v) {
		return v * sign(v);
	}

	template<typename T>
	constexpr T min(T a, T b) {
		if (a < b) { return a; }
		return b;
	}

	template<typename T>
	constexpr T max(T a, T b) {
		if (a > b) { return a; }
		return b;
	}

	template<typename T>
	constexpr T clamp(T a, T b, T c) {
		return max(a, min(b, c));
	}

	template<typename T, typename U>
	constexpr T lerp(T a, T b, U scale) {
		return a + (b - a) * scale;
	}

}

