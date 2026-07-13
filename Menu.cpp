#include "Menu.hpp"

using namespace std;

void Menu::PrintMenu(string& choice)
{
	system("cls");
	cout << "==========МЕНЮ==========\n\n";
	cout << "1. Удалить дубликаты из списка\n";
	cout << "2. Объединить два списка без дубликатов\n";
	cout << "3. Сортировать список чисел\n";
	cout << "4. Отсортировать слова по алфавиту\n";
	cout << "5. Инвертировать список (БЕТА)\n";
	cout << "6. Выбрать рандомный элемент из списка (БЕТА)\n\n";
	cout << "0. Выход\n";
	cout << "-1. Информация о программе\n";
	cout << "-2. Поменять цвет текста или фона\n\n";
	cout << "Выбор: ";
	getline(cin, choice);
}

void Menu::AskWhereToTake(std::string& choice)
{
	system("cls");
	cout << "Загрузить список из файла или введете сами?\n";
	cout << "1. Из файла\n";
	cout << "2. Сам\n";
	cout << "Выбор: ";
	getline(cin, choice);
}

void Menu::AskWhereToOut(std::string& choice)
{
	system("cls");
	cout << "Вывести измененный список на экран или сохранить в файл?\n";
	cout << "1. В файл\n";
	cout << "2. На экран\n";
	cout << "Выбор: ";
	getline(cin, choice);
}

void Menu::PrintError(bool& failed)
{
	failed = true;
	system("cls");
	cout << "Ошибка!\n";
	system("pause");
}

void Menu::IfChosenFile(string& filepath)
{
	system("cls");
	cout << "Введите путь к файлу: ";
	getline(cin, filepath);
}

void Menu::IfChosenInputFromKeyboard(int& number, bool& failed)
{
	system("cls");
	cout << "Введите количество элементов: ";
	if (cin >> number) {
		failed = false;
	}
	else {
		failed = true;
	}
	cout << "Вводите элементы списка:\n";
}

void Menu::IfChosenOutputOnScreen()
{
	system("cls");
	cout << "Список элементов:\n";
}

void Menu::PrintSuccessSave(string& filepath)
{
	system("cls");
	cout << "Список сохранен в файл " << filepath << "\n";
	system("pause");
}

void Menu::SetRussianEncode()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void Menu::SetBGAndTXTColor(string& bgcolor, string& txtcolor)
{
	string command = "color " + bgcolor + txtcolor;
	system(command.c_str());
}

void Menu::AskWhatToChangeFromColors(std::string& choice)
{
	system("cls");
	cout << "Что поменять?\n";
	cout << "1.Цвет фона\n";
	cout << "2.Цвет текста\n";
	cout << "Выбор: ";
	getline(cin, choice);
}

void Menu::PrintColortable(std::string& choice)
{
	system("cls");
	std::string colortable = "0 - черный\n1 - синий\n2 - зеленый\n3 - голубой\n4 - красный\n5 - фиолетовый\n6 - желтый\n7 - белый\n8 - серый\n9 - светло-синий\nA - светло-зеленый\nB - светло-голубой\nC - светло-красный\nD - светло-фиолетовый\nE - светло-желтый\nF - ярко-белый";
	cout << colortable << "\n\n";
	cout << "Выбор: ";
	getline(cin, choice);
}

void Menu::ClearBuffer(int method)
{
	if (method == 1) {
		cin.ignore();
	}
	else if (method == 2) {
		cin.clear();
		cin.ignore(10000, '\n');
	}
}

void Menu::LoadSettings(std::string& bgcolor, std::string& txtcolor)
{
	ifstream fin("settings.txt");
	if (fin.is_open() == false) {
		cout << "Ошибка! Файла настроек не существует!\n";
		system("pause");
		return;
	}
	fin >> bgcolor >> txtcolor;
	if (bgcolor == "" or txtcolor == "") {
		bgcolor = "0";
		txtcolor = "0";
	}
	Menu::SetBGAndTXTColor(bgcolor, txtcolor);
	fin.close();
}

void Menu::SaveSettings(std::string& bgcolor, std::string& txtcolor)
{
	ofstream fout("settings.txt");
	fout << bgcolor << "\n";
	fout << txtcolor;
	fout.close();
}

void Menu::PrintProgramName()
{
	cout << "#    \n";
	cout << "#    \n";
	cout << "#    \n";
	cout << "#    \n";
	cout << "#####\n";
}
