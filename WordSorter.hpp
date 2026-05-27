#ifndef WORDSORTER_HPP
#define WORDSORTER_HPP
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
class WordSorter {
private:
	std::vector<std::string> array;
public:
	void Input(size_t n);
	void Print();
	void Save(std::string filepath);
	void Extract(std::string filepath);
	void AToZSort();
	void ZToASort();
};
#endif