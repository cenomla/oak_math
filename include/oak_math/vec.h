#pragma once

#include "detail/defines.h"
#include "func.h"

namespace oak {

	struct Ivec2;
	struct Ivec3;
	struct Ivec4;

	struct Uvec2;
	struct Uvec3;
	struct Uvec4;

	struct Vec2;
	struct Vec3;
	struct Vec4;

	struct Mat2;
	struct Mat3;
	struct Mat4;

	struct _reflect() Ivec2 {
		constexpr Ivec2() = default;
		constexpr Ivec2(int v) : x{ v }, y{ v } {}
		constexpr Ivec2(int a, int b) : x{ a }, y{ b } {}
		constexpr Ivec2(Ivec3 const& v);
		constexpr Ivec2(Ivec4 const& v);

		_reflect() int x = 0, _reflect() y = 0;

		explicit constexpr operator Vec2() const;
	};

	struct _reflect() Ivec3 {
		constexpr Ivec3() = default;
		constexpr Ivec3(int v) : x{ v }, y{ v }, z{ v } {}
		constexpr Ivec3(int a, int b, int c) : x{ a }, y{ b }, z{ c } {}
		constexpr Ivec3(Ivec2 const& a, int b);
		constexpr Ivec3(Ivec4 const& v);

		_reflect() int x = 0, _reflect() y = 0, _reflect() z = 0;

		explicit constexpr operator Vec3() const;
	};

	struct _reflect() Ivec4 {
		constexpr Ivec4() = default;
		constexpr Ivec4(int v) : x{ v }, y{ v }, z{ v }, w{ v } {}
		constexpr Ivec4(int a, int b, int c, int d) : x{ a }, y{ b }, z{ c }, w{ d } {}
		constexpr Ivec4(Ivec2 const& a, int b, int c) : x{ a.x }, y{ a.y }, z{ b }, w{ c } {}
		constexpr Ivec4(Ivec3 const& a, int b) : x{ a.x }, y{ a.y }, z{ a.z }, w{ b } {}

		_reflect() int x = 0, _reflect() y = 0, _reflect() z = 0, _reflect() w = 0;

		explicit constexpr operator Vec4() const;
	};

	constexpr Ivec2::Ivec2(Ivec3 const& v) : x{ v.x }, y{ v.y } {}
	constexpr Ivec2::Ivec2(Ivec4 const& v) : x{ v.x }, y{ v.y } {}
	constexpr Ivec3::Ivec3(Ivec2 const& a, int b) : x{ a.x }, y{ a.y }, z{ b } {}
	constexpr Ivec3::Ivec3(Ivec4 const& v) : x{ v.x }, y{ v.y }, z{ v.z } {}

	struct _reflect() Uvec2 {
		constexpr Uvec2() = default;
		constexpr Uvec2(unsigned int v) : x{ v }, y{ v } {}
		constexpr Uvec2(unsigned int a, unsigned int b) : x{ a }, y{ b } {}
		constexpr Uvec2(Uvec3 const& v);
		constexpr Uvec2(Uvec4 const& v);

		_reflect() unsigned int x = 0, _reflect() y = 0;
	};

	struct _reflect() Uvec3 {
		constexpr Uvec3() = default;
		constexpr Uvec3(unsigned int v) : x{ v }, y{ v }, z{ v } {}
		constexpr Uvec3(unsigned int a, unsigned int b, unsigned int c) : x{ a }, y{ b }, z{ c } {}
		constexpr Uvec3(Uvec2 const& a, unsigned int b);
		constexpr Uvec3(Uvec4 const& v);

		_reflect() unsigned int x = 0, _reflect() y = 0, _reflect() z = 0;
	};

	struct _reflect() Uvec4 {
		constexpr Uvec4() = default;
		constexpr Uvec4(unsigned int v) : x{ v }, y{ v }, z{ v }, w{ v } {}
		constexpr Uvec4(unsigned int a, unsigned int b, unsigned int c, unsigned int d) : x{ a }, y{ b }, z{ c }, w{ d } {}
		constexpr Uvec4(Uvec2 const& a, unsigned int b, unsigned int c) : x{ a.x }, y{ a.y }, z{ b }, w{ c } {}
		constexpr Uvec4(Uvec3 const& a, unsigned int b) : x{ a.x }, y{ a.y }, z{ a.z }, w{ b } {}

		_reflect() unsigned int x = 0, _reflect() y = 0, _reflect() z = 0, _reflect() w = 0;
	};

	constexpr Uvec2::Uvec2(Uvec3 const& v) : x{ v.x }, y{ v.y } {}
	constexpr Uvec2::Uvec2(Uvec4 const& v) : x{ v.x }, y{ v.y } {}
	constexpr Uvec3::Uvec3(Uvec2 const& a, unsigned int b) : x{ a.x }, y{ a.y }, z{ b } {}
	constexpr Uvec3::Uvec3(Uvec4 const& v) : x{ v.x }, y{ v.y }, z{ v.z } {}

