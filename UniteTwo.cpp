#include "UniteTwo.hpp"

using namespace std;

void UniteTwo::ExtractDataFirst(const string& filepath)
{
	ExtractData(filepath);
}

void UniteTwo::ExtractDataSecond(const string& filepath)
{
	ifstream fin(filepath);
	if (fin.is_open() == false) {
		cout << "Ошибка! Файла не существует!\n";
		system("pause");
		return;
	}
	string temporary;
	while (getline(fin, temporary)) {
		array2.push_back(temporary);
	}
	fin.close();
}

void UniteTwo::InputFirst(size_t n)
{
	Methods::InputData(n);
}

void UniteTwo::InputSecond(size_t n)
{
	for (int i = 0; i < n; i++) {
		string element;
		getline(cin, element);
		array2.push_back(element);
	}
}

void UniteTwo::UniteTwoArrays()
{
	unordered_set<string> unique_set;
	unique_set.reserve(array.size() + array2.size());
	unique_set.insert(array.begin(), array.end());
	unique_set.insert(array2.begin(), array2.end());
	array.clear();
	for (auto elem : unique_set) {
		array.push_back(elem);
	}
}