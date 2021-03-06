#pragma once

#include "detail/defines.h"
#include "vec.h"

namespace oak {

	struct Mat2;
	struct Mat3;
	struct Mat4;

	struct _reflect(oak::catagory::math) OAK_MATH_API Mat2 {
		typedef Vec2 column_type;

		Mat2() = default;
		Mat2(float v);
		Mat2(
			const column_type& a,
			const column_type& b
		);
		Mat2(const Mat3& v);
		Mat2(const Mat4& v);

		column_type value[2];
	};

	struct _reflect(oak::catagory::math) OAK_MATH_API Mat3 {
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

		column_type value[3];
	};

	struct _reflect(oak::catagory::math) OAK_MATH_API Mat4 {
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

		column_type value[4];
	};

	OAK_MATH_API Mat2 operator*(const Mat2& a, float v);
	OAK_MATH_API Mat3 operator*(const Mat3& a, float v);
	OAK_MATH_API Mat4 operator*(const Mat4& a, float v);

	OAK_MATH_API Mat2 operator*(const Mat2& a, const Mat2& b);
	OAK_MATH_API Mat3 operator*(const Mat3& a, const Mat3& b);
	OAK_MATH_API Mat4 operator*(const Mat4& a, const Mat4& b);

	OAK_MATH_API Vec2 operator*(const Mat2& a, const Vec2& b);
	OAK_MATH_API Vec3 operator*(const Mat3& a, const Vec3& b);
	OAK_MATH_API Vec4 operator*(const Mat4& a, const Vec4& b);

	OAK_MATH_API float det(const Mat2& src);
	OAK_MATH_API float det(const Mat3& src);
	OAK_MATH_API float det(const Mat4& src);

	OAK_MATH_API Mat2 transpose(const Mat2& src);
	OAK_MATH_API Mat3 transpose(const Mat3& src);
	OAK_MATH_API Mat4 transpose(const Mat4& src);

	OAK_MATH_API Mat2 inverse(const Mat2& src);
	OAK_MATH_API Mat3 inverse(const Mat3& src);
	OAK_MATH_API Mat4 inverse(const Mat4& src);

	OAK_MATH_API Mat4 perspective(float fov, float ratio, float near, float far);
	OAK_MATH_API Mat4 lookAt(const Vec3& eye, const Vec3& center, const Vec3& up);
	OAK_MATH_API Mat4 ortho(float l, float r, float b, float t, float near, float far);

	OAK_MATH_API Mat3 rotate(const Mat3& src, float a);
	OAK_MATH_API Mat4 rotate(const Mat4& src, const Vec3& v);

	OAK_MATH_API Mat3 translate(const Mat3& src, const Vec2& v);
	OAK_MATH_API Mat4 translate(const Mat4& src, const Vec3& v);

	OAK_MATH_API Mat3 scale(const Mat3& src, const Vec2& v);
	OAK_MATH_API Mat4 scale(const Mat4& src, const Vec3& v);

	OAK_MATH_API Mat3 make_mat3(const Vec2& pos, float rotation, float scale);
	OAK_MATH_API Mat3 make_mat3(const Vec2& pos, float rotation, const Vec2& scale);

}

