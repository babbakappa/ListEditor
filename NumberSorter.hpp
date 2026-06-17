#ifndef NUMBERSORTER_HPP
#define NUMBERSORTER_HPP
#include <algorithm>
#include "Methods.hpp"

class NumberSorter : public Methods<double> {
public:
	void SmallToBigSort();
	void BigToSmallSort();
	void ExtractDataNS(std::string filepath);
	void InputDataNS(int n, bool& failed);
};
#endif