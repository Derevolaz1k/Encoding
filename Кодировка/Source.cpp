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
	char sym1 = _getch();
	int count = 1;
	int count1_1 = 1;
	string userText;//Before processing
	string code;//After processing
	ofstream EnCode("encode.txt");
	while ((sym = _getch())) {
		switch (sym)
		{
		case 72:count--; break;
		case 80:count++; break;
		case 13: {switch (count)
		{
		case 1:
		{
			menu1_1(a);

			while ((sym1 = _getch())) {
				switch (sym1)
				{
				case 72:count1_1--; break;
				case 80:count1_1++; break;
				case 13: 
				{
					switch (count1_1)
				case 1: {
						cout << "Enter the text to add: ";
						getline(cin, userText);
						cout << "word " + userText << " the codding..." << endl;
						cout << coding(userText, code) << endl;
						EnCode.open("encode.txt", ios_base::app);
						EnCode << coding(userText, code);
						EnCode.close();
						system("pause");
						}
				}
				default:
					break;
				}
				switch (count1_1)
				{
				case 1: menu1_1(a); break;
				case 2: menu1_2(a); break;
				case 3: menu1_3(a); break;
				case 4: menu1_4(a); break;
				default:
					if (count1_1 > 4)
					{
						count1_1 = 1;
						menu1_1(a);
					}
					if (count1_1 < 1)
					{
						count1_1 = 4;
						menu1_4(a);
					}
					break;
				}
			}

			cout << "Enter a message to encrypt: ";
			getline(cin, userText);
			cout << "word " + userText << " the codding..." << endl;
			cout << coding(userText, code) << endl;
			EnCode.open("encode.txt");
			EnCode << coding(userText, code);
			EnCode.close();
			system("pause");
		}
		break;
		case 2:cout << "Enter encrypted message: ";
			break;
		case 3:cout << "Exit...";
			return 0;
			break;
		default:
			break;
		}break;
		}
		default:
			break;
		}
		
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