#include "dice.h"

#include <ctime>
#include <cstdlib>

namespace Utilities {
	/**
  Rolls some dice.
  @param n Number of dice to roll
  @param f Faces of each die
  @param m Modifier to sum of dice
  @return Dice roll modified
  */
	int rollDice(const unsigned int n, const unsigned int f, const int m)
	{
    static bool initialized = false;
    if (!initialized)
    {
      std::srand(static_cast<unsigned int>(std::time(0)));
      initialized = true;
    }
    unsigned int sum = 0;
    for (unsigned int x = 0; x < n; ++x)
    {
      sum += (std::rand() % f) + 1;
    }
    return sum + m;
	}
}