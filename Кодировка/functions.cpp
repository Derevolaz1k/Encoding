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
					std::cout << "|";
				else
					std::cout << " ";
			else if (i == 0 || i == rows - 1 || j == 0 || j == kols - 1)
				std::cout << "|";
			else if (j == kols)
				std::cout << "|";
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

void menu1_1(Interface& a)
{
	system("cls");
	ElMenu(a.EnCode_Add);
	newElMenu(a.EnCode_Clear);
	newElMenu(a.Exit);
}
void menu1_2(Interface& a)
{
	system("cls");
	newElMenu(a.EnCode_Add);
	ElMenu(a.EnCode_Clear);
	newElMenu(a.Exit);
}
void menu1_3(Interface& a)
{
	system("cls");
	newElMenu(a.EnCode_Add);
	newElMenu(a.EnCode_Clear);
	ElMenu(a.Exit);
}

std::string coding(std::string userText,std::string code)
{
	unsigned int x;
	for (int i = 0; i < userText.size(); i++)
	{
		x = (int)userText[i];
		code+= TenToTwo(x);
	}
	return code;
}
std::string TenToTwo(int x)
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
int TwoToTen(std::string &x)
{
	int count = 6;
	int n = stoi(x);
	int temp;
	int res=0;
	while (n/10>10)
	{
		temp = (n % 10);
		for (int i = 0; i < count; i++)
			temp *= 2;
		n /= 10;
		count--;
		res += temp;
	}
	if (n == 1)
		res += 1;
	return res;
}
void MainMenu(int count, Interface a)
{
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
void MainMenu1_1(int count1_1, Interface a)
{
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