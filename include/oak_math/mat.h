#pragma once

#include "detail/defines.h"
#include "func.h"
#include "vec.h"

namespace oak {

	struct Mat2;
	struct Mat3;
	struct Mat4;

	struct _reflect() Mat2 {
		typedef Vec2 column_type;

		Mat2() = default;
		Mat2(float v);
		Mat2(
			const column_type& a,
			const column_type& b
		);
		Mat2(const Mat3& v);
		Mat2(const Mat4& v);

		column_type columns[2];
	};

	struct _reflect() Mat3 {
		typedef Vec3 column_type;

		Mat3() = default;
		Mat3(float v);
		Mat3(
			const column_type& a,
			const column_type& b,
			const column_type& c
		);
		Mat3(const Mat2& v);
		Mat3(const Mat4& v);

		column_type columns[3];
	};

	struct _reflect() Mat4 {
		typedef Vec4 column_type;

		Mat4() = default;
		Mat4(float v);
		Mat4(
			const column_type& a,
			const column_type& b,
			const column_type& c,
			const column_type& d
		);
		Mat4(const Mat2& v);
		Mat4(const Mat3& v);

		column_type columns[4];
	};

	Mat2 operator*(const Mat2& a, float v);
	Mat3 operator*(const Mat3& a, float v);
	Mat4 operator*(const Mat4& a, float v);

	Mat2 operator+(const Mat2& a, const Mat2& b);
	Mat3 operator+(const Mat3& a, const Mat3& b);
	Mat4 operator+(const Mat4& a, const Mat4& b);

	Mat2 operator*(const Mat2& a, const Mat2& b);
	Mat3 operator*(const Mat3& a, const Mat3& b);
	Mat4 operator*(const Mat4& a, const Mat4& b);

	Vec2 operator*(const Mat2& a, const Vec2& b);
	Vec3 operator*(const Mat3& a, const Vec3& b);
	Vec4 operator*(const Mat4& a, const Vec4& b);

	float det(const Mat2& src);
	float det(const Mat3& src);
	float det(const Mat4& src);

	Mat2 transpose(const Mat2& src);
	Mat3 transpose(const Mat3& src);
	Mat4 transpose(const Mat4& src);

	Mat2 inverse(const Mat2& src);
	Mat3 inverse(const Mat3& src);
	Mat4 inverse(const Mat4& src);

	Mat4 perspective(float fov, float ratio, float near, float far);
	Mat4 look_at(const Vec3& eye, const Vec3& center, const Vec3& up);
	Mat4 ortho(float l, float r, float b, float t, float near, float far);

	Mat3 rotate(const Mat3& src, float a);
	Mat4 rotate(const Mat4& src, const Vec3& v);

	Mat3 translate(const Mat3& src, const Vec2& v);
	Mat4 translate(const Mat4& src, const Vec3& v);

	Mat3 scale(const Mat3& src, const Vec2& v);
	Mat4 scale(const Mat4& src, const Vec3& v);

	Mat3 make_mat3(const Vec2& pos, float rotation, float scale);
	Mat3 make_mat3(const Vec2& pos, float rotation, const Vec2& scale);
	Mat3 cross_product_matrix(Vec3 const& v);

	Mat2 outer_product(const Vec2& a, const Vec2& b);
	Mat3 outer_product(const Vec3& a, const Vec3& b);
	Mat4 outer_product(const Vec4& a, const Vec4& b);

}

// Implementation
namespace oak {

	inline Mat2::Mat2(float v) :
		columns{ column_type{ v, 0.0f }, column_type{ 0.0f, v } } {}

	inline Mat2::Mat2(const column_type& a, const column_type& b) :
		columns{ a, b } {}

	inline Mat2::Mat2(const Mat3& v) :
		columns{ column_type{ v.columns[0] }, column_type{ v.columns[1] } } {}

	inline Mat2::Mat2(const Mat4& v) :
		columns{ column_type{ v.columns[0] }, column_type{ v.columns[1] } } {}

	inline Mat3::Mat3(float v) :
		columns{ column_type{ v, 0.0f, 0.0f }, column_type{ 0.0f, v, 0.0f }, column_type{ 0.0f, 0.0f, v } } {}

