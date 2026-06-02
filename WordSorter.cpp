#include "WordSorter.hpp"

using namespace std;

void WordSorter::Print() {
	for (size_t i = 0; i < array.size(); i++) {
		cout << array[i] << "\n";
	}
}

void WordSorter::Input(size_t n) {
	for (size_t i = 0; i < n; i++) {
		string temp;
		getline(cin, temp);
		array.push_back(temp);
	}
}

void WordSorter::Extract(string filepath) {
	ifstream fin(filepath);
	string temp;
	while (fin >> temp) {
		array.push_back(temp);
	}
	fin.close();
}

void WordSorter::Save(string filepath) {
	ofstream fout(filepath);
	for (size_t i = 0; i < array.size(); i++) {
		fout << array[i] << "\n";
	}
}

void WordSorter::AToZSort() {
	sort(array.begin(), array.end(), [](string a, string b) { return a < b; });
}

void WordSorter::ZToASort() {
	sort(array.begin(), array.end(), [](string a, string b) { return a > b; });
}

