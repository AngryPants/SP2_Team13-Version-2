#include "GenerateRange.h"

unsigned int GenerateRange(unsigned int from, unsigned int to) {

	return (rand() % (to - from)) + from;

}

int GenerateRange(int from, int to) {

	return (rand() % (to - from)) + from;

}

float GenerateRange(float from, float to) {

	return (static_cast<float>(rand())/(static_cast <float>(RAND_MAX/to)) + from);

}