	struct _reflect() Vec2 {
		constexpr Vec2() = default;
		constexpr Vec2(float a, float b) : x{ a }, y{ b } {}
		constexpr Vec2(float v) : Vec2{ v, v } {}
		constexpr Vec2(Vec3 const& v);
		constexpr Vec2(Vec4 const& v);

		explicit constexpr operator Ivec2() const;

		_reflect() float x = 0.0f, _reflect() y = 0.0f;
	};

	struct _reflect() Vec3 {
		constexpr Vec3() = default;
		constexpr Vec3(float a, float b, float c) : x{ a }, y{ b }, z{ c } {}
		constexpr Vec3(float v) : Vec3{ v, v, v } {}
		constexpr Vec3(Vec2 const& v, float a) : Vec3{ v.x, v.y, a } {}
		constexpr Vec3(Vec4 const& v);

		explicit constexpr operator Ivec3() const;

		_reflect() float x = 0.0f, _reflect() y = 0.0f, _reflect() z = 0.0f;
	};

	struct _reflect() Vec4 {
		constexpr Vec4() = default;
		constexpr Vec4(float a, float b, float c, float d) : x{ a }, y{ b }, z{ c }, w{ d } {}
		constexpr Vec4(float v) : Vec4{ v, v, v, v } {}
		constexpr Vec4(Vec2 const& v, float a, float b) : Vec4{ v.x, v.y, a, b } {}
		constexpr Vec4(Vec3 const& v, float a) : Vec4{ v.x, v.y, v.z, a } {}
		constexpr Vec4(Vec2 const& a, Vec2 const& b) : Vec4{ a.x, a.y, b.x, b.y } {}

		explicit constexpr operator Ivec4() const;

		_reflect() float x = 0.0f, _reflect() y = 0.0f, _reflect() z = 0.0f, _reflect() w = 0.0f;
	};

	constexpr Vec2::Vec2(Vec3 const& v) : Vec2{ v.x, v.y } {}
	constexpr Vec2::Vec2(Vec4 const& v) : Vec2{ v.x, v.y } {}
	constexpr Vec3::Vec3(Vec4 const& v) : Vec3{ v.x, v.y, v.z } {}

	constexpr bool operator==(const Ivec2& a, const Ivec2& b);
	constexpr bool operator==(const Ivec3& a, const Ivec3& b);
	constexpr bool operator==(const Ivec4& a, const Ivec4& b);
	constexpr bool operator==(const Vec2& a, const Vec2& b);
	constexpr bool operator==(const Vec3& a, const Vec3& b);
	constexpr bool operator==(const Vec4& a, const Vec4& b);

	constexpr bool operator!=(const Ivec2& a, const Ivec2& b);
	constexpr bool operator!=(const Ivec3& a, const Ivec3& b);
	constexpr bool operator!=(const Ivec4& a, const Ivec4& b);
	constexpr bool operator!=(const Vec2& a, const Vec2& b);
	constexpr bool operator!=(const Vec3& a, const Vec3& b);
	constexpr bool operator!=(const Vec4& a, const Vec4& b);

	constexpr Ivec2 operator-(const Ivec2& v);
	constexpr Ivec3 operator-(const Ivec3& v);
	constexpr Ivec4 operator-(const Ivec4& v);
	constexpr Vec2 operator-(const Vec2& v);
	constexpr Vec3 operator-(const Vec3& v);
	constexpr Vec4 operator-(const Vec4& v);

	constexpr Ivec2 operator+(const Ivec2& a, const Ivec2& b);
	constexpr Ivec3 operator+(const Ivec3& a, const Ivec3& b);
	constexpr Ivec4 operator+(const Ivec4& a, const Ivec4& b);
	constexpr Vec2 operator+(const Vec2& a, const Vec2& b);
	constexpr Vec3 operator+(const Vec3& a, const Vec3& b);
	constexpr Vec4 operator+(const Vec4& a, const Vec4& b);

	constexpr Ivec2 operator-(Ivec2 const& a, Ivec2 const& b) {
		return Ivec2{ a.x - b.x, a.y - b.y };
	}

	constexpr Ivec3 operator-(Ivec3 const& a, Ivec3 const& b) {
		return Ivec3{ a.x - b.x, a.y - b.y, a.z - b.z };
	}

