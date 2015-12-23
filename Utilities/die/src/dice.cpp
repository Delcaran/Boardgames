#include <dice.h>

#include <ctime>
#include <cstdlib>

namespace Utilities {
	/**
	To be called once before using any other function of this library
	*/
	bool init()
	{
		static bool initialized = false;
		if(!initialized) {
			std::srand(static_cast<unsigned int>(std::time(0)));
			initialized = true;
		}
		return initialized;
	}

	/**
	Roll 1df+0
	*/
	unsigned int roll(const unsigned int f)
	{
		return (std::rand() % f) + 1;
	}

	/**
	Roll ndf+0
	*/
	unsigned int roll(const unsigned int n, const unsigned int f)
	{
		unsigned int sum = 0;
		for(unsigned int x = 0; x < n; ++x) {
			sum += roll(f);
		}
		return sum;
	}

	/**
	Roll ndf+m
	*/
	int roll(const unsigned int n, const unsigned int f, const int m)
	{
		return roll(n, f) + m;
	}
}