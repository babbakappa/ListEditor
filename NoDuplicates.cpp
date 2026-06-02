#include "NoDuplicates.hpp"

using namespace std;

void NoDuplicates::ExtractData(string filepath)
{
	ifstream fin(filepath);
	if (fin.is_open() == false) {
		cout << "Ошибка! Файла не существует!\n";
		system("pause");
		return;
	}
	string temporary;
	while (getline(fin, temporary)) {
		array.push_back(temporary);
	}
	fin.close();
}

void NoDuplicates::SaveData(std::string filepath)
{
	ofstream fout(filepath);
	for (int i = 0; i < array.size(); i++) {
		fout << array[i] << "\n";
	}
}

void NoDuplicates::InputData(int size)
{
	for (int i = 0; i < size; i++) {
		string element;
		getline(cin, element);
		array.push_back(element);
	}
}

void NoDuplicates::OutputData()
{
	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << "\n";
	}
}

void NoDuplicates::DeleteDuplicates()
{
	unordered_set<string> seen;
	seen.reserve(array.size());
	auto new_end = std::remove_if(array.begin(), array.end(), [&seen](const string& str) {
		return !seen.insert(str).second;
		});
	array.erase(new_end, array.end());
}

