#pragma once

namespace oak {

	float radians(float deg);
	float pi();
	float floor(float v);
	float ceil(float v);
	float round(float v);
	int abs(int v);
	float abs(float v);

	template<typename T>
	T min(T a, T b) {
		if (a < b) { return a; }
		return b;
	}

	template<typename T>
	T max(T a, T b) {
		if (a > b) { return a; }
		return b;
	}

	template<typename T>
	T clamp(T a, T b, T c) {
		return max(a, min(b, c));
	}

	float log2(float v);
	float sin(float a);
	float cos(float a);
	float tan(float a);
	float atan2(float x, float y);
	float sqrt(float x);
	float fast_inv_sqrt(float x);

}

