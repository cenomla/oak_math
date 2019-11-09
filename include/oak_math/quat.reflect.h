#pragma once

#include <oak_reflect/type_info.h>
#include </home/cenomla/data/workspace/cpp/shooter/build/../subprojects/oak_math/include/oak_math/quat.h>

namespace oak {
template<> struct Reflect<::oak::Ivec2> {
	using T = ::oak::Ivec2;
	static constexpr StructTypeInfo typeInfo{ { 5218795283737642440ul, TypeInfoKind::STRUCT }, "Ivec2", "reflect;oak::catagory::math", sizeof(T), alignof(T), {} };
};
template<> struct Reflect<::oak::Ivec3> {
	using T = ::oak::Ivec3;
	static constexpr StructTypeInfo typeInfo{ { 5218795283737642441ul, TypeInfoKind::STRUCT }, "Ivec3", "reflect;oak::catagory::math", sizeof(T), alignof(T), {} };
};
template<> struct Reflect<::oak::Ivec4> {
	using T = ::oak::Ivec4;
	static constexpr StructTypeInfo typeInfo{ { 5218795283737642442ul, TypeInfoKind::STRUCT }, "Ivec4", "reflect;oak::catagory::math", sizeof(T), alignof(T), {} };
};
template<> struct Reflect<::oak::Vec2> {
	using T = ::oak::Vec2;
	static constexpr StructTypeInfo typeInfo{ { 24277160158647967ul, TypeInfoKind::STRUCT }, "Vec2", "reflect;oak::catagory::math", sizeof(T), alignof(T), {} };
};
template<> struct Reflect<::oak::Vec3> {
	using T = ::oak::Vec3;
	static constexpr StructTypeInfo typeInfo{ { 24277160158647968ul, TypeInfoKind::STRUCT }, "Vec3", "reflect;oak::catagory::math", sizeof(T), alignof(T), {} };
};
template<> struct Reflect<::oak::Vec4> {
	using T = ::oak::Vec4;
	static constexpr StructTypeInfo typeInfo{ { 24277160158647969ul, TypeInfoKind::STRUCT }, "Vec4", "reflect;oak::catagory::math", sizeof(T), alignof(T), {} };
};
template<> struct Reflect<::oak::Mat2> {
	using T = ::oak::Mat2;
	static constexpr StructTypeInfo typeInfo{ { 21736555391796755ul, TypeInfoKind::STRUCT }, "Mat2", "reflect;oak::catagory::math", sizeof(T), alignof(T), {} };
};
template<> struct Reflect<::oak::Mat3> {
	using T = ::oak::Mat3;
	static constexpr StructTypeInfo typeInfo{ { 21736555391796756ul, TypeInfoKind::STRUCT }, "Mat3", "reflect;oak::catagory::math", sizeof(T), alignof(T), {} };
};
template<> struct Reflect<::oak::Mat4> {
	using T = ::oak::Mat4;
	static constexpr StructTypeInfo typeInfo{ { 21736555391796757ul, TypeInfoKind::STRUCT }, "Mat4", "reflect;oak::catagory::math", sizeof(T), alignof(T), {} };
};
template<> struct Reflect<::oak::Quat> {
	using T = ::oak::Quat;
	static constexpr StructTypeInfo typeInfo{ { 22865791479593656ul, TypeInfoKind::STRUCT }, "Quat", "reflect;oak::catagory::math", sizeof(T), alignof(T), {} };
};
}
