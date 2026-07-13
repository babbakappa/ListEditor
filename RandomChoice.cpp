#include "RandomChoice.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;

string RandomChoice::PickRandom()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	int minidx = 0;
	int maxidx = array.size() - 1;

	int ranidx = minidx + std::rand() % (maxidx - minidx + 1);

	return array[ranidx];
}
