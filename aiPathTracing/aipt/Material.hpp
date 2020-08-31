#pragma once
#include "Vec3.hpp"

namespace aipt {
using Color = Vec3;

enum ReflectionType {
	REFLECTION_TYPE_DIFFUSE = 0,	// 完全拡散面（Lambertian面）
	REFLECTION_TYPE_SPECULAR,		// 理想的な鏡面
	REFLECTION_TYPE_REFRACTION,		// 理想的なガラス的物質
};

constexpr double kIor = 1.5; // 屈折率 (Index of refraction)

}
