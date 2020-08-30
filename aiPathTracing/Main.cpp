#include <iostream>

#pragma warning(disable:4996)
#include <edupt/render.h>

int main(int argc, char **argv) {
	std::cout << "Path tracing renderer: edupt" << std::endl << std::endl;

	// 640x480の画像、(2x2) * 4 sample / pixel
	edupt::render(640, 480, 128, 2);
}
