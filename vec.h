#pragma once

#ifdef __OSIG__
#define _reflect(x) __attribute__((annotate("reflect:"#x)))
#else
#define _reflect(x)
#endif

namespace oak::math {

	struct Vec2;
	struct Vec3;
	struct Vec4;

	struct Mat2;
	struct Mat3;
	struct Mat4;

	struct _reflect("math") Ivec2 {
		Ivec2() = default;
		Ivec2(int v);
		Ivec2(int a, int b);

		int x = 0, y = 0;
	};

	struct _reflect("math") Ivec3 {
		Ivec3() = default;
		Ivec3(int v);
		Ivec3(int a, int b, int c);

		int x = 0, y = 0, z = 0;
	};

	struct _reflect("math") Ivec4 {
		Ivec4() = default;
		Ivec4(int v);
		Ivec4(int a, int b, int c, int d);

		int x = 0, y = 0, z = 0, w = 0;
	};

	struct _reflect("math") Vec2 {
		Vec2() = default;
		Vec2(float a, float b);
		Vec2(float v);
		Vec2(const Vec3& v);
		Vec2(const Vec4& v);

        explicit operator Ivec2() const;

		float x = 0.0f, y = 0.0f;
	};

	struct _reflect("math") Vec3 {
		Vec3() = default;
		Vec3(float a, float b, float c);
		Vec3(float v);
		Vec3(const Vec4& v);
		Vec3(const Vec2& v, float a);

        explicit operator Ivec3() const;

		float x = 0.0f, y = 0.0f, z = 0.0f;
	};

	struct _reflect("math") Vec4 {
		Vec4() = default;
		Vec4(float a, float b, float c, float d);
		Vec4(float v);
		Vec4(const Vec2& v, float a, float b);
		Vec4(const Vec3& v, float a);
		Vec4(const Vec2& a, const Vec2& b);

        explicit operator Ivec4() const;

		float x = 0.0f, y = 0.0f, z = 0.0f, w = 0.0f;
	};

	bool operator==(const Ivec2& a, const Ivec2& b);
	bool operator==(const Ivec3& a, const Ivec3& b);
	bool operator==(const Ivec4& a, const Ivec4& b);
	bool operator==(const Vec2& a, const Vec2& b);
	bool operator==(const Vec3& a, const Vec3& b);
	bool operator==(const Vec4& a, const Vec4& b);

	bool operator!=(const Ivec2& a, const Ivec2& b);
	bool operator!=(const Ivec3& a, const Ivec3& b);
	bool operator!=(const Ivec4& a, const Ivec4& b);
	bool operator!=(const Vec2& a, const Vec2& b);
	bool operator!=(const Vec3& a, const Vec3& b);
	bool operator!=(const Vec4& a, const Vec4& b);

	Ivec2 operator-(const Ivec2& v);
	Ivec3 operator-(const Ivec3& v);
	Ivec4 operator-(const Ivec4& v);
	Vec2 operator-(const Vec2& v);
	Vec3 operator-(const Vec3& v);
	Vec4 operator-(const Vec4& v);

	Ivec2 operator+(const Ivec2& a, const Ivec2& b);
	Ivec3 operator+(const Ivec3& a, const Ivec3& b);
	Ivec4 operator+(const Ivec4& a, const Ivec4& b);
	Vec2 operator+(const Vec2& a, const Vec2& b);
	Vec3 operator+(const Vec3& a, const Vec3& b);
	Vec4 operator+(const Vec4& a, const Vec4& b);

	Ivec2 operator-(const Ivec2& a, const Ivec2& b);
	Ivec3 operator-(const Ivec3& a, const Ivec3& b);
	Ivec4 operator-(const Ivec4& a, const Ivec4& b);
	Vec2 operator-(const Vec2& a, const Vec2& b);
	Vec3 operator-(const Vec3& a, const Vec3& b);
	Vec4 operator-(const Vec4& a, const Vec4& b);

	Ivec2 operator*(const Ivec2& a, int b);
	Ivec3 operator*(const Ivec3& a, int b);
	Ivec4 operator*(const Ivec4& a, int b);
	Vec2 operator*(const Vec2& a, float b);
	Vec3 operator*(const Vec3& a, float b);
	Vec4 operator*(const Vec4& a, float b);

	Ivec2 operator*(const Ivec2& a, const Ivec2& b);
	Ivec3 operator*(const Ivec3& a, const Ivec3& b);
	Ivec4 operator*(const Ivec4& a, const Ivec4& b);
	Vec2 operator*(const Vec2& a, const Vec2& b);
	Vec3 operator*(const Vec3& a, const Vec3& b);
	Vec4 operator*(const Vec4& a, const Vec4& b);
	
