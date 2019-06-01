#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> // для int --> string

using namespace std;

class String
{
private: string str;
public:

	String(int str1) // из int в строку
	{
		stringstream a; // stringstream позволяет преобразовать что угодно в строку
		a << str1;
		str = a.str();
	}

	friend ostream& operator <<(ostream& out, const String& symb)
	{
		out << symb.str;
		return out;
	}

	String(double str1) // из double в строку 
	{
		stringstream b; // stringstream позволяет преобразовать что угодно в строку 
		b << str1;
		str = b.str();
	}

	string Delete_symbol(string str1)
	{
		string symbol = ",";
		int symbolCount = 0;
		string current_str;
		for (int i = 0; i < str1.size(); i++)
		{
			if (isdigit(str1[i])) // isdigit() возвращает ненулевое значение, если аргумент ch является цифрой от 0 до 9, в противном случае возвращается 0 
			{
				current_str += str1[i];
			}
			if (str1[i] == symbol[0] && symbolCount == 0)
			{
				current_str += str1[i];
				symbolCount++;
			}
		}
		return current_str;
	}

	int& String_to_int(string str1) // из строки в int
	{
		string str = Delete_symbol(str1);
		int a = stoi(str);
		return a;
	}

	double& String_to_double(string str1) // из строки в double
	{
		//string str = Delete_symbol(str1);
		double b = stod(Delete_symbol(str1));
		return b;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	String Str1(500);
	String Str2(700.0);
	cout << "Из int в строку: " << Str1 << endl;
	cout << "Из double в строку: " << Str2 << endl;
	int str3 = Str1.String_to_int("Hibro500kek");
	double str4 = Str2.String_to_double("jfgdf77dg5,68g8fg");
	cout << "Из строки в int: " << str3 << endl;
	cout << "Из строки в double: " << str4 << endl;
	system("pause");
	return 0;
}