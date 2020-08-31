#pragma once

#include "Vec3.hpp"
#include "Constant.hpp"

namespace aipt {
struct HitPoint {
	double distance;
	Vec3 normal;
	Vec3 position;

	HitPoint() : distance(kINF), normal(), position() {}
};

struct Intersection {
	HitPoint hitPoint;
	int objectID;
	Intersection() : objectID(-1) {}
};
}
