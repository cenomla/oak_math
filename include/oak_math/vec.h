#pragma once

#include "osig_defs.h"

namespace oak::catagory {
	struct math {};
}

namespace oak {

	struct Ivec2;
	struct Ivec3;
	struct Ivec4;

	struct Vec2;
	struct Vec3;
	struct Vec4;

	struct Mat2;
	struct Mat3;
	struct Mat4;

	struct _reflect(oak::catagory::math) Ivec2 {
		constexpr Ivec2() = default;
		constexpr Ivec2(int v) : x{ v }, y{ v } {};
		constexpr Ivec2(int a, int b) : x{ a }, y{ b } {};
		constexpr Ivec2(const Ivec3& v);
		constexpr Ivec2(const Ivec4& v);

		int x = 0, y = 0;

		explicit operator Vec2() const;
	};

	struct _reflect(oak::catagory::math) Ivec3 {
		constexpr Ivec3() = default;
		constexpr Ivec3(int v) : x{ v }, y{ v }, z{ v } {};
		constexpr Ivec3(int a, int b, int c) : x{ a }, y{ b }, z{ c } {};
		constexpr Ivec3(const Ivec2& a, const int b);
		constexpr Ivec3(const Ivec4& v);

		int x = 0, y = 0, z = 0;

		explicit operator Vec3() const;
	};

	struct _reflect(oak::catagory::math) Ivec4 {
		constexpr Ivec4() = default;
		constexpr Ivec4(int v) : x{ v }, y{ v }, z{ v }, w{ v } {};
		constexpr Ivec4(int a, int b, int c, int d) : x{ a }, y{ b }, z{ c }, w{ d } {};
		constexpr Ivec4(const Ivec2& a, const int b, const int c) : x{ a.x }, y{ a.y }, z{ b }, w{ c } {};
		constexpr Ivec4(const Ivec3& a, const int b) : x{ a.x }, y{ a.y }, z{ a.z }, w{ b } {};

		int x = 0, y = 0, z = 0, w = 0;

		explicit operator Vec4() const;
	};

	constexpr Ivec2::Ivec2(const Ivec3& v) : x{ v.x }, y{ v.y } {};
	constexpr Ivec2::Ivec2(const Ivec4& v) : x{ v.x }, y{ v.y } {};
	constexpr Ivec3::Ivec3(const Ivec2& a, const int b) : x{ a.x }, y{ a.y }, z{ b } {};
	constexpr Ivec3::Ivec3(const Ivec4& v) : x{ v.x }, y{ v.y }, z{ v.z } {};

	struct _reflect(oak::catagory::math) Vec2 {
		Vec2() = default;
		Vec2(float a, float b);
		Vec2(float v);
		Vec2(const Vec3& v);
		Vec2(const Vec4& v);

		explicit operator Ivec2() const;

		float x = 0.0f, y = 0.0f;
	};

	struct _reflect(oak::catagory::math) Vec3 {
		Vec3() = default;
		Vec3(float a, float b, float c);
		Vec3(float v);
		Vec3(const Vec4& v);
		Vec3(const Vec2& v, float a);

		explicit operator Ivec3() const;

		float x = 0.0f, y = 0.0f, z = 0.0f;
	};

	struct _reflect(oak::catagory::math) Vec4 {
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
	Vec2 operator*(float b, const Vec2& a);
	Vec3 operator*(float b, const Vec3& a);
	Vec4 operator*(float b, const Vec4& a);

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

	Vec2 ceil(const Vec2& v);
	Vec3 ceil(const Vec3& v);
	Vec4 ceil(const Vec4& v);

	Ivec2 abs(const Ivec2& v);
	Ivec3 abs(const Ivec3& v);
	Ivec4 abs(const Ivec4& v);
	Vec2 abs(const Vec2& v);
	Vec3 abs(const Vec3& v);
	Vec4 abs(const Vec4& v);

	Ivec2 min(const Ivec2& a, const Ivec2& b);
	Ivec3 min(const Ivec3& a, const Ivec3& b);
	Ivec4 min(const Ivec4& a, const Ivec4& b);
	Vec2 min(const Vec2& a, const Vec2& b);
	Vec3 min(const Vec3& a, const Vec3& b);
	Vec4 min(const Vec4& a, const Vec4& b);

	Ivec2 max(const Ivec2& a, const Ivec2& b);
	Ivec3 max(const Ivec3& a, const Ivec3& b);
	Ivec4 max(const Ivec4& a, const Ivec4& b);
	Vec2 max(const Vec2& a, const Vec2& b);
	Vec3 max(const Vec3& a, const Vec3& b);
	Vec4 max(const Vec4& a, const Vec4& b);

	float dot(const Vec2& a, const Vec2& b);
	float dot(const Vec3& a, const Vec3& b);
	float dot(const Vec4& a, const Vec4& b);

	Mat2 outerProduct(const Vec2& a, const Vec2& b);
	Mat3 outerProduct(const Vec3& a, const Vec3& b);
	Mat4 outerProduct(const Vec4& a, const Vec4& b);

	float cross(const Vec2& a, const Vec2& b);
	Vec2 cross(float s, const Vec2& a);
	Vec2 cross(const Vec2& a, float s);
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

	Vec2 rotate(const Vec2 v, const float angle);

	Vec2 left(const Vec2 v);
	Vec2 right(const Vec2 v);

	Vec2 reflect(const Vec2 v, const Vec2 n);
	Vec3 reflect(const Vec3 v, const Vec3 n);

}

