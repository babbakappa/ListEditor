#include "NoDuplicates.hpp"

using namespace std;

NoDuplicates::NoDuplicates() {}

NoDuplicates::~NoDuplicates()
{
	array.clear();
	array.shrink_to_fit();
}

void NoDuplicates::ExtractData(string filepath)
{
	ifstream fin(filepath);
	if (fin.is_open() == false) {
		cout << "Ошибка! Файла не существует!\n";
		system("pause");
		return;
	}
	string temporary;
	while (fin >> temporary) {
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
	cout << "Список:\n";
	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << "\n";
	}
}

void NoDuplicates::DeleteDuplicates()
{
	unordered_set<string> seen; //хеш-таблица
	auto it = array.begin(); //указатель на начало массива
	//поиск
	while (it != array.end()) {
		if (seen.find(*it) != seen.end()) {
			it = array.erase(it); //удаление если есть
		}
		else {
			seen.insert(*it); //добавление в ином случае
			it++;
		}
	}
}