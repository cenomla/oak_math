#define OAK_MATH_EXPORT_SYMBOLS

#include <oak_math/vec.h>

#include <oak_math/func.h>
#include <oak_math/mat.h>

namespace oak {

	Ivec2::operator Vec2() const {
		return { static_cast<float>(x), static_cast<float>(y) };
	}

	Ivec3::operator Vec3() const {
		return { static_cast<float>(x), static_cast<float>(y), static_cast<float>(z) };
	}

	Ivec4::operator Vec4() const {
		return { static_cast<float>(x), static_cast<float>(y),
			static_cast<float>(z), static_cast<float>(w) };
	}

	Vec2::operator Ivec2() const {
		return { static_cast<int>(x), static_cast<int>(y) };
	}

	Vec3::operator Ivec3() const {
		return { static_cast<int>(x), static_cast<int>(y), static_cast<int>(z) };
	}

	Vec4::operator Ivec4() const {
		return { static_cast<int>(x), static_cast<int>(y), static_cast<int>(z), static_cast<int>(w) };
	}

	bool operator==(const Ivec2& a, const Ivec2& b) {
		return a.x == b.x && a.y == b.y;
	}

	bool operator==(const Ivec3& a, const Ivec3& b) {
		return a.x == b.x && a.y == b.y && a.z == b.z;
	}

	bool operator==(const Ivec4& a, const Ivec4& b) {
		return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
	}

	bool operator==(const Vec2& a, const Vec2& b) {
		return a.x == b.x && a.y == b.y;
	}

	bool operator==(const Vec3& a, const Vec3& b) {
		return a.x == b.x && a.y == b.y && a.z == b.z;
	}

	bool operator==(const Vec4& a, const Vec4& b) {
		return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
	}

	bool operator!=(const Ivec2& a, const Ivec2& b) {
		return a.x != b.x || a.y != b.y;
	}

	bool operator!=(const Ivec3& a, const Ivec3& b) {
		return a.x != b.x || a.y != b.y || a.z != b.z;
	}

	bool operator!=(const Ivec4& a, const Ivec4& b) {
		return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w;
	}

	bool operator!=(const Vec2& a, const Vec2& b) {
		return a.x != b.x || a.y != b.y;
	}

	bool operator!=(const Vec3& a, const Vec3& b) {
		return a.x != b.x || a.y != b.y || a.z != b.z;
	}

	bool operator!=(const Vec4& a, const Vec4& b) {
		return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w;
	}

	Vec2 operator-(const Vec2& v) {
		return Vec2{ -v.x, -v.y };
	}

	Vec3 operator-(const Vec3& v) {
		return Vec3{ -v.x, -v.y, -v.z };
	}

	Vec4 operator-(const Vec4& v) {
		return Vec4{ -v.x, -v.y, -v.z, -v.w };
	}

	Ivec2 operator+(const Ivec2& a, const Ivec2& b) {
		return Ivec2{ a.x + b.x, a.y + b.y };
	}

	Ivec3 operator+(const Ivec3& a, const Ivec3& b) {
		return Ivec3{ a.x + b.x, a.y + b.y, a.z + b.z };
	}

