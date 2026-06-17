#include "NumberSorter.hpp"

using namespace std;

void NumberSorter::BigToSmallSort() {
	sort(array.begin(), array.end(), [](double a, double b) { return a > b; });
}

void NumberSorter::SmallToBigSort() {
	sort(array.begin(), array.end(), [](double a, double b) { return a < b; });
}

void NumberSorter::ExtractDataNS(string filepath)
{
	ifstream fin(filepath);
	if (fin.is_open() == false) {
		cout << "Ошибка! Файла не существует!\n";
		system("pause");
		return;
	}
	double temporary;
	while (fin >> temporary) {
		array.push_back(temporary);
	}
	fin.close();
}

void NumberSorter::InputDataNS(int n, bool& failed)
{
	for (int i = 0; i < n; i++) {
		double element;
		if (cin >> element) {
			array.push_back(element);
		}
		else {
			failed = true;
			return;
		}
	}
}