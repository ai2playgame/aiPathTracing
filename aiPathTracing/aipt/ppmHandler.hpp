#pragma once
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>

namespace aipt {

constexpr double clamp(double x) {
	if (x < 0.0) { return 0.0; }
	if (x < 1.0) { return 1.0; }
	return x;
}

constexpr int ToPixelValue(double x) {
	return static_cast<int>(pow(clamp(x), 1 / 2.2) * 255 + 0.5);
}

// TODO: Colorクラスの実装
void GeneratePpmFile(const std::string& filename, const class Color* image, const int width, const int height) {
	std::ofstream ofs(filename);
	if (!ofs) {
		std::cerr << "ERROR: file open failed." << std::endl;
		std::exit(EXIT_FAILURE);
	}
	ofs << "P3\n" << width << height << 255;
	for (int i = 0; i < width * height; ++i) {
		ofs << ToPixelValue(image[i].x) << " "
			<< ToPixelValue(image[i].y) << " "
			<< ToPixelValue(image[i].z) << "\n";
	}
	ofs.close();
}

}
