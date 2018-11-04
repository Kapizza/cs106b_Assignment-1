/*
* File: NumericConversions.cpp
* ---------------------------
* Name: Daviti Gochitashvili
* Section: 9
* This file is the starter project for the Numeric Conversions problem.
* [TODO: rewrite the documentation]
*/

#include <iostream>
#include <string>
#include "console.h"
using namespace std;

/* Function prototypes */
string intToString(int n);
int stringToInt(string str);

/* Main program */

int main() {
	cout << intToString(0) << endl;
	cout << stringToInt("0")<<endl;
	return 0;
}
/* 
This method converts int to string using recursion.
*/
string intToString(int n){
	if(n/10==0){
		int remainder = (n%10);
		string str = "";
		if(remainder<0){
			remainder=-remainder;
			str = "-";
		}
		str = str + string()+ char(remainder+'0');
		return str;
	} else {
		int remainder = (n%10);
		if(remainder<0){
			remainder=-remainder;
		}
		string str = string() + char(remainder+'0');
		return (intToString(n/10)+ str);
	}
}

/* 
This method converts string to int using recursion.
*/
int stringToInt(string str){
	if(str.length()==0){
		return  0;
	} else {
		int sign = 1;
		if(str[0]=='-'){
			str = str.substr(1);
			sign = -1;
		}
		char ch = str[str.length()-1]-'0';
		return stringToInt(str.substr(0,str.length()-1))*10*sign + sign*ch;
	}
}