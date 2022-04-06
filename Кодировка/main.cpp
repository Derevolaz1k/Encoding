#include <iostream>
#include <string>
#include<conio.h>
#include "functions.h"
#include <fstream>


using namespace std;
int main()
{
	system("color 0A");
	setlocale(LC_ALL, "Ru");
	Interface InterfaceJbject;
	ofstream EnCode("encode.txt", ofstream::app);//creating a text file
	EnCode.close();
	char symbolMenu;
	char sym1;
	int countMenu = 1;//counter tabs in mein menu
	int countMenu1_1 = 1;//counter tabs in secondary menu
	MainMenu(countMenu, InterfaceJbject);//Conclution Mein menu
	string userText = "";//Before processing
	string code = "";//After processing
	while (symbolMenu = _getch())//Always update press button in mein menu
	{
		switch (symbolMenu)
		{
			case 72:countMenu--; 
				break;//up
			case 80:countMenu++; 
				break;//down
			case 13: //enter
			{
				switch (countMenu)
				{
					case 1://First tab in main menu
					{
						menu1_1(InterfaceJbject);
						while (sym1 = _getch()) //Always update press button in secondary menu
						{
							if (sym1 == 13 && countMenu1_1 == 3)//exit in main menu
							{
								countMenu = 1;
								countMenu1_1 = 1;
								break;
							}
							switch (sym1)
							{
								case 72:countMenu1_1--;
									break;
								case 80:countMenu1_1++;
									break;
								case 13:
								{
									if (countMenu1_1 == 1)//first tab(add text and coding)
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
									if (countMenu1_1 == 2)//second tab(delete text)
									{
										EnCode.open("encode.txt", ofstream::trunc);
										EnCode.close();
										cout << "Data deleted..";
									}
								}
							}
							MainMenu1_1(countMenu1_1, InterfaceJbject);//update secondary menu
						}
					}
					break;
					case 2://decoding
					{
						char letter;
						int length = 0;
						//int* indexArr = new int[length];
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
		MainMenu(countMenu, InterfaceJbject);//update main menu
	}
	
	return 0;
}