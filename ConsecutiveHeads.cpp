/*
* File: ConsecutiveHeads.cpp
* --------------------------
* Name: Daviti Gochitashvili
* Section: 9
* This file is the starter project for the Consecutive Heads problem.
* [TODO: rewrite the documentation]
*/

#include <iostream>
#include "console.h"
#include "random.h"
using namespace std;

/* Function prototypes */
void simulate();
void printResult(int tries);

/* Main program */
int main() {
	simulate();
	return 0;
}

/*
This method simulates coin tossing process. Counts how many tunrs to reach 3 consecutive heads.
*/
void simulate(){
	int headsInRow = 0;
	int tries = 0;
	while(true){
		tries++;
		if(randomChance(0.5)){
			cout << "heads" << endl;
			headsInRow++;
		} else {
			headsInRow=0;
			cout << "tails" << endl;
		}
		if(headsInRow==3) break;
	}
	printResult(tries);
}
/* This method just prints result to user. */
void printResult(int tries){
	cout << "It took " <<tries << " flips to get 3 consecutive heads." << endl;
}