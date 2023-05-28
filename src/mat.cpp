#define OAK_MATH_EXPORT_SYMBOLS

#include <oak_math/mat.h>

#include <oak_math/func.h>
#include <oak_math/vec.h>

namespace oak {

	Mat2::Mat2(float v) :
		columns{ column_type{ v, 0.0f }, column_type{ 0.0f, v } } {}

	Mat2::Mat2(const column_type& a, const column_type& b) :
		columns{ a, b } {}

	Mat2::Mat2(const Mat3& v) :
		columns{ column_type{ v.columns[0] }, column_type{ v.columns[1] } } {}

	Mat2::Mat2(const Mat4& v) :
		columns{ column_type{ v.columns[0] }, column_type{ v.columns[1] } } {}

	Mat3::Mat3(float v) :
		columns{ column_type{ v, 0.0f, 0.0f }, column_type{ 0.0f, v, 0.0f }, column_type{ 0.0f, 0.0f, v } } {}

	Mat3::Mat3(const column_type& a, const column_type& b, const column_type& c) :
		columns{ a, b, c } {}

	Mat3::Mat3(const Mat2& v) :
		columns{ column_type{ v.columns[0], 0.0f }, column_type{ v.columns[1], 0.0f }, column_type{ 0.0f, 0.0f, 1.0f } } {}
	Mat3::Mat3(const Mat4& v) :
		columns{ column_type{ v.columns[0] }, column_type{ v.columns[1] }, column_type{ v.columns[2] } } {}

	Mat4::Mat4(float v) :
		columns { column_type{ v, 0.0f, 0.0f, 0.0f }, column_type{ 0.0f, v, 0.0f, 0.0f }, column_type{ 0.0f, 0.0f, v, 0.0f }, column_type{ 0.0f, 0.0f, 0.0f, v } } {}

	Mat4::Mat4(const column_type& a, const column_type& b, const column_type& c, const column_type& d) :
		columns{ a, b, c, d } {}

	Mat4::Mat4(const Mat2& v) :
		Mat4{ Mat3{ v } } {}

	Mat4::Mat4(const Mat3& v) :
		columns{ column_type{ v.columns[0], 0.0f }, column_type{ v.columns[1], 0.0f }, column_type{ v.columns[2], 0.0f }, column_type{ 0.0f, 0.0f, 0.0f, 1.0f } } {}

	Mat2 operator*(const Mat2& a, float v) {
		return Mat2{ a.columns[0] * v, a.columns[1] * v };
	}

	Mat3 operator*(const Mat3& a, float v) {
		return Mat3{ a.columns[0] * v, a.columns[1] * v, a.columns[2] * v };
	}

	Mat4 operator*(const Mat4& a, float v) {
		return Mat4{ a.columns[0] * v, a.columns[1] * v, a.columns[2] * v, a.columns[3] * v };
	}

	Mat2 operator*(const Mat2& a, const Mat2& b) {
		return Mat2{
			Mat2::column_type{ a.columns[0] * b.columns[0].x + a.columns[1] * b.columns[0].y },
	       		Mat2::column_type{ a.columns[0] * b.columns[1].x + a.columns[1] * b.columns[1].y }
		};
	}

	Mat3 operator*(const Mat3& a, const Mat3& b) {
		return Mat3{
			Mat3::column_type{ a.columns[0] * b.columns[0].x + a.columns[1] * b.columns[0].y + a.columns[2] * b.columns[0].z },
			Mat3::column_type{ a.columns[0] * b.columns[1].x + a.columns[1] * b.columns[1].y + a.columns[2] * b.columns[1].z },
			Mat3::column_type{ a.columns[0] * b.columns[2].x + a.columns[1] * b.columns[2].y + a.columns[2] * b.columns[2].z }
		};
	}

	Mat4 operator*(const Mat4& a, const Mat4& b) {
		return Mat4{
			Mat4::column_type{ a.columns[0] * b.columns[0].x + a.columns[1] * b.columns[0].y + a.columns[2] * b.columns[0].z + a.columns[3] * b.columns[0].w },
			Mat4::column_type{ a.columns[0] * b.columns[1].x + a.columns[1] * b.columns[1].y + a.columns[2] * b.columns[1].z + a.columns[3] * b.columns[1].w },
			Mat4::column_type{ a.columns[0] * b.columns[2].x + a.columns[1] * b.columns[2].y + a.columns[2] * b.columns[2].z + a.columns[3] * b.columns[2].w },
			Mat4::column_type{ a.columns[0] * b.columns[3].x + a.columns[1] * b.columns[3].y + a.columns[2] * b.columns[3].z + a.columns[3] * b.columns[3].w }
		};
	}