	constexpr Ivec4 operator-(Ivec4 const& a, Ivec4 const& b) {
		return Ivec4{ a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
	}

	constexpr Vec2 operator-(const Vec2& a, const Vec2& b);
	constexpr Vec3 operator-(const Vec3& a, const Vec3& b);
	constexpr Vec4 operator-(const Vec4& a, const Vec4& b);

	constexpr Ivec2 operator*(const Ivec2& a, int b);
	constexpr Ivec3 operator*(const Ivec3& a, int b);
	constexpr Ivec4 operator*(const Ivec4& a, int b);
	constexpr Vec2 operator*(const Vec2& a, float b);
	constexpr Vec3 operator*(const Vec3& a, float b);
	constexpr Vec4 operator*(const Vec4& a, float b);
	constexpr Vec2 operator*(float b, const Vec2& a);
	constexpr Vec3 operator*(float b, const Vec3& a);
	constexpr Vec4 operator*(float b, const Vec4& a);

	constexpr Ivec2 operator*(const Ivec2& a, const Ivec2& b);
	constexpr Ivec3 operator*(const Ivec3& a, const Ivec3& b);
	constexpr Ivec4 operator*(const Ivec4& a, const Ivec4& b);
	constexpr Vec2 operator*(const Vec2& a, const Vec2& b);
	constexpr Vec3 operator*(const Vec3& a, const Vec3& b);
	constexpr Vec4 operator*(const Vec4& a, const Vec4& b);

	constexpr Ivec2 operator/(const Ivec2& a, int b);
	constexpr Ivec3 operator/(const Ivec3& a, int b);
	constexpr Ivec4 operator/(const Ivec4& a, int b);
	constexpr Vec2 operator/(const Vec2& a, float b);
	constexpr Vec3 operator/(const Vec3& a, float b);
	constexpr Vec4 operator/(const Vec4& a, float b);

	constexpr Ivec2 operator/(const Ivec2& a, const Ivec2& b);
	constexpr Ivec3 operator/(const Ivec3& a, const Ivec3& b);
	constexpr Ivec4 operator/(const Ivec4& a, const Ivec4& b);
	constexpr Vec2 operator/(const Vec2& a, const Vec2& b);
	constexpr Vec3 operator/(const Vec3& a, const Vec3& b);
	constexpr Vec4 operator/(const Vec4& a, const Vec4& b);

	constexpr Ivec2 operator&(const Ivec2& a, const Ivec2& b);
	constexpr Ivec3 operator&(const Ivec3& a, const Ivec3& b);
	constexpr Ivec4 operator&(const Ivec4& a, const Ivec4& b);

	constexpr Ivec2& operator+=(Ivec2& a, const Ivec2& b);
	constexpr Ivec3& operator+=(Ivec3& a, const Ivec3& b);
	constexpr Ivec4& operator+=(Ivec4& a, const Ivec4& b);
	constexpr Vec2& operator+=(Vec2& a, const Vec2& b);
	constexpr Vec3& operator+=(Vec3& a, const Vec3& b);
	constexpr Vec4& operator+=(Vec4& a, const Vec4& b);

	constexpr Ivec2& operator-=(Ivec2& a, const Ivec2& b);
	constexpr Ivec3& operator-=(Ivec3& a, const Ivec3& b);
	constexpr Ivec4& operator-=(Ivec4& a, const Ivec4& b);
	constexpr Vec2& operator-=(Vec2& a, const Vec2& b);
	constexpr Vec3& operator-=(Vec3& a, const Vec3& b);
	constexpr Vec4& operator-=(Vec4& a, const Vec4& b);

	constexpr Ivec2& operator*=(Ivec2& a, int b);
	constexpr Ivec3& operator*=(Ivec3& a, int b);
	constexpr Ivec4& operator*=(Ivec4& a, int b);
	constexpr Vec2& operator*=(Vec2& a, float b);
	constexpr Vec3& operator*=(Vec3& a, float b);
	constexpr Vec4& operator*=(Vec4& a, float b);

	constexpr Ivec2& operator*=(Ivec2& a, const Ivec2& b);
	constexpr Ivec3& operator*=(Ivec3& a, const Ivec3& b);
	constexpr Ivec4& operator*=(Ivec4& a, const Ivec4& b);
	constexpr Vec2& operator*=(Vec2& a, const Vec2& b);
	constexpr Vec3& operator*=(Vec3& a, const Vec3& b);
	constexpr Vec4& operator*=(Vec4& a, const Vec4& b);

	constexpr Ivec2& operator/=(Ivec2& a, int b);
	constexpr Ivec3& operator/=(Ivec3& a, int b);
	constexpr Ivec4& operator/=(Ivec4& a, int b);
	constexpr Vec2& operator/=(Vec2& a, float b);
	constexpr Vec3& operator/=(Vec3& a, float b);
	constexpr Vec4& operator/=(Vec4& a, float b);

	constexpr Ivec2& operator/=(Ivec2& a, const Ivec2& b);
	constexpr Ivec3& operator/=(Ivec3& a, const Ivec3& b);
	constexpr Ivec4& operator/=(Ivec4& a, const Ivec4& b);
	constexpr Vec2& operator/=(Vec2& a, const Vec2& b);
	constexpr Vec3& operator/=(Vec3& a, const Vec3& b);
	constexpr Vec4& operator/=(Vec4& a, const Vec4& b);

	Vec2 floor(const Vec2& v);
	Vec3 floor(const Vec3& v);
	Vec4 floor(const Vec4& v);

	Vec2 round(const Vec2& v);
	Vec3 round(const Vec3& v);
	Vec4 round(const Vec4& v);

	Vec2 ceil(const Vec2& v);
	Vec3 ceil(const Vec3& v);
	Vec4 ceil(const Vec4& v);

	constexpr Ivec2 abs(const Ivec2& v);
	constexpr Ivec3 abs(const Ivec3& v);
	constexpr Ivec4 abs(const Ivec4& v);
	constexpr Vec2 abs(const Vec2& v);
	constexpr Vec3 abs(const Vec3& v);
	constexpr Vec4 abs(const Vec4& v);

	constexpr Ivec2 min(const Ivec2& a, const Ivec2& b);
	constexpr Ivec3 min(const Ivec3& a, const Ivec3& b);
	constexpr Ivec4 min(const Ivec4& a, const Ivec4& b);
	constexpr Vec2 min(const Vec2& a, const Vec2& b);
	constexpr Vec3 min(const Vec3& a, const Vec3& b);
	constexpr Vec4 min(const Vec4& a, const Vec4& b);

	constexpr Ivec2 max(const Ivec2& a, const Ivec2& b);
	constexpr Ivec3 max(const Ivec3& a, const Ivec3& b);
	constexpr Ivec4 max(const Ivec4& a, const Ivec4& b);
	constexpr Vec2 max(const Vec2& a, const Vec2& b);
	constexpr Vec3 max(const Vec3& a, const Vec3& b);
	constexpr Vec4 max(const Vec4& a, const Vec4& b);

	float dot(const Vec2& a, const Vec2& b);
	float dot(const Vec3& a, const Vec3& b);
	float dot(const Vec4& a, const Vec4& b);

	int dot(const Ivec2& a, const Ivec2& b);
	int dot(const Ivec3& a, const Ivec3& b);
	int dot(const Ivec4& a, const Ivec4& b);

	float cross(const Vec2& a, const Vec2& b);
	Vec2 cross(float s, const Vec2& a);
	Vec2 cross(const Vec2& a, float s);
	Vec3 cross(const Vec3& a, const Vec3& b);

	Vec2 vector_triple(const Vec2& a, const Vec2& b, const Vec2& c);
	Vec3 vector_triple(const Vec3& a, const Vec3& b, const Vec3& c);

	float scalar_triple(const Vec3& a, const Vec3& b, const Vec3& c);

	float length(const Vec2& v);
	float length(const Vec3& v);
	float length(const Vec4& v);

	Vec2 normalize(const Vec2& v);
	Vec3 normalize(const Vec3& v);
	Vec4 normalize(const Vec4& v);

	Vec2 rotate(const Vec2 v, const float angle);
	Vec2 rotate(const Vec2 v, float const st, float const ct);

	Vec2 left(const Vec2 v);
	Vec2 right(const Vec2 v);

	Vec2 reflect(const Vec2 v, const Vec2 n);
	Vec3 reflect(const Vec3 v, const Vec3 n);

	bool refract(Vec3 *out, Vec3 const& v, Vec3 const& n, float ratio);

}

// Implementation
namespace oak {

