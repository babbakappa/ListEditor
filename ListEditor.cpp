#include "NoDuplicates.hpp"
#include "UniteTwo.hpp"
#include "NumberSorter.hpp"
#include "WordSorter.hpp"
#include "Inverse.hpp"
#include "RandomChoice.hpp"
#include "Menu.hpp"

using namespace std;

int main() {
	Menu::SetRussianEncode();

	string choice;
	string bgcolor, txtcolor;

	Menu::LoadSettings(bgcolor, txtcolor);

	do {

		bool failed = false;

		Menu::PrintMenu(choice);

		if (choice == "1") {
			NoDuplicates Object1;

			string subchoice;
			Menu::AskWhereToTake(subchoice);

			if (subchoice == "1") {
				string filepath;
				Menu::IfChosenFile(filepath);
				Object1.ExtractData(filepath);
			}

			else if (subchoice == "2") {
				int size;
				Menu::IfChosenInputFromKeyboard(size, failed);
				Menu::ClearBuffer(1);

				if (failed == true) {
					Menu::PrintError(failed);
					Menu::ClearBuffer(2);
					continue;
				}

				Object1.InputData(size);
			}

			else {
				Menu::PrintError(failed);
			}

			if (failed == true) {
				continue;
			}

			Object1.DeleteDuplicates();

			Menu::AskWhereToOut(subchoice);

			if (subchoice == "1") {
				string filepath;
				Menu::IfChosenFile(filepath);
				Object1.SaveData(filepath);
				Menu::PrintSuccessSave(filepath);
			}

			else if (subchoice == "2") {
				Menu::IfChosenOutputOnScreen();
				Object1.PrintData();
				system("pause");
			}

			else {
				Menu::PrintError(failed);
			}
		}

		else if (choice == "2") {
			UniteTwo Object2;

			string subchoice1;
			Menu::AskWhereToTake(subchoice1);

			if (subchoice1 == "1") {
				string filepath1;
				Menu::IfChosenFile(filepath1);
				Object2.ExtractDataFirst(filepath1);
			}
			else if (subchoice1 == "2") {
				int number;
				Menu::IfChosenInputFromKeyboard(number, failed);
				Menu::ClearBuffer(1);
				if (failed == true) {
					Menu::PrintError(failed);
					Menu::ClearBuffer(2);
					continue;
				}
				Object2.InputFirst(number);
			}
			else {
				Menu::PrintError(failed);
			}

			if (failed == true) {
				continue;
			}

			string subchoice2;
			Menu::AskWhereToTake(subchoice2);

			if (subchoice2 == "1") {
				string filepath2;
				Menu::IfChosenFile(filepath2);
				Object2.ExtractDataSecond(filepath2);
			}
			else if (subchoice2 == "2") {
				int number;
				Menu::IfChosenInputFromKeyboard(number, failed);
				Menu::ClearBuffer(1);
				if (failed == true) {
					Menu::PrintError(failed);
					Menu::ClearBuffer(2);
					continue;
				}
				Object2.InputSecond(number);
			}
			else {
				Menu::PrintError(failed);
			}

			if (failed == true) {
				continue;
			}

			Object2.UniteTwoArrays();

			string subchoice3;
			Menu::AskWhereToOut(subchoice3);

			if (subchoice3 == "1") {
				string filepath3;
				Menu::IfChosenFile(filepath3);
				Object2.SaveData(filepath3);
				Menu::PrintSuccessSave(filepath3);
			}

			else if (subchoice3 == "2") {
				Menu::IfChosenOutputOnScreen();
				Object2.PrintData();
			}

			else {
				Menu::PrintError(failed);
			}
		}

		else if (choice == "3") {
			NumberSorter Object3;

			string subchoice;
			Menu::AskWhereToTake(subchoice);

			if (subchoice == "1") {
				string filepath;
				Menu::IfChosenFile(filepath);
				Object3.ExtractDataNS(filepath);
			}

			else if (subchoice == "2") {
				int n;
				Menu::IfChosenInputFromKeyboard(n, failed);
				Menu::ClearBuffer(1);
				if (failed == true) {
					Menu::PrintError(failed);
					Menu::ClearBuffer(2);
					continue;
				}
				Object3.InputDataNS(n, failed);
			}

			else {
				Menu::PrintError(failed);
			}

			if (failed == true) {
				Menu::ClearBuffer(2);
				Menu::PrintError(failed);
				continue;
			}

			Menu::ClearBuffer(1);
			system("cls");
			cout << "Какую сортировку выполнить?\n";
			cout << "1.От меньшего к большему\n";
			cout << "2.От большего к меньшему\n";
			cout << "Выбор: ";
			string subsubchoice;
			getline(cin, subsubchoice);
			
			if (subsubchoice == "1") {
				Object3.SmallToBigSort();
			}
			else if (subsubchoice == "2") {
				Object3.BigToSmallSort();
			}
			else {
				Menu::PrintError(failed);
			}

			if (failed == true) {
				continue;
			}

			string subchoice2;
			Menu::AskWhereToOut(subchoice2);

			if (subchoice2 == "1") {
				string filepath;
				Menu::IfChosenFile(filepath);
				Object3.SaveData(filepath);
				Menu::PrintSuccessSave(filepath);
			}

			else if (subchoice2 == "2") {
				Menu::IfChosenOutputOnScreen();
				Object3.PrintData();
			}

			else {
				Menu::PrintError(failed);
			}

		}

		else if (choice == "4") {
			WordSorter Object4;

			string subchoice;
			Menu::AskWhereToTake(subchoice);

			if (subchoice == "1") {
				string filepath;
				Menu::IfChosenFile(filepath);
				Object4.ExtractData(filepath);
			}

			else if (subchoice == "2") {
				int n;
				Menu::IfChosenInputFromKeyboard(n, failed);
				Menu::ClearBuffer(1);
				if (failed == true) {
					Menu::PrintError(failed);
					Menu::ClearBuffer(2);
					continue;
				}
				Object4.InputData(n);
			}

			else {
				Menu::PrintError(failed);
			}

			if (failed == true) {
				continue;
			}

			system("cls");
			cout << "Каким образом отсортировать?\n";
			cout << "1.По афлавиту\n";
			cout << "2.По алфавиту наоборот\n";
			cout << "Выбор: ";
			string subchoice2;
			getline(cin, subchoice2);

			if (subchoice2 == "1") {
				Object4.AToZSort();
			}
			else if (subchoice2 == "2") {
				Object4.ZToASort();
			}
			else {
				Menu::PrintError(failed);
			}

			string subchoice3;
			Menu::AskWhereToOut(subchoice3);

			if (subchoice3 == "1") {
				string filepath;
				Menu::IfChosenFile(filepath);
				Object4.SaveData(filepath);
				Menu::PrintSuccessSave(filepath);
			}

			else if (subchoice3 == "2") {
				Menu::IfChosenOutputOnScreen();
				Object4.PrintData();
			}

			else {
				Menu::PrintError(failed);
			}
		}

		//довести до ума
		else if (choice == "5") {
			Inverse Object5;

			int n;
			Menu::IfChosenInputFromKeyboard(n, failed);
			Menu::ClearBuffer(1);
			Object5.InputData(n);
			Object5.InverseList();
			Object5.PrintData();
			system("pause");
		}

		//довести до ума тоже
		else if (choice == "6") {
			RandomChoice Object6;

			string result;
			int n;
			Menu::IfChosenInputFromKeyboard(n, failed);
			Menu::ClearBuffer(1);
			Object6.InputData(n);
			result = Object6.PickRandom();
			cout << "\n";
			cout << result << "\n";
			system("pause");
		}

		else if (choice == "-1") {
			system("cls");
			cout << "Информация о программе: \n\n";
			cout << "List Editor - это программа для сортировки, фильтрации и обработки списков. Эта\n";
			cout << "программа подойдет для работы с очень большими списками за счет алгоритмов O(n)\n";
			cout << "и O(n*log(n)).\n\n";
			cout << "Исходный код этой программы свободен для использования, редактирования, публикации\n";
			cout << "исходных кодов модифицированных версий и т.д.\n\n";
			system("pause");
		}

		else if (choice == "-2")  {

			string subchoice;
			Menu::AskWhatToChangeFromColors(subchoice);

			if (subchoice == "1") {
				Menu::PrintColortable(bgcolor);
			}

			else if (subchoice == "2") {
				Menu::PrintColortable(txtcolor);
			}

			else {
				Menu::PrintError(failed);
			}

			Menu::SetBGAndTXTColor(bgcolor, txtcolor);
		}

		else {
			if (choice != "0") {
				Menu::PrintError(failed);
			}
		}

	} while (choice != "0");

	system("cls");
	cout << "Завершение работы...\n";
	Menu::SaveSettings(bgcolor, txtcolor);

	return 0;
}

//Изменения в 1.1
//1.Исправление багов при вводе букв при выборе варианта
//2.Небольшое улучшение дизайна
//3.Добавление возможности изменить цвет фона и текста
//4.Оптимизация алгоритма в NoDuplicates
//5.Оптимизация алгоритма в UniteTwo
//6.Исправление багов чтения данных

//Изменения в 1.2
//1.Добавление отдельного класса для вывода текста в меню
//2.Небольшая оптимизация кода
//3.Глобальное изменение работы меню
//4.Немного изменено оформление
//5.Создан базовый класс для всех методов
//6.Добавлено сохранение настройки цветов

//Изменения в 1.3
//1.Исправление некоторых багов
//2.Добавление метода инверсирования списка

