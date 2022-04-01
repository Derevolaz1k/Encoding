#include <iostream>
#include <string>
#include<conio.h>
#include "functions.h"
#include "structures.h"
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	Interface a;
	ElMenu(a.EnCode);
	newElMenu(a.DeCode);
	newElMenu(a.Exit);
	char sym = _getch();
	int count = 1;
	
	while ((sym = _getch())) {
		if (sym == 72)//Вверх
			count--;
		else if (sym == 80)//Вниз
			count++;

		if (sym == 13) {
			switch (count)
			{
			case 1: 
			{
				cout << "Enter a message to encrypt: ";
				string userText;//До обработки
				string code;//На выходе после обработки
				getline(cin, userText);
				cout << "word " + userText << " the codding..." << endl;
				cout << coding(userText, code) << endl;
				ofstream EnCode("encode.txt");
				EnCode << coding(userText, code);
				EnCode.close(); 
			}
			break;
			case 2:cout << "Enter encrypted message: "; 
				break;
			case 3:cout << "Exit..."; 
				return 0;
				break;
			default:
				break;
			}
			break;
		}
		else
		switch (count)
		{
		case 1: menu1(a); break;
		case 2: menu2(a); break;
		case 3: menu3(a); break;
		default:
			if (count > 3)
			{
				count = 1;
				menu1(a);
			}
			if (count < 1)
			{
				count = 3;
				menu3(a);
			}
			break;
		}
	}
	
	return 0;
}