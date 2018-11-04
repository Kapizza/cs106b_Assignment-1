/*
* File: Combinations.cpp
* ----------------------
* Name: Daviti Gochitashvili
* Section: 9
* This file is the starter project for the Combinations problem.
* [TODO: rewrite the documentation]
*/

#include <iostream>
#include "console.h"
#include "simpio.h"
using namespace std;

/* Function prototype */
int findCombination(int n, int k);


/* Main program */
int main() {
	//read numbers from user;
	int n = getInteger("Enter n: ");
	int k = getInteger("Enter k: ");
	//check validation;
	while(k>n){
		cout << "error!" ;
		k = getInteger("Enter k: ");
	}
	//print results;
	cout << findCombination(n,k) << endl;
	return 0;
}
/* This method finds C(n,k) combinations*/
int findCombination(int n, int k){
	if(k == n || k == 0){
		return 1;
	} else {
		return findCombination(n-1,k-1)+findCombination(n-1, k);
	}
}