	Ivec4 operator+(const Ivec4& a, const Ivec4& b) {
		return Ivec4{ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
	}

	Vec2 operator+(const Vec2& a, const Vec2& b) {
		return Vec2{ a.x + b.x, a.y + b.y };
	}

	Vec3 operator+(const Vec3& a, const Vec3& b) {
		return Vec3{ a.x + b.x, a.y + b.y, a.z + b.z };
	}

	Vec4 operator+(const Vec4& a, const Vec4& b) {
		return Vec4{ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
	}

	Vec2 operator-(const Vec2& a, const Vec2& b) {
		return Vec2{ a.x - b.x, a.y - b.y };
	}

	Vec3 operator-(const Vec3& a, const Vec3& b) {
		return Vec3{ a.x - b.x, a.y - b.y, a.z - b.z };
	}

	Vec4 operator-(const Vec4& a, const Vec4& b) {
		return Vec4{ a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
	}

	Ivec2 operator*(const Ivec2& a, int b) {
		return Ivec2{ a.x * b, a.y * b };
	}

	Ivec3 operator*(const Ivec3& a, int b) {
		return Ivec3{ a.x * b, a.y * b, a.z * b };
	}

	Ivec4 operator*(const Ivec4& a, int b) {
		return Ivec4{ a.x * b, a.y * b, a.z * b, a.w * b };
	}

	Vec2 operator*(const Vec2& a, float b) {
		return Vec2{ a.x * b, a.y * b };
	}

	Vec3 operator*(const Vec3& a, float b) {
		return Vec3{ a.x * b, a.y * b, a.z * b };
	}

	Vec4 operator*(const Vec4& a, float b) {
		return Vec4{ a.x * b, a.y * b, a.z * b, a.w * b };
	}

	Vec2 operator*(float b, const Vec2& a) {
		return Vec2{ a.x * b, a.y * b };
	}

	Vec3 operator*(float b, const Vec3& a) {
		return Vec3{ a.x * b, a.y * b, a.z * b };
	}

	Vec4 operator*(float b, const Vec4& a) {
		return Vec4{ a.x * b, a.y * b, a.z * b, a.w * b };
	}

	Ivec2 operator*(const Ivec2& a, const Ivec2& b) {
		return Ivec2{ a.x * b.x, a.y * b.y };
	}

	Ivec3 operator*(const Ivec3& a, const Ivec3& b) {
		return Ivec3{ a.x * b.x, a.y * b.y, a.z * b.z };
	}

	Ivec4 operator*(const Ivec4& a, const Ivec4& b) {
		return Ivec4{ a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
	}

	Vec2 operator*(const Vec2& a, const Vec2& b) {
		return Vec2{ a.x * b.x, a.y * b.y };
	}

	Vec3 operator*(const Vec3& a, const Vec3& b) {
		return Vec3{ a.x * b.x, a.y * b.y, a.z * b.z };
	}

	Vec4 operator*(const Vec4& a, const Vec4& b) {
		return Vec4{ a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
	}

	Ivec2 operator/(const Ivec2& a, int b) {
		return Ivec2{ a.x / b, a.y / b };
	}

	Ivec3 operator/(const Ivec3& a, int b) {
		return Ivec3{ a.x / b, a.y / b, a.z / b };
	}

	Ivec4 operator/(const Ivec4& a, int b) {
		return Ivec4{ a.x / b, a.y / b, a.z / b, a.w / b };
	}

	Vec2 operator/(const Vec2& a, float b) {
		return Vec2{ a.x / b, a.y / b };
	}

	Vec3 operator/(const Vec3& a, float b) {
		return Vec3{ a.x / b, a.y / b, a.z / b };
	}

	Vec4 operator/(const Vec4& a, float b) {
		return Vec4{ a.x / b, a.y / b, a.z / b, a.w / b };
	}

	Ivec2 operator/(const Ivec2& a, const Ivec2& b) {
		return Ivec2{ a.x / b.x, a.y / b.y };
	}

	Ivec3 operator/(const Ivec3& a, const Ivec3& b) {
		return Ivec3{ a.x / b.x, a.y / b.y, a.z / b.z };
	}

	Ivec4 operator/(const Ivec4& a, const Ivec4& b) {
		return Ivec4{ a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
	}

	Vec2 operator/(const Vec2& a, const Vec2& b) {
		return Vec2{ a.x / b.x, a.y / b.y };
	}

	Vec3 operator/(const Vec3& a, const Vec3& b) {
		return Vec3{ a.x / b.x, a.y / b.y, a.z / b.z };
	}

	Vec4 operator/(const Vec4& a, const Vec4& b) {
		return Vec4{ a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
	}

	Ivec2& operator+=(Ivec2& a, const Ivec2& b) {
		a.x += b.x;
		a.y += b.y;
		return a;
	}

	Ivec3& operator+=(Ivec3& a, const Ivec3& b) {
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		return a;
	}

	Ivec4& operator+=(Ivec4& a, const Ivec4& b) {
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		a.w += b.w;
		return a;
	}

	Vec2& operator+=(Vec2& a, const Vec2& b) {
		a.x += b.x;
		a.y += b.y;
		return a;
	}

	Vec3& operator+=(Vec3& a, const Vec3& b) {
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		return a;
	}

	Vec4& operator+=(Vec4& a, const Vec4& b) {
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		a.w += b.w;
		return a;
	}

	Ivec2& operator-=(Ivec2& a, const Ivec2& b) {
		a.x -= b.x;
		a.y -= b.y;
		return a;
	}

	Ivec3& operator-=(Ivec3& a, const Ivec3& b) {
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
		return a;
	}

	Ivec4& operator-=(Ivec4& a, const Ivec4& b) {
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
		a.w -= b.w;
		return a;
	}

	Vec2& operator-=(Vec2& a, const Vec2& b) {
		a.x -= b.x;
		a.y -= b.y;
		return a;
	}

	Vec3& operator-=(Vec3& a, const Vec3& b) {
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
		return a;
	}

	Vec4& operator-=(Vec4& a, const Vec4& b) {
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
		a.w -= b.w;
		return a;
	}

	Ivec2& operator*=(Ivec2& a, int b) {
		a.x *= b;
		a.y *= b;
		return a;
	}

	Ivec3& operator*=(Ivec3& a, int b) {
		a.x *= b;
		a.y *= b;
		a.z *= b;
		return a;
	}

	Ivec4& operator*=(Ivec4& a, int b) {
		a.x *= b;
		a.y *= b;
		a.z *= b;
		a.w *= b;
		return a;
	}

	Vec2& operator*=(Vec2& a, float b) {
		a.x *= b;
		a.y *= b;
		return a;
	}

	Vec3& operator*=(Vec3& a, float b) {
		a.x *= b;
		a.y *= b;
		a.z *= b;
		return a;
	}

	Vec4& operator*=(Vec4& a, float b) {
		a.x *= b;
		a.y *= b;
		a.z *= b;
		a.w *= b;
		return a;
	}

	Ivec2& operator*=(Ivec2& a, const Ivec2& b) {
		a.x *= b.x;
		a.y *= b.y;
		return a;
	}

	Ivec3& operator*=(Ivec3& a, const Ivec3& b) {
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;
		return a;
	}

	Ivec4& operator*=(Ivec4& a, const Ivec4& b) {
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;
		a.w *= b.w;
		return a;
	}

	Vec2& operator*=(Vec2& a, const Vec2& b) {
		a.x *= b.x;
		a.y *= b.y;
		return a;
	}

	Vec3& operator*=(Vec3& a, const Vec3& b) {
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;
		return a;
	}

	Vec4& operator*=(Vec4& a, const Vec4& b) {
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;
		a.w *= b.w;
		return a;
	}

	Ivec2& operator/=(Ivec2& a, int b) {
		a.x /= b;
		a.y /= b;
		return a;
	}

	Ivec3& operator/=(Ivec3& a, int b) {
		a.x /= b;
		a.y /= b;
		a.z /= b;
		return a;
	}

	Ivec4& operator/=(Ivec4& a, int b) {
		a.x /= b;
		a.y /= b;
		a.z /= b;
		a.w /= b;
		return a;
	}

	Vec2& operator/=(Vec2& a, float b) {
		a.x /= b;
		a.y /= b;
		return a;
	}

	Vec3& operator/=(Vec3& a, float b) {
		a.x /= b;
		a.y /= b;
		a.z /= b;
		return a;
	}

	Vec4& operator/=(Vec4& a, float b) {
		a.x /= b;
		a.y /= b;
		a.z /= b;
		a.w /= b;
		return a;
	}

	Ivec2& operator/=(Ivec2& a, const Ivec2& b) {
		a.x /= b.x;
		a.y /= b.y;
		return a;
	}

	Ivec3& operator/=(Ivec3& a, const Ivec3& b) {
		a.x /= b.x;
		a.y /= b.y;
		a.z /= b.z;
		return a;
	}

	Ivec4& operator/=(Ivec4& a, const Ivec4& b) {
		a.x /= b.x;
		a.y /= b.y;
		a.z /= b.z;
		a.w /= b.w;
		return a;
	}

	Vec2& operator/=(Vec2& a, const Vec2& b) {
		a.x /= b.x;
		a.y /= b.y;
		return a;
	}

	Vec3& operator/=(Vec3& a, const Vec3& b) {
		a.x /= b.x;
		a.y /= b.y;
		a.z /= b.z;
		return a;
	}

	Vec4& operator/=(Vec4& a, const Vec4& b) {
		a.x /= b.x;
		a.y /= b.y;
		a.z /= b.z;
		a.w /= b.w;
		return a;
	}

	Vec2 floor(const Vec2& v) {
		return { floor(v.x), floor(v.y) };
	}

	Vec3 floor(const Vec3& v) {
		return { floor(v.x), floor(v.y), floor(v.z) };
	}

	Vec4 floor(const Vec4& v) {
		return { floor(v.x), floor(v.y), floor(v.z), floor(v.w) };
	}

	Vec2 round(const Vec2& v) {
		return { round(v.x), round(v.y) };
	}

	Vec3 round(const Vec3& v) {
		return { round(v.x), round(v.y), round(v.z) };
	}

	Vec4 round(const Vec4& v) {
		return { round(v.x), round(v.y), round(v.z), round(v.w) };
	}

	Vec2 ceil(const Vec2& v) {
		return { ceil(v.x), ceil(v.y) };
	}

	Vec3 ceil(const Vec3& v) {
		return { ceil(v.x), ceil(v.y), ceil(v.z) };
	}

	Vec4 ceil(const Vec4& v) {
		return { ceil(v.x), ceil(v.y), ceil(v.z), ceil(v.w) };
	}

	Ivec2 abs(const Ivec2& v) {
		return { abs(v.x), abs(v.y) };
	}

	Ivec3 abs(const Ivec3& v) {
		return { abs(v.x), abs(v.y), abs(v.z) };
	}

	Ivec4 abs(const Ivec4& v) {
		return { abs(v.x), abs(v.y), abs(v.z), abs(v.w) };
	}

	Vec2 abs(const Vec2& v) {
		return { abs(v.x), abs(v.y) };
	}

	Vec3 abs(const Vec3& v) {
		return { abs(v.x), abs(v.y), abs(v.z) };
	}

	Vec4 abs(const Vec4& v) {
		return { abs(v.x), abs(v.y), abs(v.z), abs(v.w) };
	}

	Ivec2 min(const Ivec2& a, const Ivec2& b) {
		return { min(a.x, b.x), min(a.y, b.y) };
	}

	Ivec3 min(const Ivec3& a, const Ivec3& b) {
		return { min(a.x, b.x), min(a.y, b.y), min(a.z, b.z) };
	}

	Ivec4 min(const Ivec4& a, const Ivec4& b) {
		return { min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w) };
	}

	Vec2 min(const Vec2& a, const Vec2& b) {
		return { min(a.x, b.x), min(a.y, b.y) };
	}

	Vec3 min(const Vec3& a, const Vec3& b) {
		return { min(a.x, b.x), min(a.y, b.y), min(a.z, b.z) };
	}

	Vec4 min(const Vec4& a, const Vec4& b) {
		return { min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w) };
	}

	Ivec2 max(const Ivec2& a, const Ivec2& b) {
		return { max(a.x, b.x), max(a.y, b.y) };
	}

	Ivec3 max(const Ivec3& a, const Ivec3& b) {
		return { max(a.x, b.x), max(a.y, b.y), max(a.z, b.z) };
	}

	Ivec4 max(const Ivec4& a, const Ivec4& b) {
		return { max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w) };
	}

	Vec2 max(const Vec2& a, const Vec2& b) {
		return { max(a.x, b.x), max(a.y, b.y) };
	}

	Vec3 max(const Vec3& a, const Vec3& b) {
		return { max(a.x, b.x), max(a.y, b.y), max(a.z, b.z) };
	}

	Vec4 max(const Vec4& a, const Vec4& b) {
		return { max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w) };
	}

	float dot(const Vec2& a, const Vec2& b) {
		return (a.x * b.x) + (a.y * b.y);
	}

	float dot(const Vec3& a, const Vec3& b) {
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	}

	float dot(const Vec4& a, const Vec4& b) {
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
	}

	Mat2 outerProduct(const Vec2& a, const Vec2& b) {
		return Mat2 {
			a * b.x,
			a * b.y
		};
	}

	Mat3 outerProduct(const Vec3& a, const Vec3& b) {
		return Mat3 {
			a * b.x,
			a * b.y,
			a * b.z
		};
	}

	Mat4 outerProduct(const Vec4& a, const Vec4& b) {
		return Mat4 {
			a * b.x,
			a * b.y,
			a * b.z,
			a * b.w
		};
	}

	float cross(const Vec2& a, const Vec2& b) {
		return a.x * b.y - a.y * b.x;
	}

	Vec2 cross(float s, const Vec2& a) {
		return { -s * a.y, s * a.x };
	}

	Vec2 cross(const Vec2& a, float s) {
		return { s * a.y, -s * a.x };
	}

	Vec3 cross(const Vec3& a, const Vec3& b) {
		return Vec3{
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		};
	}

	Vec2 vectorTriple(const Vec2& a, const Vec2& b, const Vec2& c) {
		return b * dot(c, a) - a * dot(c, b);
	}

	Vec3 vectorTriple(const Vec3& a, const Vec3& b, const Vec3& c) {
		return cross(a, cross(b, c));
	}

	float scalarTriple(const Vec3& a, const Vec3& b, const Vec3& c) {
		return dot(cross(a, b), c);
	}

	float length(const Vec2& v) {
		return sqrt(v.x * v.x + v.y * v.y);
	}

	float length(const Vec3& v) {
		return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	}

	float length(const Vec4& v) {
		return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
	}

	Vec2 normalize(const Vec2& v) {
		auto l = length(v);
		return l == 0.0f ? v : v / l;
	}

	Vec3 normalize(const Vec3& v) {
		auto l = length(v);
		return l == 0.0f ? v : v / l;
	}

	Vec4 normalize(const Vec4& v) {
		auto l = length(v);
		return l == 0.0f ? v : v / l;
	}

	Vec2 rotate(const Vec2 v, const float angle) {
		const auto ct = cos(angle);
		const auto st = sin(angle);
		return { v.x * ct - v.y * st, v.x * st + v.y * ct };
	}

	Vec2 rotate(const Vec2 v, float const st, float const ct) {
		return { v.x * ct - v.y * st, v.x * st + v.y * ct };
	}

	Vec2 left(const Vec2 v) {
		return { -v.y, v.x };
	}

	Vec2 right(const Vec2 v) {
		return { v.y, -v.x };
	}

	Vec2 reflect(const Vec2 v, const Vec2 n) {
		return v - 2.f * dot(v, n) * n;
	}

	Vec3 reflect(const Vec3 v, const Vec3 n) {
		return v - 2.f * dot(v, n) * n;
	}

	bool refract(Vec3 *out, Vec3 const& v, Vec3 const& n, float ratio) {
		auto uv = normalize(v);
		float dt = dot(uv, n);
		float descr = 1.f - ratio*ratio*(1.f - dt*dt);

		if (descr < 0.f)
			return false;

		*out = ratio*(uv - n*dt) - n*sqrt(descr);
		return true;
	}

}

