#pragma once

#include <string.h>

#ifdef _MSC_VER
#include <smmintrin.h>
#endif

#ifdef _MSC_VER
extern "C" __declspec(dllimport) float powf(float b, float e);
extern "C" __declspec(dllimport) float expf(float x);
extern "C" __declspec(dllimport) float exp2f(float x);
extern "C" __declspec(dllimport) float logf(float x);
extern "C" __declspec(dllimport) float log2f(float x);
extern "C" __declspec(dllimport) float sinf(float x);
extern "C" __declspec(dllimport) float cosf(float x);
extern "C" __declspec(dllimport) float tanf(float x);
extern "C" __declspec(dllimport) float asinf(float x);
extern "C" __declspec(dllimport) float acosf(float x);
extern "C" __declspec(dllimport) float atanf(float x);
extern "C" __declspec(dllimport) float atan2f(float x, float y);
extern "C" __declspec(dllimport) float sqrtf(float x);
extern "C" __declspec(dllimport) float cbrtf(float x);
extern "C" __declspec(dllimport) float fmodf(float x, float y);
extern "C" __declspec(dllimport) double sqrt(double x);
extern "C" __declspec(dllimport) double exp(double x);
#elif __ANDROID__
extern "C" float powf(float b, float e);
extern "C" float expf(float x);
extern "C" float exp2f(float x);
extern "C" float logf(float x);
extern "C" float log2f(float x);
extern "C" float sinf(float x);
extern "C" float cosf(float x);
extern "C" float tanf(float x);
extern "C" float asinf(float x);
extern "C" float acosf(float x);
extern "C" float atanf(float x);
extern "C" float atan2f(float x, float y);
extern "C" float sqrtf(float x);
extern "C" float cbrtf(float x);
extern "C" float fmodf(float x, float y);
extern "C" double sqrt(double x);
extern "C" double exp(double x);
#else
extern "C" float powf(float b, float e) noexcept(true);
extern "C" float expf(float x) noexcept(true);
extern "C" float exp2f(float x) noexcept(true);
extern "C" float logf(float x) noexcept(true);
extern "C" float log2f(float x) noexcept(true);
extern "C" float sinf(float x) noexcept(true);
extern "C" float cosf(float x) noexcept(true);
extern "C" float tanf(float x) noexcept(true);
extern "C" float asinf(float x) noexcept(true);
extern "C" float acosf(float x) noexcept(true);
extern "C" float atanf(float x) noexcept(true);
extern "C" float atan2f(float x, float y) noexcept(true);
extern "C" float sqrtf(float x) noexcept(true);
extern "C" float cbrtf(float x) noexcept(true);
extern "C" float fmodf(float x, float y) noexcept(true);
extern "C" double sqrt(double x) noexcept(true);
extern "C" double exp(double x) noexcept(true);
#endif


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

// Implementation
namespace oak {

	inline float radians(float deg) {
		return deg / 180.0f * m_pi;
	}

	inline float floor(float x) {
#ifdef _MSC_VER
		__m128 v = _mm_set_ss(x);
		__m128 rv = _mm_floor_ss(v, v);
		return _mm_cvtss_f32(rv);
#else
		return __builtin_floorf(x);
#endif
	}

	inline float ceil(float x) {
#ifdef _MSC_VER
		__m128 v = _mm_set_ss(x);
		__m128 rv = _mm_ceil_ss(v, v);
		return _mm_cvtss_f32(rv);
#else
		return __builtin_ceilf(x);
#endif
	}

	inline float round(float x) {
#ifdef _MSC_VER
		__m128 v = _mm_set_ss(x);
		__m128 rv = _mm_round_ss(v, v, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
		return _mm_cvtss_f32(rv);
#else
		return __builtin_roundf(x);
#endif
	}

	inline float pow(float b, float e) {
		return ::powf(b, e);
	}

	inline float exp(float v) {
		return ::expf(v);
	}

	inline float exp2(float v) {
		return ::exp2f(v);
	}

	inline float ln(float v) {
		return ::logf(v);
	}

	inline float log2(float v) {
		return ::log2f(v);
	}

	inline float sin(float a) {
		return ::sinf(a);
	}

	inline float cos(float a) {
		return ::cosf(a);
	}

	inline float tan(float a) {
		return ::tanf(a);
	}

	inline float asin(float a) {
		return ::asinf(a);
	}

	inline float acos(float a) {
		return ::acosf(a);
	}

	inline float atan(float a) {
		return ::atanf(a);
	}

	inline float atan2(float x, float y) {
		return ::atan2f(x, y);
	}

	inline float sqrt(float x) {
		return ::sqrtf(x);
	}

	inline float cbrt(float x) {
		return ::cbrtf(x);
	}

	inline float fast_inv_sqrt(float x) {
		float xhalf = 0.5f * x;
		int v;
		memcpy(&v, &x, sizeof(float));
		v = 0x5f3759df - (v >> 1);
		memcpy(&x, &v, sizeof(float));
		return x * (1.5f - xhalf * x * x);
	}

	inline bool is_finite(float x) {
		unsigned int v;
		memcpy(&v, &x, sizeof(float));

		return static_cast<bool>(((v & 0x7f800000) - 0x7f800000) >> 31);
	}

	inline bool is_nan(float x) {
		return x != x;
	}

	inline float fmod(float x, float y) {
		return ::fmodf(x, y);
	}

	inline double floor(double x) {
#ifdef _MSC_VER
		__m128d v = _mm_set_sd(x);
		__m128d rv = _mm_floor_sd(v, v);
		return _mm_cvtsd_f64(rv);
#else
		return __builtin_floor(x);
#endif
	}

	inline double sqrt(double v) {
		return ::sqrt(v);
	}

	inline double exp(double v) {
		return ::exp(v);
	}

}

