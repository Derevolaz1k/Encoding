#pragma once
#include <iostream>
struct Interface
{
	std::string EnCode = "EnCode";
	std::string DeCode = "DeCode";
	std::string Exit = "Exit";
	std::string EnCode_Clear = "Del file";
	std::string EnCode_Add = "Add text";
};
void newElMenu(std::string name);
void ElMenu(std::string name);
void menu1(Interface &a);
void menu2(Interface &a);
void menu3(Interface &a);
void menu1_1(Interface& a);
void menu1_2(Interface& a);
void menu1_3(Interface& a);
void MainMenu(int &count,Interface a);
void MainMenu1_1(int &count1_1, Interface a);
int myPow(int a, int b);
std::string coding(std::string userText, std::string code);
std::string TenToTwo(int x);
int TwoToTen(std::string &x,int &i);

