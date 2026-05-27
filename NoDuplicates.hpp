#ifndef NODUPLICATES_HPP
#define NODUPLICATES_HPP
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>

class NoDuplicates {
private:
	std::vector<std::string> array;
public:
	NoDuplicates();
	~NoDuplicates();
	void ExtractData(std::string filepath);
	void SaveData(std::string filepath);
	void InputData(int size);
	void OutputData();
	void DeleteDuplicates();
};

#endif // !NODUPLICATES_HPP