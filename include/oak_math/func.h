#pragma once

namespace oak {

	constexpr float pi = 3.1415926f;
	constexpr float e = 2.7182818f;

	float to_radians(float deg);
	float floor(float v);
	float ceil(float v);
	float round(float v);
	float pow(float v, float e);
	float exp(float v);

	template<typename T>
	constexpr T sign(T v) {
		return (T{ 0 } < v) - (T{ 0 } > v);
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

	float log2(float v);
	float sin(float a);
	float cos(float a);
	float tan(float a);
	float atan2(float x, float y);
	float sqrt(float x);
	float fast_inv_sqrt(float x);
	bool is_finite(float x);

}

