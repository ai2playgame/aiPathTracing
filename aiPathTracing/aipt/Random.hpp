#pragma once
#include <random>

namespace aipt {
class RandomGenerator {
public:
	RandomGenerator() 
		: randomEngine(std::random_device()())
		, randomDist(0.0, 1.0)
	{}
	
	// 0.0 ~ 1.0の範囲の一様分布乱数を返す
	double Get() const {
		return randomDist(randomEngine);
	}

private:
	std::mt19937 randomEngine;
	std::uniform_real_distribution<> randomDist;
};
}
