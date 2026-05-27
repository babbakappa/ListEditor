#ifndef NUMBERSORTER_HPP
#define NUMBERSORTER_HPP
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
class NumberSorter {
private:
	std::vector<double> array;
public:
	NumberSorter();
	~NumberSorter();
	void Input(size_t n);
	void Print();
	void Save(std::string filepath);
	void Extract(std::string filepath);
	void SmallToBigSort();
	void BigToSmallSort();
};
#endif // !LISTSORTER_HPP