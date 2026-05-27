#include "UniteTwo.hpp"

using namespace std;

UniteTwo::UniteTwo() {}

UniteTwo::~UniteTwo()
{
	array1.clear();
	array1.shrink_to_fit();
	array2.clear();
	array2.shrink_to_fit();
}

void UniteTwo::Extract(const string& filepath, vector<string>& mas) {
	ifstream fin(filepath);
	if (fin.is_open() == false) {
		system("cls");
		cerr << "Ошибка! Файла не существует!\n";
		system("pause");
		return;
	}
	string temporary;
	while (fin >> temporary) {
		mas.push_back(temporary);
	}
	fin.close();
}

void UniteTwo::Input(size_t n, vector<string>& mas) {
	for (size_t i = 0; i < n; i++) {
		string temporary;
		getline(cin, temporary);
		mas.push_back(temporary);
	}
}

void UniteTwo::ExtractDataFirst(const string& filepath)
{
	UniteTwo::Extract(filepath, array1);
}

void UniteTwo::ExtractDataSecond(const string& filepath)
{
	UniteTwo::Extract(filepath, array2);
}

void UniteTwo::SaveData(const string& filepath) {
	ofstream fout(filepath);
	for (int i = 0; i < array3.size(); i++) {
		fout << array3[i] << "\n";
	}
	fout.close();
}

void UniteTwo::Print()
{
	for (int i = 0; i < array3.size(); i++) {
		cout << array3[i] << "\n";
	}
}

void UniteTwo::InputFirst(size_t n)
{
	UniteTwo::Input(n, array1);
}

void UniteTwo::InputSecond(size_t n)
{
	UniteTwo::Input(n, array2);
}

void UniteTwo::UniteTwoArrays()
{
	unordered_set<string> unique_set(array1.begin(), array1.end());
	unique_set.insert(array2.begin(), array2.end());
	array3.assign(unique_set.begin(), unique_set.end());
}