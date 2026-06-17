#ifndef METHODS_HPP
#define METHODS_HPP
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

template <class DataType>
class Methods {
protected:
	vector<DataType> array;
public:
	void ExtractData(string filepath) {
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

	void SaveData(string filepath) {
		ofstream fout(filepath);
		for (int i = 0; i < array.size(); i++) {
			fout << array[i] << "\n";
		}
	}

	void InputData(int size) {
		for (int i = 0; i < size; i++) {
			DataType element;
			getline(cin, element);
			array.push_back(element);
		}
	}

	void PrintData() {
		for (int i = 0; i < array.size(); i++) {
			cout << array[i] << "\n";
		}
		system("pause");
	}

	~Methods() = default;
};
#endif