	Ivec2 operator/(const Ivec2& a, int b);
	Ivec3 operator/(const Ivec3& a, int b);
	Ivec4 operator/(const Ivec4& a, int b);
	Vec2 operator/(const Vec2& a, float b);
	Vec3 operator/(const Vec3& a, float b);
	Vec4 operator/(const Vec4& a, float b);

	Ivec2 operator/(const Ivec2& a, const Ivec2& b);
	Ivec3 operator/(const Ivec3& a, const Ivec3& b);
	Ivec4 operator/(const Ivec4& a, const Ivec4& b);
	Vec2 operator/(const Vec2& a, const Vec2& b);
	Vec3 operator/(const Vec3& a, const Vec3& b);
	Vec4 operator/(const Vec4& a, const Vec4& b);

	Ivec2& operator+=(Ivec2& a, const Ivec2& b);
	Ivec3& operator+=(Ivec3& a, const Ivec3& b);
	Ivec4& operator+=(Ivec4& a, const Ivec4& b);
	Vec2& operator+=(Vec2& a, const Vec2& b);
	Vec3& operator+=(Vec3& a, const Vec3& b);
	Vec4& operator+=(Vec4& a, const Vec4& b);

	Ivec2& operator-=(Ivec2& a, const Ivec2& b);
	Ivec3& operator-=(Ivec3& a, const Ivec3& b);
	Ivec4& operator-=(Ivec4& a, const Ivec4& b);
	Vec2& operator-=(Vec2& a, const Vec2& b);
	Vec3& operator-=(Vec3& a, const Vec3& b);
	Vec4& operator-=(Vec4& a, const Vec4& b);

	Ivec2& operator*=(Ivec2& a, int b);
	Ivec3& operator*=(Ivec3& a, int b);
	Ivec4& operator*=(Ivec4& a, int b);
	Vec2& operator*=(Vec2& a, float b);
	Vec3& operator*=(Vec3& a, float b);
	Vec4& operator*=(Vec4& a, float b);

	Ivec2& operator*=(Ivec2& a, const Ivec2& b);
	Ivec3& operator*=(Ivec3& a, const Ivec3& b);
	Ivec4& operator*=(Ivec4& a, const Ivec4& b);
	Vec2& operator*=(Vec2& a, const Vec2& b);
	Vec3& operator*=(Vec3& a, const Vec3& b);
	Vec4& operator*=(Vec4& a, const Vec4& b);
	
	Ivec2& operator/=(Ivec2& a, int b);
	Ivec3& operator/=(Ivec3& a, int b);
	Ivec4& operator/=(Ivec4& a, int b);
	Vec2& operator/=(Vec2& a, float b);
	Vec3& operator/=(Vec3& a, float b);
	Vec4& operator/=(Vec4& a, float b);

	Ivec2& operator/=(Ivec2& a, const Ivec2& b);
	Ivec3& operator/=(Ivec3& a, const Ivec3& b);
	Ivec4& operator/=(Ivec4& a, const Ivec4& b);
	Vec2& operator/=(Vec2& a, const Vec2& b);
	Vec3& operator/=(Vec3& a, const Vec3& b);
	Vec4& operator/=(Vec4& a, const Vec4& b);

	Vec2 floor(const Vec2& v);
	Vec3 floor(const Vec3& v);
	Vec4 floor(const Vec4& v);

	Vec2 round(const Vec2& v);
	Vec3 round(const Vec3& v);
	Vec4 round(const Vec4& v);

	Ivec2 abs(const Ivec2& v);
	Ivec3 abs(const Ivec3& v);
	Ivec4 abs(const Ivec4& v);
	Vec2 abs(const Vec2& v);
	Vec3 abs(const Vec3& v);
	Vec4 abs(const Vec4& v);

	float dot(const Vec2& a, const Vec2& b);
	float dot(const Vec3& a, const Vec3& b);
	float dot(const Vec4& a, const Vec4& b);

	Mat2 outerProduct(const Vec2& a, const Vec2& b);
	Mat3 outerProduct(const Vec3& a, const Vec3& b);
	Mat4 outerProduct(const Vec4& a, const Vec4& b);

	Vec3 cross(const Vec3& a, const Vec3& b);

	Vec2 vectorTriple(const Vec2& a, const Vec2& b, const Vec2& c);
	Vec3 vectorTriple(const Vec3& a, const Vec3& b, const Vec3& c);

	float scalarTriple(const Vec3& a, const Vec3& b, const Vec3& c);

	float length(const Vec2& v);
	float length(const Vec3& v);
	float length(const Vec4& v);

	Vec2 normalize(const Vec2& v);
	Vec3 normalize(const Vec3& v);
	Vec4 normalize(const Vec4& v);

}
