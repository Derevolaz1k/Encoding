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
int TwoToTen(std::string &x,int &i)
{
	int n=0;
	int count = 0;
	{
		n = 0;
		for (int j = i; j < i + 7; j++)
		{
			if (j == i && (x[j] - 48) == 1)
				n += 1;
			else if ((x[j] - 48) == 1)
				n += myPow(x[j], count-1);//minus 1, becouse 2th system,and first number have zero index
			count++;
		}
		i++;
	}
	return n;
}

//void resizeArr(int*&arr, int &length, int num)
//{
//	length += 1;
//	int* arr2 = new int[length];
//	for (int i = 0; i < length; i++)
//	{
//		if (i == length - 1)
//			arr2[i] = num;
//		else
//		arr2[i] = arr[i];
//	}
//	delete[]arr;
//	arr = new int[length];
//	for (int i = 0; i < length; i++)
//	{
//		arr[i] = arr2[i];
//	}
//	delete[]arr2;
//	arr2 = arr;
//}
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
int myPow(int a, int b)
{
	if (a == 0)
		return 0;
	a = 2;
	int temp = a;
	for (int i = 0; i < b; i++)
		a *= temp;
	return a;
}