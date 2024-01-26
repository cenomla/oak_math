#include <string.h>

#ifdef _MSC_VER
#include <immintrin.h>
#endif

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
		__m128 v = _mm_set_sd(x);
		__m128 rv = _mm_floor_sd(v, v);
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

