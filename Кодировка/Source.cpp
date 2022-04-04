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
	while (sym = _getch()) 
	{
		switch (sym)
		{
			case 72:count--; break;//up
			case 80:count++; break;//down
			case 13: //enter
			{
				switch (count)
				{
					case 1:
					{
						menu1_1(a);
						while ((sym1 = _getch()))
						{
							if (sym1 == 13 && count1_1 == 3)
							{
								count = 1;
								count1_1 = 1;
								break;
							}
							switch (sym1)
							{
								case 72:count1_1--; break;
								case 80:count1_1++; break;
								case 13:
								{
									if (count1_1 == 1)
									{
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
									{
										EnCode.open("encode.txt", ofstream::trunc);
										EnCode.close();
										cout << "Data deleted..";
									}
								}
							}
							MainMenu1_1(count1_1, a);
						}
					}break;
					case 2:
					{
						char letter;
						int length = 0;
					//	int* indexArr = new int[length];
						userText = "";
						ifstream DeCode("encode.txt");
						getline(DeCode, userText);
						if (userText == "")
						{
							cout << "Error!" << endl;
							system("pause");
							break;
						}
						DeCode.close();
						for (int i = 0; i < userText.size(); i += 6)
						{
							//resizeArr(indexArr,length,TwoToTen(userText, i));
							letter = (int)TwoToTen(userText, i);
							cout << letter;
						}
						cout << endl;
						system("pause");
					}break;
					case 3:
					{
					cout << "Exit...";
					return 0;
					}break;
				}break;
			}break;
		}
		MainMenu(count, a);
	}
	
	return 0;
}