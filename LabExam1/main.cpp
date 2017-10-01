
//============================================================================
// Name        : LabExam1a.cpp
// Author      : 
// Version     :
// Copyright   : Ameen Saleminik
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void groceryPurchase();

void upSort(int* start, int* end);

void readIn();

void mergeSorter(int lenA, int lenB, int a[MAX_ARRAY_SIZE],
		int b[MAX_ARRAY_SIZE]);

int const MAX_ARRAY_SIZE = 10;

int main() {
	char choice = ' ';
	do {
		cout << "Type 2 to enter Exercise 2" << endl;
		cout << "Type 3 to enter Exercise 3" << endl;
		cout << "Type q/Q to quit" << endl;
		cin >> choice;
		if (choice == '2') {
			cout << "You chose to enter Exercise 2" << endl << endl;
			groceryPurchase();
			;
			break;
		} else if (choice == '3') {
			cout << "You chose to enter Exercise 3" << endl << endl;
			readIn();
			break;
		}
	} while (!(choice == 'q' || choice == 'Q'));

}

void groceryPurchase() {
	double high[2], low[2];
	double avg = 0;
	char choice = ' ';
	ifstream infile;
	char fileName[100];
	string months[12] = { "January", "February", "March", "April", "May",
			"June", "July", "August", "September", "October", "November",
			"December" };
	double purchases[12] = { 0 };
	cout
			<< "Would you like to input monthly purchases from a file(f) or enter them manually(m)?"
			<< endl;
	cin >> choice;
	if (choice == 'm') {
		for (int i = 0; i < 12; i++) {
			cout << "Enter grocery purchases for " << months[i] << ":" << endl;
			cin >> purchases[i];
		}
	}
	if (choice == 'f') {
		cout << "Enter the file name:" << endl;
		cin >> fileName;
		cout << fileName;
		infile.open(fileName);
		if (infile.fail()) {
			cout << "File not found.";
			ofstream test;
			test.open("Test.txt");
			exit(1);
		}
		int i = 0;
		while (infile >> purchases[i++])
			;
	}
	//Calculation Section
	low[0] = purchases[0];
	high[0] = 0;
	for (int c = 0; c < 12; c++) {
		if (purchases[c] > high[0]) {
			high[0] = purchases[c];
			high[1] = (double) c;
		}
		if (purchases[c] < low[0]) {
			low[0] = purchases[c];
			low[1] = (double) c;
		}
		avg += purchases[c];
	}
	avg = avg / 12.0;
	cout << "The highest grocery cost was " << high[0] << " in "
			<< months[(int) high[1]] << endl;
	cout << "The lowest grocery cost was " << low[0] << " in "
			<< months[(int) low[1]] << endl;
	cout << "The average monthly expense was " << avg << endl;

}

void upSort(int* start, int* end) {
	int len = *end - *start;
	int *i, *f, *high;
	high = start;
	for (i = start; i <= end; i++) {
		int temp = 0;
		high = &temp;
		for (f = i; f <= end; f++) {
			if (*f > *high) {
				high = f;
			}
		}
		temp = *i;
		*i = *high;
		*high = temp;
	}
}

void mergeSorter(int lenA, int lenB, int a[MAX_ARRAY_SIZE],
		int b[MAX_ARRAY_SIZE]) {
	int mergedArray[MAX_ARRAY_SIZE * 2];
	for (int i = 0; i < lenA; i++) {
		mergedArray[i] = a[i];
	}
	for (int i = 0; i < lenB; i++) {
		mergedArray[i + lenA] = b[i];
	}
	upSort(&mergedArray[0], &mergedArray[lenA + lenB - 2]);
	for(int i = 0; i < lenA+lenB - 1; i++){
		cout << mergedArray[i] << ", ";
	}
}

void readIn() {

	int a[MAX_ARRAY_SIZE], b[MAX_ARRAY_SIZE] = {0};
	int count1, count2 = 0;
	cout << "Enter first set of numbers , max is ten."
			<< endl;
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
		count1++;
	}
	cout << "Enter second set of numbers , max is ten.";
	for (int i = 0; i < 10; i++) {
		cin >> b[i];
		count2++;
	}
	cout << "The sorted array is: ";
	mergeSorter(count1, count2, a, b);
}

/*
 *
 *
 *
 * OUTPUT: OPTION 2
 *
 * Type 2 to enter Exercise 2
Type 3 to enter Exercise 3
Type q/Q to quit
2
You chose to enter Exercise 2

Would you like to input monthly purchases from a file(f) or enter them manually(m)?
m
Enter grocery purchases for January:
60
Enter grocery purchases for February:
70
Enter grocery purchases for March:
50
Enter grocery purchases for April:
30
Enter grocery purchases for May:
60
Enter grocery purchases for June:
70.2
Enter grocery purchases for July:
50
Enter grocery purchases for August:
50
Enter grocery purchases for September:
43
Enter grocery purchases for October:
30
Enter grocery purchases for November:
22
Enter grocery purchases for December:
40
The highest grocery cost was 70.2 in June
The lowest grocery cost was 22 in November
The average monthly expense was 47.9333

OUTPUT: OPTION 3
The following code will hangup. I am unsure of the reason. The sorting function, along with the merging function works as intended.


 */