	constexpr Ivec2::operator Vec2() const {
		return { static_cast<float>(x), static_cast<float>(y) };
	}

	constexpr Ivec3::operator Vec3() const {
		return { static_cast<float>(x), static_cast<float>(y), static_cast<float>(z) };
	}

	constexpr Ivec4::operator Vec4() const {
		return { static_cast<float>(x), static_cast<float>(y),
			static_cast<float>(z), static_cast<float>(w) };
	}

	constexpr Vec2::operator Ivec2() const {
		return { static_cast<int>(x), static_cast<int>(y) };
	}

	constexpr Vec3::operator Ivec3() const {
		return { static_cast<int>(x), static_cast<int>(y), static_cast<int>(z) };
	}

	constexpr Vec4::operator Ivec4() const {
		return { static_cast<int>(x), static_cast<int>(y), static_cast<int>(z), static_cast<int>(w) };
	}

	constexpr bool operator==(const Ivec2& a, const Ivec2& b) {
		return a.x == b.x && a.y == b.y;
	}

	constexpr bool operator==(const Ivec3& a, const Ivec3& b) {
		return a.x == b.x && a.y == b.y && a.z == b.z;
	}

	constexpr bool operator==(const Ivec4& a, const Ivec4& b) {
		return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
	}

	constexpr bool operator==(const Vec2& a, const Vec2& b) {
		return a.x == b.x && a.y == b.y;
	}

	constexpr bool operator==(const Vec3& a, const Vec3& b) {
		return a.x == b.x && a.y == b.y && a.z == b.z;
	}

