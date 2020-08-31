#pragma once
#include <cmath>

namespace aipt {

class Vec3 {
public:

	// TODO: Vec3::ToStr()の実装
	// TODO: Vec3をstd::coutに直接ストリームで投げられるようにする
	// TODO: 各種関数の単体テスト
	// TODO: Logger実装
	double x, y, z;

	constexpr Vec3()
		: x(0), y(0), z(0) {}

	constexpr Vec3(const double x, const double y, const double z)
		: x(x), y(y), z(z) {}

	constexpr Vec3(const Vec3& rhs)
		: x(rhs.x), y(rhs.y), z(rhs.z) {}

	~Vec3() = default;

	constexpr Vec3& operator=(const Vec3& rhs) {
		x = rhs.x; y = rhs.y; z = rhs.z;
		return *this;
	}

	constexpr Vec3 operator+(const Vec3& rhs) const {
		return Vec3(x + rhs.x, y + rhs.y, z + rhs.z);
	}
	constexpr Vec3 operator-(const Vec3& rhs) const {
		return Vec3(x - rhs.x, y - rhs.y, z - rhs.z);
	}
	constexpr Vec3 operator*(const double value) const {
		return Vec3(x * value, y * value, z * value);
	}
	constexpr Vec3 operator/(const double value) const {
		return Vec3(x / value, y / value, z / value);
	}
	constexpr double lenght_squared() const {
		return x * x + y * y + z * z;
	}
	constexpr const double length() const {
		return sqrt(lenght_squared());
	}
};

inline Vec3 operator*(double a, const Vec3& v) {
	return v * a;
}
inline Vec3 normalize(const Vec3& v) {
	return v * (1.0 / v.length());
}
inline const Vec3 mult(const Vec3& lhs, const Vec3& rhs) {
	return Vec3(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}
inline const double dot(const Vec3& a, const Vec3& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
inline const Vec3 cross(const Vec3& a, const Vec3& b) {
	return Vec3(
		(a.y * b.z) - (a.z * b.y),
		(a.z * b.x) - (a.x * b.z),
		(a.x * b.y) - (a.y * b.y)
	);
}

}
