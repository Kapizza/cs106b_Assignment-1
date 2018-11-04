/*
* File: FleschKincaid.cpp
* ----------------------
* Name: Daviti Gochitashvili
* Section: 9
* This file is the starter project for the Flesch-Kincaid problem.
* [TODO: rewrite the documentation]
*/

#include <iostream>
#include "console.h"
#include "filelib.h"
#include "simpio.h"
#include "tokenscanner.h"
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

const double c0 = -15.59;
const double c1 = 0.39;
const double c2 = 11.8;

/* Function prototypes */
bool containsSym(string str);
bool isVowel(char ch);
int countSyllables(string str);
double calculateScore();

/* Main program */
int main() {
	cout<<calculateScore()<<endl;
	return 0;
}

/* 
This method reads file given by user and calculates score.
*/
double calculateScore(){
	ifstream file;
	promptUserForFile(file, "Please enter file name: ");
	TokenScanner scanner(file);
	scanner.addWordCharacters("\'");
	scanner.ignoreWhitespace() ;
	int words = 0;
	int sentences = 0;
	int syllabels = 0;
	while(scanner.hasMoreTokens()){
		string token = scanner.nextToken();
		if(isalpha(token[0])){
			words++;
			syllabels += countSyllables(token);
		}
		if(containsSym(token)){
			sentences++;
		}
	}
	return c0+c1*(double(words)/sentences)+c2*(syllabels/double(words));
}

/* 
This method checks if the char is a vowel.
*/
bool containsSym(string str){
	if (str.find('?') != string::npos ||  str.find('!') != string::npos || str.find('.') != string::npos) {
		return true;
	}
	return false;
}

/* 
This method checks if the char is a vowel.
*/
bool isVowel(char ch){
	if(ch == 'a'|| ch == 'e' || ch == 'i'|| ch == 'o' || ch == 'u' || ch == 'y' ){
		return true;
	}
	return false;
}

/* 
This method counts vowels.
*/
int countSyllables(string str){
	str = toLowerCase(str);
	int count =0;
	for(int i =0; i<str.length()-1; i++){
		if(isVowel(str[i]) && !isVowel(str[i+1])){
			count++;	
		}
	}
	//If statements given below check and count special cases of this problem.
	if(str[str.length()-1]!='e' &&  isVowel(str[str.length()-1])){
		count ++;
	}
	if(str.length()>2 && str[str.length()-1]=='e'  && isVowel(str[str.length()-2])){
		count++;
	}
	if(count == 0){
		return 1;
	} else {
		return count;
	}
}