#include "NumberSorter.hpp"

using namespace std;

NumberSorter::NumberSorter() {}

NumberSorter::~NumberSorter()
{
	array.clear();
	array.shrink_to_fit();
}

void NumberSorter::Input(size_t n) {
	for (size_t i = 0; i < n; i++) {
		double temp;
		cin >> temp;
		array.push_back(temp);
	}
}

void NumberSorter::Print() {
	for (size_t i = 0; i < array.size(); i++) {
		cout << array[i] << "\n";
	}
}

void NumberSorter::Save(string filepath) {
	ofstream fout(filepath);
	for (size_t i = 0; i < array.size(); i++) {
		fout << array[i] << "\n";
	}
	fout.close();
}

void NumberSorter::Extract(string filepath) {
	ifstream fin(filepath);
	if (fin.is_open() == false) {
		cout << "Ошибка! Файла не существует!\n";
		return;
	}
	string temp;
	while (fin >> temp) {
		double elem = stod(temp);
		array.push_back(elem);
	}
	fin.close();
}

void NumberSorter::BigToSmallSort() {
	sort(array.begin(), array.end(), [](double a, double b) { return a > b; });
}

void NumberSorter::SmallToBigSort() {
	sort(array.begin(), array.end(), [](double a, double b) { return a < b; });
}