	constexpr bool operator==(const Vec4& a, const Vec4& b) {
		return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
	}

	constexpr bool operator!=(const Ivec2& a, const Ivec2& b) {
		return a.x != b.x || a.y != b.y;
	}

	constexpr bool operator!=(const Ivec3& a, const Ivec3& b) {
		return a.x != b.x || a.y != b.y || a.z != b.z;
	}

	constexpr bool operator!=(const Ivec4& a, const Ivec4& b) {
		return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w;
	}

	constexpr bool operator!=(const Vec2& a, const Vec2& b) {
		return a.x != b.x || a.y != b.y;
	}

	constexpr bool operator!=(const Vec3& a, const Vec3& b) {
		return a.x != b.x || a.y != b.y || a.z != b.z;
	}

	constexpr bool operator!=(const Vec4& a, const Vec4& b) {
		return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w;
	}

	constexpr Vec2 operator-(const Vec2& v) {
		return Vec2{ -v.x, -v.y };
	}

	constexpr Vec3 operator-(const Vec3& v) {
		return Vec3{ -v.x, -v.y, -v.z };
	}

	constexpr Vec4 operator-(const Vec4& v) {
		return Vec4{ -v.x, -v.y, -v.z, -v.w };
	}

	constexpr Ivec2 operator+(const Ivec2& a, const Ivec2& b) {
		return Ivec2{ a.x + b.x, a.y + b.y };
	}

	constexpr Ivec3 operator+(const Ivec3& a, const Ivec3& b) {
		return Ivec3{ a.x + b.x, a.y + b.y, a.z + b.z };
	}