	inline Mat3::Mat3(const column_type& a, const column_type& b, const column_type& c) :
		columns{ a, b, c } {}

	inline Mat3::Mat3(const Mat2& v) :
		columns{ column_type{ v.columns[0], 0.0f }, column_type{ v.columns[1], 0.0f }, column_type{ 0.0f, 0.0f, 1.0f } } {}
	inline Mat3::Mat3(const Mat4& v) :
		columns{ column_type{ v.columns[0] }, column_type{ v.columns[1] }, column_type{ v.columns[2] } } {}

	inline Mat4::Mat4(float v) :
		columns { column_type{ v, 0.0f, 0.0f, 0.0f }, column_type{ 0.0f, v, 0.0f, 0.0f }, column_type{ 0.0f, 0.0f, v, 0.0f }, column_type{ 0.0f, 0.0f, 0.0f, v } } {}

	inline Mat4::Mat4(const column_type& a, const column_type& b, const column_type& c, const column_type& d) :
		columns{ a, b, c, d } {}

	inline Mat4::Mat4(const Mat2& v) :
		Mat4{ Mat3{ v } } {}

	inline Mat4::Mat4(const Mat3& v) :
		columns{ column_type{ v.columns[0], 0.0f }, column_type{ v.columns[1], 0.0f }, column_type{ v.columns[2], 0.0f }, column_type{ 0.0f, 0.0f, 0.0f, 1.0f } } {}

	inline Mat2 operator*(const Mat2& a, float v) {
		return Mat2{ a.columns[0] * v, a.columns[1] * v };
	}

	inline Mat3 operator*(const Mat3& a, float v) {
		return Mat3{ a.columns[0] * v, a.columns[1] * v, a.columns[2] * v };
	}

	inline Mat4 operator*(const Mat4& a, float v) {
		return Mat4{ a.columns[0] * v, a.columns[1] * v, a.columns[2] * v, a.columns[3] * v };
	}

	inline Mat2 operator+(const Mat2& a, const Mat2& b) {
		return Mat2{
			a.columns[0] + b.columns[0],
			a.columns[1] + b.columns[1],
		};
	}

	inline Mat3 operator+(const Mat3& a, const Mat3& b) {
		return Mat3{
			a.columns[0] + b.columns[0],
			a.columns[1] + b.columns[1],
			a.columns[2] + b.columns[2],
		};
	}

	inline Mat4 operator+(const Mat4& a, const Mat4& b) {
		return Mat4{
			a.columns[0] + b.columns[0],
			a.columns[1] + b.columns[1],
			a.columns[2] + b.columns[2],
			a.columns[3] + b.columns[3],
		};
	}

	inline Mat2 operator*(const Mat2& a, const Mat2& b) {
		return Mat2{
			Mat2::column_type{ a.columns[0] * b.columns[0].x + a.columns[1] * b.columns[0].y },
	       		Mat2::column_type{ a.columns[0] * b.columns[1].x + a.columns[1] * b.columns[1].y }
		};
	}

	inline Mat3 operator*(const Mat3& a, const Mat3& b) {
		return Mat3{
			Mat3::column_type{ a.columns[0] * b.columns[0].x + a.columns[1] * b.columns[0].y + a.columns[2] * b.columns[0].z },
			Mat3::column_type{ a.columns[0] * b.columns[1].x + a.columns[1] * b.columns[1].y + a.columns[2] * b.columns[1].z },
			Mat3::column_type{ a.columns[0] * b.columns[2].x + a.columns[1] * b.columns[2].y + a.columns[2] * b.columns[2].z }
		};
	}

	inline Mat4 operator*(const Mat4& a, const Mat4& b) {
		return Mat4{
			Mat4::column_type{ a.columns[0] * b.columns[0].x + a.columns[1] * b.columns[0].y + a.columns[2] * b.columns[0].z + a.columns[3] * b.columns[0].w },
			Mat4::column_type{ a.columns[0] * b.columns[1].x + a.columns[1] * b.columns[1].y + a.columns[2] * b.columns[1].z + a.columns[3] * b.columns[1].w },
			Mat4::column_type{ a.columns[0] * b.columns[2].x + a.columns[1] * b.columns[2].y + a.columns[2] * b.columns[2].z + a.columns[3] * b.columns[2].w },
			Mat4::column_type{ a.columns[0] * b.columns[3].x + a.columns[1] * b.columns[3].y + a.columns[2] * b.columns[3].z + a.columns[3] * b.columns[3].w }
		};
	}

