//inclass4.cpp
//Name:Zhou Tian
//Course:16:332:503,Programming Finance
//Date of submission:2017/10/07
//Example:A recursive function that count the number of times that character c occurs in string s.

#include<iostream>
using namespace std;

#include<string>

//declare and initialize the function c_Count and counting number c_number
int c_Count(char*,char );
int c_number=0;

int main() {
	////declare and initialize the string s and character c
	string s;
	char c;
	//inputting string s and character c
	cout << "Please enter the string s: ";
	cin >> s;
	cout << "Please enter the character c: ";
	cin >> c;
	
	//transform the string to char pointer
	char*s_char = (char*)s.c_str();
	
	//run the function c_Count
	c_Count(s_char,c);
	cout << "The number of charactor c='"<<c<<"' occurs in the string s is: "<<c_number << endl;
	system("pause");
	return 0;
}

//function c_Count:count the number of character c occurs in the string s.
int c_Count(char*str,char c_f)
{
	if (*str=='\0')
		return 0;
	else {
		//count plus 1 when the element in the string is character c 
		if (*str == c_f)
			c_number = c_number + 1;
		//run the function
		c_Count(str + 1,c_f);
	}
	return 0;
}