	Vec2 operator*(const Mat2& a, const Vec2& b) {
		return Vec2{ a.columns[0] * b.x + a.columns[1] * b.y };
	}

	Vec3 operator*(const Mat3& a, const Vec3& b) {
		return Vec3{ a.columns[0] * b.x + a.columns[1] * b.y + a.columns[2] * b.z };
	}

	Vec4 operator*(const Mat4& a, const Vec4& b) {
		return Vec4{ a.columns[0] * b.x + a.columns[1] * b.y + a.columns[2] * b.z + a.columns[3] * b.w };
	}

	float det(const Mat2& src) {
		return src.columns[0].x * src.columns[1].y - src.columns[1].x * src.columns[0].y;
	}

	float det(const Mat3& src) {
		return
			src.columns[0].x * src.columns[1].y * src.columns[2].z +
			src.columns[1].x * src.columns[2].y * src.columns[0].z +
			src.columns[2].x * src.columns[0].y * src.columns[1].z -
			src.columns[2].x * src.columns[1].y * src.columns[0].z -
			src.columns[1].x * src.columns[0].y * src.columns[2].z -
			src.columns[0].x * src.columns[2].y * src.columns[1].z;
	}

	float det(const Mat4& src) {
		return
			src.columns[0].x * (
				src.columns[1].y * src.columns[2].z * src.columns[3].w +
				src.columns[2].y * src.columns[3].z * src.columns[1].w +
				src.columns[3].y * src.columns[1].z * src.columns[2].w -
				src.columns[3].y * src.columns[2].z * src.columns[1].w -
				src.columns[2].y * src.columns[1].z * src.columns[3].w -
				src.columns[1].y * src.columns[3].z * src.columns[2].w
			) - src.columns[1].x * (
				src.columns[0].y * src.columns[2].z * src.columns[3].w +
				src.columns[2].y * src.columns[3].z * src.columns[0].w +
				src.columns[3].y * src.columns[0].z * src.columns[2].w -
				src.columns[3].y * src.columns[2].z * src.columns[0].w -
				src.columns[2].y * src.columns[0].z * src.columns[3].w -
				src.columns[0].y * src.columns[3].z * src.columns[2].w
			) + src.columns[2].x * (
				src.columns[0].y * src.columns[1].z * src.columns[3].w +
				src.columns[1].y * src.columns[3].z * src.columns[0].w +
				src.columns[3].y * src.columns[0].z * src.columns[1].w -
				src.columns[3].y * src.columns[1].z * src.columns[0].w -
				src.columns[1].y * src.columns[0].z * src.columns[3].w -
				src.columns[0].y * src.columns[3].z * src.columns[1].w
			) - src.columns[3].x * (
				src.columns[0].y * src.columns[1].z * src.columns[2].w +
				src.columns[1].y * src.columns[2].z * src.columns[0].w +
				src.columns[2].y * src.columns[0].z * src.columns[1].w -
				src.columns[2].y * src.columns[1].z * src.columns[0].w -
				src.columns[1].y * src.columns[0].z * src.columns[2].w -
				src.columns[0].y * src.columns[2].z * src.columns[1].w
			);
	}

	Mat2 transpose(const Mat2& src) {
		return Mat2{
			Mat2::column_type{ src.columns[0].x, src.columns[1].x },
			Mat2::column_type{ src.columns[0].y, src.columns[1].y }
		};
	}

	Mat3 transpose(const Mat3& src) {
		return Mat3 {
			Mat3::column_type{ src.columns[0].x, src.columns[1].x, src.columns[2].x },
			Mat3::column_type{ src.columns[0].y, src.columns[1].y, src.columns[2].y },
			Mat3::column_type{ src.columns[0].z, src.columns[1].z, src.columns[2].z }
		};
	}

	Mat4 transpose(const Mat4& src) {
		return Mat4 {
			Mat4::column_type{ src.columns[0].x, src.columns[1].x, src.columns[2].x, src.columns[3].x },
			Mat4::column_type{ src.columns[0].y, src.columns[1].y, src.columns[2].y, src.columns[3].y },
			Mat4::column_type{ src.columns[0].z, src.columns[1].z, src.columns[2].z, src.columns[3].z },
			Mat4::column_type{ src.columns[0].w, src.columns[1].w, src.columns[2].w, src.columns[3].w }
		};
	}

