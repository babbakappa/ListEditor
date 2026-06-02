#ifndef UNITETWO_HPP
#define UNITETWO_HPP
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_set>

class UniteTwo {
private:
	std::vector<std::string> array1, array2, array3;
	void Extract(const std::string& filepath, std::vector<std::string>& mas);
	void Input(size_t n, std::vector<std::string>& mas);
public:
	void ExtractDataFirst(const std::string& filepath);
	void ExtractDataSecond(const std::string& filepath);
	void SaveData(const std::string& filepath);
	void Print();
	void InputFirst(size_t n);
	void InputSecond(size_t n);
	void UniteTwoArrays();
};

#endif