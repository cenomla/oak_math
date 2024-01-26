namespace oak {

	inline Ivec2::operator Vec2() const {
		return { static_cast<float>(x), static_cast<float>(y) };
	}

	inline Ivec3::operator Vec3() const {
		return { static_cast<float>(x), static_cast<float>(y), static_cast<float>(z) };
	}

	inline Ivec4::operator Vec4() const {
		return { static_cast<float>(x), static_cast<float>(y),
			static_cast<float>(z), static_cast<float>(w) };
	}

	inline Vec2::operator Ivec2() const {
		return { static_cast<int>(x), static_cast<int>(y) };
	}

	inline Vec3::operator Ivec3() const {
		return { static_cast<int>(x), static_cast<int>(y), static_cast<int>(z) };
	}

	inline Vec4::operator Ivec4() const {
		return { static_cast<int>(x), static_cast<int>(y), static_cast<int>(z), static_cast<int>(w) };
	}

	inline bool operator==(const Ivec2& a, const Ivec2& b) {
		return a.x == b.x && a.y == b.y;
	}

	inline bool operator==(const Ivec3& a, const Ivec3& b) {
		return a.x == b.x && a.y == b.y && a.z == b.z;
	}

	inline bool operator==(const Ivec4& a, const Ivec4& b) {
		return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
	}

	inline bool operator==(const Vec2& a, const Vec2& b) {
		return a.x == b.x && a.y == b.y;
	}

	inline bool operator==(const Vec3& a, const Vec3& b) {
		return a.x == b.x && a.y == b.y && a.z == b.z;
	}

	inline bool operator==(const Vec4& a, const Vec4& b) {
		return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
	}

	inline bool operator!=(const Ivec2& a, const Ivec2& b) {
		return a.x != b.x || a.y != b.y;
	}

	inline bool operator!=(const Ivec3& a, const Ivec3& b) {
		return a.x != b.x || a.y != b.y || a.z != b.z;
	}

	inline bool operator!=(const Ivec4& a, const Ivec4& b) {
		return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w;
	}

	inline bool operator!=(const Vec2& a, const Vec2& b) {
		return a.x != b.x || a.y != b.y;
	}

	inline bool operator!=(const Vec3& a, const Vec3& b) {
		return a.x != b.x || a.y != b.y || a.z != b.z;
	}

	inline bool operator!=(const Vec4& a, const Vec4& b) {
		return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w;
	}

	inline Vec2 operator-(const Vec2& v) {
		return Vec2{ -v.x, -v.y };
	}

	inline Vec3 operator-(const Vec3& v) {
		return Vec3{ -v.x, -v.y, -v.z };
	}

	inline Vec4 operator-(const Vec4& v) {
		return Vec4{ -v.x, -v.y, -v.z, -v.w };
	}

	inline Ivec2 operator+(const Ivec2& a, const Ivec2& b) {
		return Ivec2{ a.x + b.x, a.y + b.y };
	}

	inline Ivec3 operator+(const Ivec3& a, const Ivec3& b) {
		return Ivec3{ a.x + b.x, a.y + b.y, a.z + b.z };
	}

	inline Ivec4 operator+(const Ivec4& a, const Ivec4& b) {
		return Ivec4{ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
	}

	inline Vec2 operator+(const Vec2& a, const Vec2& b) {
		return Vec2{ a.x + b.x, a.y + b.y };
	}

	inline Vec3 operator+(const Vec3& a, const Vec3& b) {
		return Vec3{ a.x + b.x, a.y + b.y, a.z + b.z };
	}

	inline Vec4 operator+(const Vec4& a, const Vec4& b) {
		return Vec4{ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
	}

	inline Vec2 operator-(const Vec2& a, const Vec2& b) {
		return Vec2{ a.x - b.x, a.y - b.y };
	}

	inline Vec3 operator-(const Vec3& a, const Vec3& b) {
		return Vec3{ a.x - b.x, a.y - b.y, a.z - b.z };
	}

	inline Vec4 operator-(const Vec4& a, const Vec4& b) {
		return Vec4{ a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
	}

	inline Ivec2 operator*(const Ivec2& a, int b) {
		return Ivec2{ a.x * b, a.y * b };
	}

	inline Ivec3 operator*(const Ivec3& a, int b) {
		return Ivec3{ a.x * b, a.y * b, a.z * b };
	}

	inline Ivec4 operator*(const Ivec4& a, int b) {
		return Ivec4{ a.x * b, a.y * b, a.z * b, a.w * b };
	}

	inline Vec2 operator*(const Vec2& a, float b) {
		return Vec2{ a.x * b, a.y * b };
	}

	inline Vec3 operator*(const Vec3& a, float b) {
		return Vec3{ a.x * b, a.y * b, a.z * b };
	}

	inline Vec4 operator*(const Vec4& a, float b) {
		return Vec4{ a.x * b, a.y * b, a.z * b, a.w * b };
	}

	inline Vec2 operator*(float b, const Vec2& a) {
		return Vec2{ a.x * b, a.y * b };
	}

	inline Vec3 operator*(float b, const Vec3& a) {
		return Vec3{ a.x * b, a.y * b, a.z * b };
	}

	inline Vec4 operator*(float b, const Vec4& a) {
		return Vec4{ a.x * b, a.y * b, a.z * b, a.w * b };
	}

	inline Ivec2 operator*(const Ivec2& a, const Ivec2& b) {
		return Ivec2{ a.x * b.x, a.y * b.y };
	}

	inline Ivec3 operator*(const Ivec3& a, const Ivec3& b) {
		return Ivec3{ a.x * b.x, a.y * b.y, a.z * b.z };
	}

	inline Ivec4 operator*(const Ivec4& a, const Ivec4& b) {
		return Ivec4{ a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
	}

	inline Vec2 operator*(const Vec2& a, const Vec2& b) {
		return Vec2{ a.x * b.x, a.y * b.y };
	}

	inline Vec3 operator*(const Vec3& a, const Vec3& b) {
		return Vec3{ a.x * b.x, a.y * b.y, a.z * b.z };
	}

	inline Vec4 operator*(const Vec4& a, const Vec4& b) {
		return Vec4{ a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
	}

	inline Ivec2 operator/(const Ivec2& a, int b) {
		return Ivec2{ a.x / b, a.y / b };
	}

	inline Ivec3 operator/(const Ivec3& a, int b) {
		return Ivec3{ a.x / b, a.y / b, a.z / b };
	}

	inline Ivec4 operator/(const Ivec4& a, int b) {
		return Ivec4{ a.x / b, a.y / b, a.z / b, a.w / b };
	}

	inline Vec2 operator/(const Vec2& a, float b) {
		return Vec2{ a.x / b, a.y / b };
	}

	inline Vec3 operator/(const Vec3& a, float b) {
		return Vec3{ a.x / b, a.y / b, a.z / b };
	}

	inline Vec4 operator/(const Vec4& a, float b) {
		return Vec4{ a.x / b, a.y / b, a.z / b, a.w / b };
	}

	inline Ivec2 operator/(const Ivec2& a, const Ivec2& b) {
		return Ivec2{ a.x / b.x, a.y / b.y };
	}

	inline Ivec3 operator/(const Ivec3& a, const Ivec3& b) {
		return Ivec3{ a.x / b.x, a.y / b.y, a.z / b.z };
	}

	inline Ivec4 operator/(const Ivec4& a, const Ivec4& b) {
		return Ivec4{ a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
	}

	inline Vec2 operator/(const Vec2& a, const Vec2& b) {
		return Vec2{ a.x / b.x, a.y / b.y };
	}

	inline Vec3 operator/(const Vec3& a, const Vec3& b) {
		return Vec3{ a.x / b.x, a.y / b.y, a.z / b.z };
	}

	inline Vec4 operator/(const Vec4& a, const Vec4& b) {
		return Vec4{ a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w };
	}

	inline Ivec2& operator+=(Ivec2& a, const Ivec2& b) {
		a.x += b.x;
		a.y += b.y;
		return a;
	}

	inline Ivec3& operator+=(Ivec3& a, const Ivec3& b) {
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		return a;
	}

	inline Ivec4& operator+=(Ivec4& a, const Ivec4& b) {
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		a.w += b.w;
		return a;
	}

	inline Vec2& operator+=(Vec2& a, const Vec2& b) {
		a.x += b.x;
		a.y += b.y;
		return a;
	}

	inline Vec3& operator+=(Vec3& a, const Vec3& b) {
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		return a;
	}

	inline Vec4& operator+=(Vec4& a, const Vec4& b) {
		a.x += b.x;
		a.y += b.y;
		a.z += b.z;
		a.w += b.w;
		return a;
	}

	inline Ivec2& operator-=(Ivec2& a, const Ivec2& b) {
		a.x -= b.x;
		a.y -= b.y;
		return a;
	}

	inline Ivec3& operator-=(Ivec3& a, const Ivec3& b) {
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
		return a;
	}

	inline Ivec4& operator-=(Ivec4& a, const Ivec4& b) {
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
		a.w -= b.w;
		return a;
	}

	inline Vec2& operator-=(Vec2& a, const Vec2& b) {
		a.x -= b.x;
		a.y -= b.y;
		return a;
	}

	inline Vec3& operator-=(Vec3& a, const Vec3& b) {
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
		return a;
	}

	inline Vec4& operator-=(Vec4& a, const Vec4& b) {
		a.x -= b.x;
		a.y -= b.y;
		a.z -= b.z;
		a.w -= b.w;
		return a;
	}

	inline Ivec2& operator*=(Ivec2& a, int b) {
		a.x *= b;
		a.y *= b;
		return a;
	}

	inline Ivec3& operator*=(Ivec3& a, int b) {
		a.x *= b;
		a.y *= b;
		a.z *= b;
		return a;
	}

	inline Ivec4& operator*=(Ivec4& a, int b) {
		a.x *= b;
		a.y *= b;
		a.z *= b;
		a.w *= b;
		return a;
	}

	inline Vec2& operator*=(Vec2& a, float b) {
		a.x *= b;
		a.y *= b;
		return a;
	}

	inline Vec3& operator*=(Vec3& a, float b) {
		a.x *= b;
		a.y *= b;
		a.z *= b;
		return a;
	}

	inline Vec4& operator*=(Vec4& a, float b) {
		a.x *= b;
		a.y *= b;
		a.z *= b;
		a.w *= b;
		return a;
	}

	inline Ivec2& operator*=(Ivec2& a, const Ivec2& b) {
		a.x *= b.x;
		a.y *= b.y;
		return a;
	}

	inline Ivec3& operator*=(Ivec3& a, const Ivec3& b) {
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;
		return a;
	}

	inline Ivec4& operator*=(Ivec4& a, const Ivec4& b) {
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;
		a.w *= b.w;
		return a;
	}

	inline Vec2& operator*=(Vec2& a, const Vec2& b) {
		a.x *= b.x;
		a.y *= b.y;
		return a;
	}

	inline Vec3& operator*=(Vec3& a, const Vec3& b) {
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;
		return a;
	}

	inline Vec4& operator*=(Vec4& a, const Vec4& b) {
		a.x *= b.x;
		a.y *= b.y;
		a.z *= b.z;
		a.w *= b.w;
		return a;
	}

	inline Ivec2& operator/=(Ivec2& a, int b) {
		a.x /= b;
		a.y /= b;
		return a;
	}

	inline Ivec3& operator/=(Ivec3& a, int b) {
		a.x /= b;
		a.y /= b;
		a.z /= b;
		return a;
	}

	inline Ivec4& operator/=(Ivec4& a, int b) {
		a.x /= b;
		a.y /= b;
		a.z /= b;
		a.w /= b;
		return a;
	}

	inline Vec2& operator/=(Vec2& a, float b) {
		a.x /= b;
		a.y /= b;
		return a;
	}

	inline Vec3& operator/=(Vec3& a, float b) {
		a.x /= b;
		a.y /= b;
		a.z /= b;
		return a;
	}

	inline Vec4& operator/=(Vec4& a, float b) {
		a.x /= b;
		a.y /= b;
		a.z /= b;
		a.w /= b;
		return a;
	}

	inline Ivec2& operator/=(Ivec2& a, const Ivec2& b) {
		a.x /= b.x;
		a.y /= b.y;
		return a;
	}

	inline Ivec3& operator/=(Ivec3& a, const Ivec3& b) {
		a.x /= b.x;
		a.y /= b.y;
		a.z /= b.z;
		return a;
	}

	inline Ivec4& operator/=(Ivec4& a, const Ivec4& b) {
		a.x /= b.x;
		a.y /= b.y;
		a.z /= b.z;
		a.w /= b.w;
		return a;
	}

	inline Vec2& operator/=(Vec2& a, const Vec2& b) {
		a.x /= b.x;
		a.y /= b.y;
		return a;
	}

	inline Vec3& operator/=(Vec3& a, const Vec3& b) {
		a.x /= b.x;
		a.y /= b.y;
		a.z /= b.z;
		return a;
	}

	inline Vec4& operator/=(Vec4& a, const Vec4& b) {
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

	inline Ivec2 abs(const Ivec2& v) {
		return { abs(v.x), abs(v.y) };
	}

	inline Ivec3 abs(const Ivec3& v) {
		return { abs(v.x), abs(v.y), abs(v.z) };
	}

	inline Ivec4 abs(const Ivec4& v) {
		return { abs(v.x), abs(v.y), abs(v.z), abs(v.w) };
	}

	inline Vec2 abs(const Vec2& v) {
		return { abs(v.x), abs(v.y) };
	}

	inline Vec3 abs(const Vec3& v) {
		return { abs(v.x), abs(v.y), abs(v.z) };
	}

	inline Vec4 abs(const Vec4& v) {
		return { abs(v.x), abs(v.y), abs(v.z), abs(v.w) };
	}

	inline Ivec2 min(const Ivec2& a, const Ivec2& b) {
		return { min(a.x, b.x), min(a.y, b.y) };
	}

	inline Ivec3 min(const Ivec3& a, const Ivec3& b) {
		return { min(a.x, b.x), min(a.y, b.y), min(a.z, b.z) };
	}

	inline Ivec4 min(const Ivec4& a, const Ivec4& b) {
		return { min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w) };
	}

	inline Vec2 min(const Vec2& a, const Vec2& b) {
		return { min(a.x, b.x), min(a.y, b.y) };
	}

	inline Vec3 min(const Vec3& a, const Vec3& b) {
		return { min(a.x, b.x), min(a.y, b.y), min(a.z, b.z) };
	}

	inline Vec4 min(const Vec4& a, const Vec4& b) {
		return { min(a.x, b.x), min(a.y, b.y), min(a.z, b.z), min(a.w, b.w) };
	}

	inline Ivec2 max(const Ivec2& a, const Ivec2& b) {
		return { max(a.x, b.x), max(a.y, b.y) };
	}

	inline Ivec3 max(const Ivec3& a, const Ivec3& b) {
		return { max(a.x, b.x), max(a.y, b.y), max(a.z, b.z) };
	}

	inline Ivec4 max(const Ivec4& a, const Ivec4& b) {
		return { max(a.x, b.x), max(a.y, b.y), max(a.z, b.z), max(a.w, b.w) };
	}

	inline Vec2 max(const Vec2& a, const Vec2& b) {
		return { max(a.x, b.x), max(a.y, b.y) };
	}

	inline Vec3 max(const Vec3& a, const Vec3& b) {
		return { max(a.x, b.x), max(a.y, b.y), max(a.z, b.z) };
	}

	inline Vec4 max(const Vec4& a, const Vec4& b) {
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