	Mat2 inverse(const Mat2& src) {
		float ood = 1.0f / det(src);

		return Mat2{
			Mat2::column_type{ src.columns[1].y * ood, -src.columns[0].y * ood },
			Mat2::column_type{ -src.columns[1].x * ood, src.columns[0].x * ood }
		};
	}

	Mat3 inverse(const Mat3& src) {
		float ood = 1.0f / det(src);

		return Mat3{
			Mat3::column_type{
			(src.columns[1].y * src.columns[2].z - src.columns[2].y * src.columns[1].z) * ood,
			- (src.columns[1].x * src.columns[2].z - src.columns[2].x * src.columns[1].z) * ood,
			(src.columns[1].x * src.columns[2].y - src.columns[2].x * src.columns[1].y) * ood },
			Mat3::column_type{
			- (src.columns[0].y * src.columns[2].z - src.columns[2].y * src.columns[0].z) * ood,
			(src.columns[0].x * src.columns[2].z - src.columns[2].x * src.columns[0].z) * ood,
			- (src.columns[0].x * src.columns[2].y - src.columns[2].x * src.columns[0].y) *ood },
			Mat3::column_type{
			(src.columns[0].x * src.columns[1].z - src.columns[1].y * src.columns[0].z) * ood,
			- (src.columns[0].x * src.columns[1].z - src.columns[1].x * src.columns[0].z) * ood,
			(src.columns[0].x * src.columns[1].y - src.columns[1].x * src.columns[0].y) * ood }
		};
	}

	Mat4 inverse(const Mat4& src) {
		float ood = 1.0f / det(src);

		float c00 = src.columns[2].z * src.columns[3].w - src.columns[3].z * src.columns[2].w;
		float c02 = src.columns[1].z * src.columns[3].w - src.columns[3].z * src.columns[1].w;
		float c03 = src.columns[1].z * src.columns[2].w - src.columns[2].z * src.columns[1].w;

		float c04 = src.columns[2].y * src.columns[3].w - src.columns[3].y * src.columns[2].w;
		float c06 = src.columns[1].y * src.columns[3].w - src.columns[3].y * src.columns[1].w;
		float c07 = src.columns[1].y * src.columns[2].w - src.columns[2].y * src.columns[1].w;

		float c08 = src.columns[2].y * src.columns[3].z - src.columns[3].y * src.columns[2].z;
		float c10 = src.columns[1].y * src.columns[3].z - src.columns[3].y * src.columns[1].z;
		float c11 = src.columns[1].y * src.columns[2].z - src.columns[2].y * src.columns[1].z;

		float c12 = src.columns[2].x * src.columns[3].w - src.columns[3].x * src.columns[2].w;
		float c14 = src.columns[1].x * src.columns[3].w - src.columns[3].x * src.columns[1].w;
		float c15 = src.columns[1].x * src.columns[2].w - src.columns[2].x * src.columns[1].w;

		float c16 = src.columns[2].x * src.columns[3].z - src.columns[3].x * src.columns[2].z;
		float c18 = src.columns[1].x * src.columns[3].z - src.columns[3].x * src.columns[1].z;
		float c19 = src.columns[1].x * src.columns[2].z - src.columns[2].x * src.columns[1].z;

		float c20 = src.columns[2].x * src.columns[3].y - src.columns[3].x * src.columns[2].y;
		float c22 = src.columns[1].x * src.columns[3].y - src.columns[3].x * src.columns[1].y;
		float c23 = src.columns[1].x * src.columns[2].y - src.columns[2].x * src.columns[1].y;

		Mat4::column_type f0{ c00, c00, c02, c03 };
		Mat4::column_type f1{ c04, c04, c06, c07 };
		Mat4::column_type f2{ c08, c08, c10, c11 };
		Mat4::column_type f3{ c12, c12, c14, c15 };
		Mat4::column_type f4{ c16, c16, c18, c19 };
		Mat4::column_type f5{ c20, c20, c22, c23 };

		Mat4::column_type v0{ src.columns[1].x, src.columns[0].x, src.columns[0].x, src.columns[0].x };
		Mat4::column_type v1{ src.columns[1].y, src.columns[0].y, src.columns[0].y, src.columns[0].y };
		Mat4::column_type v2{ src.columns[1].z, src.columns[0].z, src.columns[0].z, src.columns[0].z };
		Mat4::column_type v3{ src.columns[1].w, src.columns[0].w, src.columns[0].w, src.columns[0].w };

		Mat4::column_type i0{ v1 * f0 - v2 * f1 + v3 * f2 };
		Mat4::column_type i1{ v0 * f0 - v2 * f3 + v3 * f4 };
		Mat4::column_type i2{ v0 * f1 - v1 * f3 + v3 * f5 };
		Mat4::column_type i3{ v0 * f2 - v1 * f4 + v2 * f5 };

		Mat4::column_type sA{ 1, -1, 1, -1 };
		Mat4::column_type sB{ -1, 1, -1, 1 };

		return Mat4{ i0 * sA, i1 * sB, i2 * sA, i3 * sB } * ood;
	}

