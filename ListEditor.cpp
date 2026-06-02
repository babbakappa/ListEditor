#include "NoDuplicates.hpp"
#include "UniteTwo.hpp"
#include "NumberSorter.hpp"
#include "WordSorter.hpp"
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main() {
	string colortable = "0 - черный\n1 - синий\n2 - зеленый\n3 - голубой\n4 - красный\n5 - фиолетовый\n6 - желтый\n7 - белый\n8 - серый\n9 - светло-синий\nA - светло-зеленый\nB - светло-голубой\nC - светло-красный\nD - светло-фиолетовый\nE - светло-желтый\nF - ярко-белый";
	string bgcolor = "0";
	string txtcolor = "B";
	//для русского языка
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;

	do {
		string command = "color " + bgcolor + txtcolor;
		system("cls");
		system(command.c_str());
		//объекты для работы
		NoDuplicates Object1;
		UniteTwo Object2;
		NumberSorter Object3;
		WordSorter Object4;

		//пункты в меню
		cout << "List Editor v1.1\n\n";
		cout << "==========МЕНЮ==========\n\n";
		cout << "1. Удалить дубликаты из списка\n";
		cout << "2. Объединить два списка без дубликатов\n";
		cout << "3. Сортировать список чисел\n";
		cout << "4. Отсортировать слова по алфавиту\n";

		cout << "\n";
		cout << "0. Выход\n";
		cout << "-1. Информация о программе\n";
		cout << "-2. Поменять цвет текста или фона\n";
		cout << "\n";

		//выбор
		cout << "Выбор: ";
		cin >> choice;

		//меню
		system("cls");
		switch (choice) {

		case 1: {
			cout << "Загрузить из файла или введете список сами?\n";
			cout << "1. Из файла\n";
			cout << "2. Сам\n";
			int subchoice;
			cout << "Выбор: ";
			cin >> subchoice;

			if (subchoice == 1) {
				system("cls");
				string filepath;
				cout << "Введите путь к файлу: ";
				cin.ignore();
				getline(cin, filepath);
				Object1.ExtractData(filepath);
			}

			else if (subchoice == 2) {
				system("cls");
				int size;
				cout << "Введите количество элементов: ";
				cin >> size;
				cin.ignore();
				Object1.InputData(size);
			}

			else {
				system("cls");
				cout << "Выбран неверный вариант!\n";
				system("pause");
				cin.clear();
				cin.ignore(32767, '\n');
				break;
			}

			Object1.DeleteDuplicates();

			system("cls");
			cout << "Вывести измененный список на экран или сохранить в файл?\n";
			cout << "1. В файл\n";
			cout << "2. На экран\n";
			cout << "Выбор: ";
			cin >> subchoice;

			if (subchoice == 1) {
				system("cls");
				string filepath;
				cout << "Введите путь к файлу: ";
				cin.ignore();
				getline(cin, filepath);
				Object1.SaveData(filepath);
				system("cls");
				cout << "Данные сохранены в файл " << filepath << "\n";
				system("pause");
			}

			else if (subchoice == 2) {
				system("cls");
				cout << "Список:\n";
				Object1.OutputData();
				system("pause");
			}

			else {
				system("cls");
				cout << "Выбран неверный вариант!\n";
				system("pause");
				cin.clear();
				cin.ignore(32767, '\n');
			}

			break;
		}

		case 2: {
			system("cls");
			cout << "Первый список взять из файла или введете сами?\n";
			cout << "1.Из файла\n";
			cout << "2.Сам\n";
			cout << "Выбор: ";

			int subchoice1;
			cin >> subchoice1;
			cin.ignore();

			if (subchoice1 == 1) {
				system("cls");
				string filepath1;
				cout << "Введите путь к файлу первого списка: ";
				getline(cin, filepath1);
				Object2.ExtractDataFirst(filepath1);
			}
			else if (subchoice1 == 2) {
				system("cls");
				cout << "Введите количество элементов первого списка: ";
				int number;
				cin >> number;
				cin.ignore();
				Object2.InputFirst(number);
			}
			else {
				system("cls");
				cout << "Выбран неверный вариант!\n";
				system("pause");
				cin.clear();
				break;
			}

			system("cls");
			cout << "Второй список взять из файла или введете сами?\n";
			cout << "1.Из файла\n";
			cout << "2.Сам\n";
			cout << "Выбор: ";

			int subchoice2;
			cin >> subchoice2;


			if (subchoice2 == 1) {
				cin.ignore();
				system("cls");
				string filepath2;
				cout << "Введите путь к файлу второго списка: ";
				getline(cin, filepath2);
				Object2.ExtractDataSecond(filepath2);
			}
			else if (subchoice2 == 2) {
				system("cls");
				cout << "Введите количество элементов второго списка: ";
				int number;
				cin >> number;
				cin.ignore();
				Object2.InputSecond(number);
			}
			else {
				system("cls");
				cout << "Выбран неверный вариант!\n";
				system("pause");
				cin.clear();
				cin.ignore(32767, '\n');
				break;
			}

			Object2.UniteTwoArrays();

			system("cls");
			cout << "Списки объединены. Вывести итоговый список на экран или сохранить в файл?\n";
			cout << "1.Сохранить в файл\n";
			cout << "2.Вывести на экран\n";
			cout << "Выбор: ";
			int subchoice3;
			cin >> subchoice3;

			if (subchoice3 == 1) {
				cin.ignore();
				system("cls");
				string filepath3;
				cout << "Введите путь к файлу: ";
				getline(cin, filepath3);
				Object2.SaveData(filepath3);
				system("cls");
				cout << "Данные сохранены в файл " << filepath3 << "\n";
				system("pause");
			}

			else if (subchoice3 == 2) {
				system("cls");
				cout << "Список:\n";
				Object2.Print();
				system("pause");
			}

			else {
				system("cls");
				cout << "Выбран неверный вариант!\n";
				system("pause");
				cin.clear();
				cin.ignore(32767, '\n');
				break;
			}

			break;
		}

		case 3: {
			cout << "Введете список сами или загрузите файлом?\n";
			cout << "1.Из файла\n";
			cout << "2.Сам\n";
			cout << "Выбор: ";

			int subchoice;
			cin >> subchoice;

			system("cls");

			if (subchoice == 1) {
				cin.ignore();
				cout << "Введите ссылку на файл: ";
				string filepath;
				getline(cin, filepath);
				Object3.Extract(filepath);
			}

			else if (subchoice == 2) {
				cin.ignore();
				size_t n;
				cout << "Введите размер: ";
				cin >> n;
				cin.ignore();
				Object3.Input(n);
			}

			else {
				system("cls");
				cout << "Выбран неверный вариант!\n";
				system("pause");
				cin.clear();
				cin.ignore(32767, '\n');
				break;
			}

			system("cls");
			cout << "Какую сортировку выполнить?\n";
			cout << "1.От меньшего к большему\n";
			cout << "2.От большего к меньшему\n";
			cout << "Выбор: ";
			int subsubchoice;
			cin >> subsubchoice;

			system("cls");
			if (subsubchoice == 1) {
				Object3.SmallToBigSort();
			}
			else if (subsubchoice == 2) {
				Object3.BigToSmallSort();
			}
			else {
				cout << "Выбран неверный вариант!\n";
				system("pause");
				break;
			}

			cin.ignore();
			cout << "Вывести список на экран или сохранить в файл?\n";
			cout << "1.В файл\n";
			cout << "2.На экран\n";
			cout << "Выбор: ";
			int subchoice2;
			cin >> subchoice2;

			system("cls");
			if (subchoice2 == 1) {
				cin.ignore();
				string filepath;
				cout << "Введите ссылку на файл: ";
				getline(cin, filepath);
				Object3.Save(filepath);
				system("cls");
				cout << "Данные сохранены в файл " << filepath << "\n";
			}

			else if (subchoice2 == 2) {
				cout << "Список:\n";
				Object3.Print();
			}

			else {
				system("cls");
				cout << "Выбран неверный вариант!\n";
				system("pause");
				cin.clear();
				cin.ignore(32767, '\n');
				break;
			}

			system("pause");

			break;
		}

		case 4: {
			system("cls");
			cout << "Введете список сами или из файла?\n";
			cout << "1.Из файла\n";
			cout << "2.Сам\n";
			cout << "Выбор: ";
			int subchoice;
			cin >> subchoice;

			if (subchoice == 1) {
				system("cls");
				cin.ignore();
				cout << "Введите путь к файлу: ";
				string filepath;
				getline(cin, filepath);
				Object4.Extract(filepath);
			}

			else if (subchoice == 2) {
				system("cls");
				cout << "Введите количество элементов: ";
				int n;
				cin >> n;
				cin.ignore();
				Object4.Input(n);
			}

			else {
				system("cls");
				cout << "Введен неверный вариант!\n";
				cin.clear();
				cin.ignore(32767, '\n');
				system("pause");
				break;
			}

			system("cls");
			cout << "Каким образом отсортировать?\n";
			cout << "1.По афлавиту\n";
			cout << "2.По алфавиту наоборот\n";
			cout << "Выбор: ";
			int subchoice2;
			cin >> subchoice2;

			if (subchoice2 == 1) {
				Object4.AToZSort();
			}
			else if (subchoice2 == 2) {
				Object4.ZToASort();
			}
			else {
				cout << "Введен неверный вариант!\n";
				break;
			}

			system("cls");
			cout << "Вывести список на экран или сохранить в файл?\n";
			cout << "1.В файл\n";
			cout << "2.На экран\n";
			cout << "Выбор: ";
			int subchoice3;
			cin >> subchoice3;

			system("cls");
			if (subchoice3 == 1) {
				cin.ignore();
				system("cls");
				string filepath;
				cout << "Введите ссылку на файл: ";
				getline(cin, filepath);
				Object4.Save(filepath);
				system("cls");
				cout << "Данные сохранены в файл " << filepath << "\n";
			}

			else if (subchoice3 == 2) {
				cout << "Список:\n";
				Object4.Print();
			}

			else {
				cout << "Выбран неверный вариант!\n";
				system("pause");
				cin.clear();
				cin.ignore(32767, '\n');
				break;
			}
			system("pause");

			break;
		}

		case -1: {
			system("cls");
			cout << "Информация о программе: \n\n";
			cout << "List Editor - это программа для сортировки, фильтрации и обработки списков.\n";
			cout << "Эта программа подойет для работы с очень большими спсиками за счет алгоритмов O(n)\n";
			cout << "и эффективности самого C++, на котором написана эта программа.\n";
			cout << "Исходный код этой программы свободен для использования, редактирования, публикации\n";
			cout << "исходных кодов модифицированных версий и т.д.\n\n";
			system("pause");
			break;
		}

		case -2: {
			system("cls");
			cout << "Что поменять?\n";
			cout << "1.Цвет фона\n";
			cout << "2.Цвет текста\n";
			cout << "Выбор: ";
			int subchoice;
			cin >> subchoice;

			system("cls");
			cout << colortable << "\n\n";
			cout << "Выбор: ";
			if (subchoice == 1) {
				cin.ignore();
				getline(cin, bgcolor);
				break;
			}

			else if (subchoice == 2) {
				cin.ignore();
				getline(cin, txtcolor);
				break;
			}

			else {
				system("cls");
				cout << "Ошибка! Неверный вариант!\n";
				cin.clear();
				cin.ignore(32767, '\n');
				system("pause");
				break;
			}

			break;
		}

		default: {
			if (choice != 0) {
				system("cls");
				cout << "Выбран неверный вариант!\n";
				system("pause");
				cin.clear();
				cin.ignore(32767, '\n');
				break;
			}
		}
		}
	} while (choice != 0);

	cout << "Завершение работы...\n";

	return 0;
}

//Что нового в 1.1
//1.Исправление багов при вводе букв при выборе варианта
//2.Небольшое улучшение дизайна
//3.Добавление возможности изменить цвет фона и текста
//4.Оптимизация алгоритма в NoDuplicates
//5.Оптимизация алгоритма в UniteTwo
//6.Исправление багов чтения данных