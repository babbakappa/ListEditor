#ifndef UNITETWO_HPP
#define UNITETWO_HPP
#include "Methods.hpp"
#include <unordered_set>

class UniteTwo : public Methods<string> {
public:
	std::vector<std::string> array2;
	void ExtractDataFirst(const std::string& filepath);
	void ExtractDataSecond(const std::string& filepath);
	void InputFirst(size_t n);
	void InputSecond(size_t n);
	void UniteTwoArrays();
};

#endif