	Mat4 perspective(float fov, float ratio, float near, float far) {
		float tfovh = tan(fov / 2.0f);
		return Mat4 {
			Mat4::column_type{ 1.0f / (ratio * tfovh), 0.0f, 0.0f, 0.0f },
			Mat4::column_type{ 0.0f, 1.0f / tfovh, 0.0f, 0.0f },
			Mat4::column_type{ 0.0f, 0.0f, -(far + near) / (far - near), -1.0f },
			Mat4::column_type{ 0.0f, 0.0f, -(2.f * far * near) / (far - near), 0.0f }
		};
	}

	Mat4 lookAt(const Vec3& eye, const Vec3& center, const Vec3& up) {
		Vec3 f{ normalize(center - eye) };
		Vec3 s{ normalize(cross(f, up)) };
		Vec3 u{ cross(s, f) };

		return Mat4 {
			Mat4::column_type{ s.x, u.x, -f.x, 0.0f },
			Mat4::column_type{ s.y, u.y, -f.y, 0.0f },
			Mat4::column_type{ s.z, u.z, -f.z, 0.0f },
			Mat4::column_type{ -dot(s, eye), -dot(u, eye), dot(f, eye), 1.0f }
		};
	}

	Mat4 ortho(float l, float r, float b, float t, float near, float far) {
		float rsl = r - l;
		float tsb = t - b;
		float fsn = far - near;

		return Mat4 {
			Mat4::column_type{ 2.0f / rsl, 0.0f, 0.0f, 0.0f },
			Mat4::column_type{ 0.0f, 2.0f / tsb, 0.0f, 0.0f },
			Mat4::column_type{ 0.0f, 0.0f, -2.0f / (fsn), 0.0f },
			Mat4::column_type{ -(r + l)/(rsl), -(t + b)/tsb, -(far + near)/fsn, 1.0f }
		};
	}

	Mat3 rotate(const Mat3& src, float a) {
		const float c = cos(a);
		const float s = sin(a);

		Mat3 result;
		result.columns[0] = src.columns[0] * c + src.columns[1] * s;
		result.columns[1] = src.columns[0] * -s + src.columns[1] * c;
		result.columns[2] = src.columns[2];

		return result;
	}

	Mat4 rotate(const Mat4& src, const Vec3& v) {
		return {};
	}

	Mat3 translate(const Mat3& src, const Vec2& v) {
		Mat3 result{ src };
		result.columns[2] = src.columns[0] * v.x + src.columns[1] * v.y + src.columns[2];

		return result;
	}

	Mat4 translate(const Mat4& src, const Vec3& v) {
		Mat4 result{ src };
		result.columns[3] = src.columns[0] * v.x + src.columns[1] * v.y + src.columns[2] * v.z + src.columns[3];

		return result;
	}

	Mat3 scale(const Mat3& src, const Vec2& v) {
		Mat3 result{ 1.0f };
		result.columns[0] = src.columns[0] * v.x;
		result.columns[1] = src.columns[1] * v.y;
		result.columns[2] = src.columns[2];

		return result;
	}

	Mat4 scale(const Mat4& src, const Vec3& v) {
		Mat4 result{ 1.0f };
		result.columns[0] = src.columns[0] * v.x;
		result.columns[1] = src.columns[1] * v.y;
		result.columns[2] = src.columns[2] * v.z;
		result.columns[3] = src.columns[3];

		return result;
	}

	Mat3 make_mat3(const Vec2& pos, float r, float s) {
		return translate(Mat3{ 1.0f }, pos) * scale(Mat3{ 1.0f }, { s }) * rotate(Mat3{ 1.0f }, r);
	}

	Mat3 make_mat3(const Vec2& pos, float r, const Vec2& s) {
		return translate(Mat3{ 1.0f }, pos) * scale(Mat3{ 1.0f }, s) * rotate(Mat3{ 1.0f }, r);
	}

}