	constexpr Ivec4 operator+(const Ivec4& a, const Ivec4& b) {
		return Ivec4{ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
	}

	constexpr Vec2 operator+(const Vec2& a, const Vec2& b) {
		return Vec2{ a.x + b.x, a.y + b.y };
	}

	constexpr Vec3 operator+(const Vec3& a, const Vec3& b) {
		return Vec3{ a.x + b.x, a.y + b.y, a.z + b.z };
	}

	constexpr Vec4 operator+(const Vec4& a, const Vec4& b) {
		return Vec4{ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
	}

	constexpr Vec2 operator-(const Vec2& a, const Vec2& b) {
		return Vec2{ a.x - b.x, a.y - b.y };
	}

	constexpr Vec3 operator-(const Vec3& a, const Vec3& b) {
		return Vec3{ a.x - b.x, a.y - b.y, a.z - b.z };
	}

	constexpr Vec4 operator-(const Vec4& a, const Vec4& b) {
		return Vec4{ a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
	}

	constexpr Ivec2 operator*(const Ivec2& a, int b) {
		return Ivec2{ a.x * b, a.y * b };
	}

	constexpr Ivec3 operator*(const Ivec3& a, int b) {
		return Ivec3{ a.x * b, a.y * b, a.z * b };
	}

	constexpr Ivec4 operator*(const Ivec4& a, int b) {
		return Ivec4{ a.x * b, a.y * b, a.z * b, a.w * b };
	}

	constexpr Vec2 operator*(const Vec2& a, float b) {
		return Vec2{ a.x * b, a.y * b };
	}

	constexpr Vec3 operator*(const Vec3& a, float b) {
		return Vec3{ a.x * b, a.y * b, a.z * b };
	}

	constexpr Vec4 operator*(const Vec4& a, float b) {
		return Vec4{ a.x * b, a.y * b, a.z * b, a.w * b };
	}

	constexpr Vec2 operator*(float b, const Vec2& a) {
		return Vec2{ a.x * b, a.y * b };
	}

	constexpr Vec3 operator*(float b, const Vec3& a) {
		return Vec3{ a.x * b, a.y * b, a.z * b };
	}

	constexpr Vec4 operator*(float b, const Vec4& a) {
		return Vec4{ a.x * b, a.y * b, a.z * b, a.w * b };
	}

	constexpr Ivec2 operator*(const Ivec2& a, const Ivec2& b) {
		return Ivec2{ a.x * b.x, a.y * b.y };
	}

	constexpr Ivec3 operator*(const Ivec3& a, const Ivec3& b) {
		return Ivec3{ a.x * b.x, a.y * b.y, a.z * b.z };
	}

	constexpr Ivec4 operator*(const Ivec4& a, const Ivec4& b) {
		return Ivec4{ a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
	}

	constexpr Vec2 operator*(const Vec2& a, const Vec2& b) {
		return Vec2{ a.x * b.x, a.y * b.y };
	}

	constexpr Vec3 operator*(const Vec3& a, const Vec3& b) {
		return Vec3{ a.x * b.x, a.y * b.y, a.z * b.z };
	}

	constexpr Vec4 operator*(const Vec4& a, const Vec4& b) {
		return Vec4{ a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
	}

	constexpr Ivec2 operator/(const Ivec2& a, int b) {
		return Ivec2{ a.x / b, a.y / b };
	}

	constexpr Ivec3 operator/(const Ivec3& a, int b) {
		return Ivec3{ a.x / b, a.y / b, a.z / b };
	}

	constexpr Ivec4 operator/(const Ivec4& a, int b) {
		return Ivec4{ a.x / b, a.y / b, a.z / b, a.w / b };
	}

	constexpr Vec2 operator/(const Vec2& a, float b) {
		return Vec2{ a.x / b, a.y / b };
	}

	constexpr Vec3 operator/(const Vec3& a, float b) {
		return Vec3{ a.x / b, a.y / b, a.z / b };
	}

	constexpr Vec4 operator/(const Vec4& a, float b) {
		return Vec4{ a.x / b, a.y / b, a.z / b, a.w / b };
	}

	constexpr Ivec2 operator/(const Ivec2& a, const Ivec2& b) {
		return Ivec2{ a.x / b.x, a.y / b.y };
	}

	constexpr Ivec3 operator/(const Ivec3& a, const Ivec3& b) {
		return Ivec3{ a.x / b.x, a.y / b.y, a.z / b.z };
	}

	constexpr Ivec4 operator/(const Ivec4& a, const Ivec4& b) {
		return Ivec4{ a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
	}

	constexpr Vec2 operator/(const Vec2& a, const Vec2& b) {
		return Vec2{ a.x / b.x, a.y / b.y };
	}

	constexpr Vec3 operator/(const Vec3& a, const Vec3& b) {
		return Vec3{ a.x / b.x, a.y / b.y, a.z / b.z };
	}

	constexpr Vec4 operator/(const Vec4& a, const Vec4& b) {
		return Vec4{ a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
	}

	constexpr Ivec2 operator&(const Ivec2& a, const Ivec2& b) {
		return { a.x & b.x, a.y & b.y };
	}

	constexpr Ivec3 operator&(const Ivec3& a, const Ivec3& b) {
		return { a.x & b.x, a.y & b.y, a.z & b.z };
	}

	constexpr Ivec4 operator&(const Ivec4& a, const Ivec4& b) {
		return { a.x & b.x, a.y & b.y, a.z & b.z, a.w & b.w };
	}

	constexpr Ivec2& operator+=(Ivec2& a, const Ivec2& b) {
		a.x += b.x;
		a.y += b.y;
		return a;
	}

	constexpr Ivec3& operator+=(Ivec3& a, const Ivec3& b) {
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		return a;
	}

	constexpr Ivec4& operator+=(Ivec4& a, const Ivec4& b) {
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		a.w += b.w;
		return a;
	}

	constexpr Vec2& operator+=(Vec2& a, const Vec2& b) {
		a.x += b.x;
		a.y += b.y;
		return a;
	}

	constexpr Vec3& operator+=(Vec3& a, const Vec3& b) {
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		return a;
	}

	constexpr Vec4& operator+=(Vec4& a, const Vec4& b) {
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		a.w += b.w;
		return a;
	}

	constexpr Ivec2& operator-=(Ivec2& a, const Ivec2& b) {
		a.x -= b.x;
		a.y -= b.y;
		return a;
	}

	constexpr Ivec3& operator-=(Ivec3& a, const Ivec3& b) {
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
		return a;
	}

	constexpr Ivec4& operator-=(Ivec4& a, const Ivec4& b) {
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
		a.w -= b.w;
		return a;
	}

	constexpr Vec2& operator-=(Vec2& a, const Vec2& b) {
		a.x -= b.x;
		a.y -= b.y;
		return a;
	}

	constexpr Vec3& operator-=(Vec3& a, const Vec3& b) {
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
		return a;
	}

	constexpr Vec4& operator-=(Vec4& a, const Vec4& b) {
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
		a.w -= b.w;
		return a;
	}

	constexpr Ivec2& operator*=(Ivec2& a, int b) {
		a.x *= b;
		a.y *= b;
		return a;
	}

	constexpr Ivec3& operator*=(Ivec3& a, int b) {
		a.x *= b;
		a.y *= b;
		a.z *= b;
		return a;
	}

	constexpr Ivec4& operator*=(Ivec4& a, int b) {
		a.x *= b;
		a.y *= b;
		a.z *= b;
		a.w *= b;
		return a;
	}

	constexpr Vec2& operator*=(Vec2& a, float b) {
		a.x *= b;
		a.y *= b;
		return a;
	}

	constexpr Vec3& operator*=(Vec3& a, float b) {
		a.x *= b;
		a.y *= b;
		a.z *= b;
		return a;
	}

	constexpr Vec4& operator*=(Vec4& a, float b) {
		a.x *= b;
		a.y *= b;
		a.z *= b;
		a.w *= b;
		return a;
	}

	constexpr Ivec2& operator*=(Ivec2& a, const Ivec2& b) {
		a.x *= b.x;
		a.y *= b.y;
		return a;
	}

	constexpr Ivec3& operator*=(Ivec3& a, const Ivec3& b) {
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;
		return a;
	}

	constexpr Ivec4& operator*=(Ivec4& a, const Ivec4& b) {
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;
		a.w *= b.w;
		return a;
	}

	constexpr Vec2& operator*=(Vec2& a, const Vec2& b) {
		a.x *= b.x;
		a.y *= b.y;
		return a;
	}

	constexpr Vec3& operator*=(Vec3& a, const Vec3& b) {
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;
		return a;
	}

	constexpr Vec4& operator*=(Vec4& a, const Vec4& b) {
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;
		a.w *= b.w;
		return a;
	}

	constexpr Ivec2& operator/=(Ivec2& a, int b) {
		a.x /= b;
		a.y /= b;
		return a;
	}

	constexpr Ivec3& operator/=(Ivec3& a, int b) {
		a.x /= b;
		a.y /= b;
		a.z /= b;
		return a;
	}

	constexpr Ivec4& operator/=(Ivec4& a, int b) {
		a.x /= b;
		a.y /= b;
		a.z /= b;
		a.w /= b;
		return a;
	}

	constexpr Vec2& operator/=(Vec2& a, float b) {
		a.x /= b;
		a.y /= b;
		return a;
	}

	constexpr Vec3& operator/=(Vec3& a, float b) {
		a.x /= b;
		a.y /= b;
		a.z /= b;
		return a;
	}

	constexpr Vec4& operator/=(Vec4& a, float b) {
		a.x /= b;
		a.y /= b;
		a.z /= b;
		a.w /= b;
		return a;
	}

	constexpr Ivec2& operator/=(Ivec2& a, const Ivec2& b) {
		a.x /= b.x;
		a.y /= b.y;
		return a;
	}

	constexpr Ivec3& operator/=(Ivec3& a, const Ivec3& b) {
		a.x /= b.x;
		a.y /= b.y;
		a.z /= b.z;
		return a;
	}

	constexpr Ivec4& operator/=(Ivec4& a, const Ivec4& b) {
		a.x /= b.x;
		a.y /= b.y;
		a.z /= b.z;
		a.w /= b.w;
		return a;
	}

	constexpr Vec2& operator/=(Vec2& a, const Vec2& b) {
		a.x /= b.x;
		a.y /= b.y;
		return a;
	}

	constexpr Vec3& operator/=(Vec3& a, const Vec3& b) {
		a.x /= b.x;
		a.y /= b.y;
		a.z /= b.z;
		return a;
	}

	constexpr Vec4& operator/=(Vec4& a, const Vec4& b) {
		a.x /= b.x;
		a.y /= b.y;
		a.z /= b.z;
		a.w /= b.w;
		return a;
	}

	inline Vec2 floor(const Vec2& v) {
		return { floor(v.x), floor(v.y) };
	}

	inline Vec3 floor(const Vec3& v) {
		return { floor(v.x), floor(v.y), floor(v.z) };
	}

	inline Vec4 floor(const Vec4& v) {
		return { floor(v.x), floor(v.y), floor(v.z), floor(v.w) };
	}

	inline Vec2 round(const Vec2& v) {
		return { round(v.x), round(v.y) };
	}

	inline Vec3 round(const Vec3& v) {
		return { round(v.x), round(v.y), round(v.z) };
	}

	inline Vec4 round(const Vec4& v) {
		return { round(v.x), round(v.y), round(v.z), round(v.w) };
	}

	inline Vec2 ceil(const Vec2& v) {
		return { ceil(v.x), ceil(v.y) };
	}

	inline Vec3 ceil(const Vec3& v) {
		return { ceil(v.x), ceil(v.y), ceil(v.z) };
	}

	inline Vec4 ceil(const Vec4& v) {
		return { ceil(v.x), ceil(v.y), ceil(v.z), ceil(v.w) };
	}

	constexpr Ivec2 abs(const Ivec2& v) {
		return { abs(v.x), abs(v.y) };
	}

	constexpr Ivec3 abs(const Ivec3& v) {
		return { abs(v.x), abs(v.y), abs(v.z) };
	}

	constexpr Ivec4 abs(const Ivec4& v) {
		return { abs(v.x), abs(v.y), abs(v.z), abs(v.w) };
	}

	constexpr Vec2 abs(const Vec2& v) {
		return { abs(v.x), abs(v.y) };
	}

	constexpr Vec3 abs(const Vec3& v) {
		return { abs(v.x), abs(v.y), abs(v.z) };
	}

	constexpr Vec4 abs(const Vec4& v) {
		return { abs(v.x), abs(v.y), abs(v.z), abs(v.w) };
	}

	constexpr Ivec2 min(const Ivec2& a, const Ivec2& b) {
		return { min(a.x, b.x), min(a.y, b.y) };
	}

	constexpr Ivec3 min(const Ivec3& a, const Ivec3& b) {
		return { min(a.x, b.x), min(a.y, b.y), min(a.z, b.z) };
	}

	constexpr Ivec4 min(const Ivec4& a, const Ivec4& b) {
		return { min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w) };
	}

	constexpr Vec2 min(const Vec2& a, const Vec2& b) {
		return { min(a.x, b.x), min(a.y, b.y) };
	}

	constexpr Vec3 min(const Vec3& a, const Vec3& b) {
		return { min(a.x, b.x), min(a.y, b.y), min(a.z, b.z) };
	}

	constexpr Vec4 min(const Vec4& a, const Vec4& b) {
		return { min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w) };
	}

	constexpr Ivec2 max(const Ivec2& a, const Ivec2& b) {
		return { max(a.x, b.x), max(a.y, b.y) };
	}

	constexpr Ivec3 max(const Ivec3& a, const Ivec3& b) {
		return { max(a.x, b.x), max(a.y, b.y), max(a.z, b.z) };
	}

	constexpr Ivec4 max(const Ivec4& a, const Ivec4& b) {
		return { max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w) };
	}

	constexpr Vec2 max(const Vec2& a, const Vec2& b) {
		return { max(a.x, b.x), max(a.y, b.y) };
	}

	constexpr Vec3 max(const Vec3& a, const Vec3& b) {
		return { max(a.x, b.x), max(a.y, b.y), max(a.z, b.z) };
	}

	constexpr Vec4 max(const Vec4& a, const Vec4& b) {
		return { max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w) };
	}

	inline float dot(const Vec2& a, const Vec2& b) {
		return (a.x * b.x) + (a.y * b.y);
	}

	inline float dot(const Vec3& a, const Vec3& b) {
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	}

	inline float dot(const Vec4& a, const Vec4& b) {
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
	}

	inline int dot(const Ivec2& a, const Ivec2& b) {
		return (a.x * b.x) + (a.y * b.y);
	}

	inline int dot(const Ivec3& a, const Ivec3& b) {
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	}

	inline int dot(const Ivec4& a, const Ivec4& b) {
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
	}

	inline float cross(const Vec2& a, const Vec2& b) {
		return a.x * b.y - a.y * b.x;
	}

	inline Vec2 cross(float s, const Vec2& a) {
		return { -s * a.y, s * a.x };
	}

	inline Vec2 cross(const Vec2& a, float s) {
		return { s * a.y, -s * a.x };
	}

	inline Vec3 cross(const Vec3& a, const Vec3& b) {
		return Vec3{
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		};
	}

	inline Vec2 vector_triple(const Vec2& a, const Vec2& b, const Vec2& c) {
		return b * dot(c, a) - a * dot(c, b);
	}

	inline Vec3 vector_triple(const Vec3& a, const Vec3& b, const Vec3& c) {
		return cross(a, cross(b, c));
	}

	inline float scalar_triple(const Vec3& a, const Vec3& b, const Vec3& c) {
		return dot(cross(a, b), c);
	}

	inline float length(const Vec2& v) {
		return sqrt(v.x * v.x + v.y * v.y);
	}

	inline float length(const Vec3& v) {
		return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	}

	inline float length(const Vec4& v) {
		return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
	}

	inline Vec2 normalize(const Vec2& v) {
		auto l = length(v);
		return l == 0.0f ? v : v / l;
	}

	inline Vec3 normalize(const Vec3& v) {
		auto l = length(v);
		return l == 0.0f ? v : v / l;
	}

	inline Vec4 normalize(const Vec4& v) {
		auto l = length(v);
		return l == 0.0f ? v : v / l;
	}

	inline Vec2 rotate(const Vec2 v, const float angle) {
		const auto ct = cos(angle);
		const auto st = sin(angle);
		return { v.x * ct - v.y * st, v.x * st + v.y * ct };
	}

	inline Vec2 rotate(const Vec2 v, float const st, float const ct) {
		return { v.x * ct - v.y * st, v.x * st + v.y * ct };
	}

	inline Vec2 left(const Vec2 v) {
		return { -v.y, v.x };
	}

	inline Vec2 right(const Vec2 v) {
		return { v.y, -v.x };
	}

	inline Vec2 reflect(const Vec2 v, const Vec2 n) {
		return v - 2.f * dot(v, n) * n;
	}

	inline Vec3 reflect(const Vec3 v, const Vec3 n) {
		return v - 2.f * dot(v, n) * n;
	}

	inline bool refract(Vec3 *out, Vec3 const& v, Vec3 const& n, float ratio) {
		auto uv = normalize(v);
		float dt = dot(uv, n);
		float descr = 1.f - ratio*ratio*(1.f - dt*dt);

		if (descr < 0.f)
			return false;

		*out = ratio*(uv - n*dt) - n*sqrt(descr);
		return true;
	}

}

