#ifndef WORDSORTER_HPP
#define WORDSORTER_HPP
#include "Methods.hpp"
#include <algorithm>
class WordSorter : public Methods<string> {
public:
	void AToZSort();
	void ZToASort();
};
#endif