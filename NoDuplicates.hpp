#ifndef NODUPLICATES_HPP
#define NODUPLICATES_HPP
#include "Methods.hpp"
#include <unordered_set>

class NoDuplicates : public Methods<std::string> {
public:
	void DeleteDuplicates();
};

#endif