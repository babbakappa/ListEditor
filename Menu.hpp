#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <fstream>

class Menu {
public:
	static void PrintMenu(std::string& choice);
	static void AskWhereToTake(std::string& choice);
	static void AskWhereToOut(std::string& choice);
	static void PrintError(bool& failed);
	static void IfChosenFile(std::string& filepath);
	static void IfChosenInputFromKeyboard(int& number, bool& failed);
	static void IfChosenOutputOnScreen();
	static void PrintSuccessSave(std::string& filepath);
	static void SetRussianEncode();
	static void SetBGAndTXTColor(std::string& bgcolor, std::string& txtcolor);
	static void AskWhatToChangeFromColors(std::string& choice);
	static void PrintColortable(std::string& choice);
	static void ClearBuffer(int method);
	static void LoadSettings(std::string& bgcolor, std::string& txtcolor);
	static void SaveSettings(std::string& bgcolor, std::string& txtcolor);
	static void PrintProgramName();
};
#endif