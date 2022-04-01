#include "functions.h"
#include "structures.h"
#include <string>

void newElMenu(std::string name)
{
	int text;
	int rows = 5;
	int kols = 15;
	if ((kols - name.size()) % 2 == 1)
		kols++;
	text = (kols - name.size()) / 2;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < kols; j++)
		{
			if (i == 2)
				if (j >= text && j < kols - text)
					std::cout << name[j - text];
				else if (j == 0 || j == kols-1)
					std::cout << "#";
				else 
					std::cout << " ";
					else if (i == 0 || i == rows - 1 || j == 0 || j == kols - 1)
						std::cout << "#";
							else if (j == kols)
								std::cout << "#";
									else
										std::cout << " ";
		}
		
		
		std::cout << std::endl;
	}

}

void ElMenu(std::string name)
{
	int text;
	int rows = 5;
	int kols = 15;
	if ((kols - name.size()) % 2 == 1)
		kols++;
	text = (kols - name.size()) / 2;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < kols; j++)
		{
			if (i == 2)
				if (j >= text && j < kols - text)
					std::cout << name[j - text];
				else if (j == 0 || j == kols - 1)
					std::cout << "$";
				else
					std::cout << " ";
			else if (i == 0 || i == rows - 1 || j == 0 || j == kols - 1)
				std::cout << "$";
			else if (j == kols)
				std::cout << "$";
			else
				std::cout << " ";
		}


		std::cout << std::endl;
	}
}

void menu1(Interface &a)
{
	system("cls");
	ElMenu(a.EnCode);
	newElMenu(a.DeCode);
	newElMenu(a.Exit);
}

void menu2(Interface &a)
{
	system("cls");
	newElMenu(a.EnCode);
	ElMenu(a.DeCode);
	newElMenu(a.Exit);
}

void menu3(Interface &a)
{
	system("cls");
	newElMenu(a.EnCode);
	newElMenu(a.DeCode);
	ElMenu(a.Exit);
}

std::string coding(std::string userText,std::string code)
{
	unsigned int x;
	for (int i = 0; i < userText.size(); i++)
	{
		x = (int)userText[i];
		code+=TTT(x);
	}
	return code;
}
std::string TTT(int x)
{
	std::string x2th="";
	do
	{
		x2th += std::to_string(x % 2);
		x /= 2;
	} while (x != 0);
	if (x2th.size() < 7)
		x2th += "0";
	return x2th;
}