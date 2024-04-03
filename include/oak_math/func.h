#pragma once

namespace oak {

	constexpr float m_pi = 3.1415926f;
	constexpr float m_e = 2.7182818f;

	constexpr double m_l_pi = 3.14159265358979323846;
	constexpr double m_l_e = 2.71828182845904523536;

	float to_radians(float deg);
	float floor(float v);
	float ceil(float v);
	float round(float v);
	float pow(float v, float e);
	float exp(float v);
	float exp2(float v);
	float ln(float v);
	float log2(float v);
	float sin(float a);
	float cos(float a);
	float tan(float a);
	float asin(float a);
	float acos(float a);
	float atan(float a);
	float atan2(float x, float y);
	float sqrt(float x);
	float cbrt(float x);
	float fast_inv_sqrt(float x);
	bool is_finite(float x);
	bool is_nan(float x);
	float fmod(float x, float y);

	double floor(double v);
	double sqrt(double v);
	double exp(double v);

	template<typename T>
	constexpr T sign(T v) {
		return static_cast<T>(v > T{0}) - static_cast<T>(v < T{0});
	}

	template<typename T>
	constexpr T non_zero_sign(T v) {
		return static_cast<T>(v >= T{0}) - static_cast<T>(v < T{0});
	}

	template<typename T>
	constexpr T abs(T v) {
		return v < T{ 0 } ? -v : v;
	}

	template<typename T>
	constexpr T min(T a, T b) {
		return a < b ? a : b;
	}

	template<typename T>
	constexpr T max(T a, T b) {
		return a > b ? a : b;
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

#include "func.inl"
