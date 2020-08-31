#pragma once
#include <cmath>
#include "Vec3.hpp"
#include "Ray.hpp"
#include "Constant.hpp"
#include "Material.hpp"
#include "Intersection.hpp"

namespace aipt {
struct Sphere {
	double radius;
	Vec3 position;
	Color emission;
	Color color;
	ReflectionType reflectionType;

	Sphere(const double radius, const Vec3& pos, const Color& emission, const Color& color, const ReflectionType reflectionType)
		: radius(radius), position(pos), emission(emission), color(color), reflectionType(reflectionType)
	{}

	// Rayと球の交差判定
	bool intersect(const Ray& ray, HitPoint* hitPoint) const {
		// 球とRayの式を代入法で連立して解く
		const Vec3 pMinusO = position - ray.org;
		const double B = dot(pMinusO, ray.dir);
		const double D4 = B * B - dot(pMinusO, pMinusO) + radius * radius;
		
		// 判別式D/4が負⇒交差しない
		if (D4 < 0.0) { return false; }

		// 二次方程式の解の公式を使って解く
		const double sqrt_D4 = sqrt(D4);
		const double t1 = B - sqrt_D4, t2 = B + sqrt_D4;

		// 得られた解がkEPS(1e-6)以下なら交差しない
		// 両方kEPS未満ならレイの向きとは反対方向で交わる
		if (t1 < kEPS && t2 < kEPS) { return false; }

		// 片方の解が0以上kEPS未満なら、レイの始点と球の表面が非常に近い場所に存在している
		//   ⇒ 球の表面でレイが反射し、今球面からレイが発射されたものと考える
		if (t1 > kEPS) {
			// t1 < t2は保証されている
			//  ⇒ t1が始点に近い方のレイと球の交差点
			hitPoint->distance = t1;
		}
		else {
			// t1 < kEPS && t2 > kEPS
			// t2が交差点
			hitPoint->distance = t2;
		}
		
		hitPoint->position = ray.org + hitPoint->distance * ray.dir;
		hitPoint->normal = normalize(hitPoint->position - position);

		return true;
	}
};
}
