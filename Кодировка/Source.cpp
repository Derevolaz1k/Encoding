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
	ofstream EnCode("encode.txt", ofstream::app);
	ElMenu(a.EnCode);
	newElMenu(a.DeCode);
	newElMenu(a.Exit);
	char sym;
	char sym1;
	int count = 1;
	int count1_1 = 1;
	
	string userText = "";//Before processing
	string code = "";//After processing
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
				if (sym1 == 13 && count1_1 == 3)
				{
					break;
				}

				switch (sym1)
				{
				case 72:count1_1--; break;
				case 80:count1_1++; break;
				case 13:
				{

					if (count1_1 == 3)
						break;
					if (count1_1 == 1) {


						cout << "Enter the text to add: ";
						getline(cin, userText);
						cout << "word " + userText << " the codding..." << endl;
						cout << coding(userText, code) << endl;
						EnCode.open("encode.txt", ofstream::app);
						EnCode << coding(userText, code);
						EnCode.close();
						system("pause");
					}

					if (count1_1 == 2)
						EnCode.open("encode.txt", ofstream::trunc);
					EnCode.close();
					cout << "Data deleted..";
				}
		
				
				}
				switch (count1_1)
				{
				case 1: menu1_1(a); break;
				case 2: menu1_2(a); break;
				case 3: menu1_3(a); break;
					default:
					if (count1_1 > 3)
					{
						count1_1 = 1;
						menu1_1(a);
					}
					if (count1_1 < 1)
					{
						count1_1 = 3;
						menu1_3(a);
					}
					break;
				}
			}

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
		
		MainMenu(count, a);
	}
	
	return 0;
}