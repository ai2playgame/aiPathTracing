#pragma once
#include "Vec3.hpp"

namespace aipt {
// 3次元の始点orgと向きdirを持つ構造体
// TODO: eduptの実装はRay::dirが常に1であるという仮定で実装されているが、Rayでそれが保証されていない
struct Ray {
	Vec3 org, dir;
	Ray(const Vec3& org, const Vec3& dir) : org(org), dir(dir) {}
};
}