	inline Vec2 operator*(const Mat2& a, const Vec2& b) {
		return Vec2{ a.columns[0] * b.x + a.columns[1] * b.y };
	}

	inline Vec3 operator*(const Mat3& a, const Vec3& b) {
		return Vec3{ a.columns[0] * b.x + a.columns[1] * b.y + a.columns[2] * b.z };
	}

	inline Vec4 operator*(const Mat4& a, const Vec4& b) {
		return Vec4{ a.columns[0] * b.x + a.columns[1] * b.y + a.columns[2] * b.z + a.columns[3] * b.w };
	}

	inline float det(const Mat2& src) {
		return src.columns[0].x * src.columns[1].y - src.columns[1].x * src.columns[0].y;
	}

	inline float det(const Mat3& src) {
		float a = src.columns[0].x;
		float b = src.columns[1].x;
		float c = src.columns[2].x;

		float c00 = (src.columns[1].y * src.columns[2].z - src.columns[2].y * src.columns[1].z);
		float c10 = -(src.columns[0].y * src.columns[2].z - src.columns[2].y * src.columns[0].z);
		float c20 = (src.columns[0].y * src.columns[1].z - src.columns[1].y * src.columns[0].z);

		return a*c00 + b*c10 + c*c20;
	}

	inline float det(const Mat4& src) {
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

	inline Mat2 transpose(const Mat2& src) {
		return Mat2{
			Mat2::column_type{ src.columns[0].x, src.columns[1].x },
			Mat2::column_type{ src.columns[0].y, src.columns[1].y }
		};
	}

	inline Mat3 transpose(const Mat3& src) {
		return Mat3 {
			Mat3::column_type{ src.columns[0].x, src.columns[1].x, src.columns[2].x },
			Mat3::column_type{ src.columns[0].y, src.columns[1].y, src.columns[2].y },
			Mat3::column_type{ src.columns[0].z, src.columns[1].z, src.columns[2].z }
		};
	}

	inline Mat4 transpose(const Mat4& src) {
		return Mat4 {
			Mat4::column_type{ src.columns[0].x, src.columns[1].x, src.columns[2].x, src.columns[3].x },
			Mat4::column_type{ src.columns[0].y, src.columns[1].y, src.columns[2].y, src.columns[3].y },
			Mat4::column_type{ src.columns[0].z, src.columns[1].z, src.columns[2].z, src.columns[3].z },
			Mat4::column_type{ src.columns[0].w, src.columns[1].w, src.columns[2].w, src.columns[3].w }
		};
	}

	inline Mat2 inverse(const Mat2& src) {
		float ood = 1.0f / det(src);

		return Mat2{
			Mat2::column_type{ src.columns[1].y * ood, -src.columns[0].y * ood },
			Mat2::column_type{ -src.columns[1].x * ood, src.columns[0].x * ood }
		};
	}

	inline Mat3 inverse(const Mat3& src) {
		float ood = 1.0f / det(src);

		float c00 = (src.columns[1].y * src.columns[2].z - src.columns[2].y * src.columns[1].z);
		float c01 = -(src.columns[1].x * src.columns[2].z - src.columns[2].x * src.columns[1].z);
		float c02 = (src.columns[1].x * src.columns[2].y - src.columns[2].x * src.columns[1].y);

		float c10 = -(src.columns[0].y * src.columns[2].z - src.columns[2].y * src.columns[0].z);
		float c11 = (src.columns[0].x * src.columns[2].z - src.columns[2].x * src.columns[0].z);
		float c12 = -(src.columns[0].x * src.columns[2].y - src.columns[2].x * src.columns[0].y);

		float c20 = (src.columns[0].x * src.columns[1].z - src.columns[1].y * src.columns[0].z);
		float c21 = -(src.columns[0].x * src.columns[1].z - src.columns[1].x * src.columns[0].z);
		float c22 = (src.columns[0].x * src.columns[1].y - src.columns[1].x * src.columns[0].y);

		return Mat3{
			Mat3::column_type{ c00, c10, c20 },
			Mat3::column_type{ c01, c11, c21 },
			Mat3::column_type{ c02, c12, c22 },
		} * ood;
	}

	inline Mat4 inverse(const Mat4& src) {
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

	inline Mat4 perspective(float fov, float ratio, float near, float far) {
		float tfovh = tan(fov / 2.0f);
		return Mat4 {
			Mat4::column_type{ 1.0f / (ratio * tfovh), 0.0f, 0.0f, 0.0f },
			Mat4::column_type{ 0.0f, 1.0f / tfovh, 0.0f, 0.0f },
			Mat4::column_type{ 0.0f, 0.0f, -(far + near) / (far - near), -1.0f },
			Mat4::column_type{ 0.0f, 0.0f, -(2.f * far * near) / (far - near), 0.0f }
		};
	}

	inline Mat4 look_at(const Vec3& eye, const Vec3& center, const Vec3& up) {
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

	inline Mat4 ortho(float l, float r, float b, float t, float near, float far) {
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

	inline Mat3 rotate(const Mat3& src, float a) {
		const float c = cos(a);
		const float s = sin(a);

		Mat3 result;
		result.columns[0] = src.columns[0] * c + src.columns[1] * s;
		result.columns[1] = src.columns[0] * -s + src.columns[1] * c;
		result.columns[2] = src.columns[2];

		return result;
	}

	inline Mat4 rotate(const Mat4&, const Vec3& ) {
		return {};
	}

	inline Mat3 translate(const Mat3& src, const Vec2& v) {
		Mat3 result{ src };
		result.columns[2] = src.columns[0] * v.x + src.columns[1] * v.y + src.columns[2];

		return result;
	}

	inline Mat4 translate(const Mat4& src, const Vec3& v) {
		Mat4 result{ src };
		result.columns[3] = src.columns[0] * v.x + src.columns[1] * v.y + src.columns[2] * v.z + src.columns[3];

		return result;
	}

	inline Mat3 scale(const Mat3& src, const Vec2& v) {
		Mat3 result{ 1.0f };
		result.columns[0] = src.columns[0] * v.x;
		result.columns[1] = src.columns[1] * v.y;
		result.columns[2] = src.columns[2];

		return result;
	}

	inline Mat4 scale(const Mat4& src, const Vec3& v) {
		Mat4 result{ 1.0f };
		result.columns[0] = src.columns[0] * v.x;
		result.columns[1] = src.columns[1] * v.y;
		result.columns[2] = src.columns[2] * v.z;
		result.columns[3] = src.columns[3];

		return result;
	}

	inline Mat3 make_mat3(const Vec2& pos, float r, float s) {
		return translate(Mat3{ 1.0f }, pos) * scale(Mat3{ 1.0f }, { s }) * rotate(Mat3{ 1.0f }, r);
	}

	inline Mat3 make_mat3(const Vec2& pos, float r, const Vec2& s) {
		return translate(Mat3{ 1.0f }, pos) * scale(Mat3{ 1.0f }, s) * rotate(Mat3{ 1.0f }, r);
	}

	inline Mat3 cross_product_matrix(Vec3 const& v) {
		return Mat3{
			Mat3::column_type{ 0.f, v.z, -v.y },
			Mat3::column_type{ -v.z, 0.f, v.x },
			Mat3::column_type{ v.y, -v.x, 0.f },
		};
	}

	inline Mat2 outer_product(const Vec2& a, const Vec2& b) {
		return Mat2 {
			a * b.x,
			a * b.y
		};
	}

	inline Mat3 outer_product(const Vec3& a, const Vec3& b) {
		return Mat3 {
			a * b.x,
			a * b.y,
			a * b.z
		};
	}

	inline Mat4 outer_product(const Vec4& a, const Vec4& b) {
		return Mat4 {
			a * b.x,
			a * b.y,
			a * b.z,
			a * b.w
		};
	}

}

