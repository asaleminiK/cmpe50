//============================================================================
// Name        : lab2.cpp
// Author      : Ameen Saleminik
// Version     :
// Copyright   :
//============================================================================

#include <iostream>
using namespace std;

//Declaring functions for Part 1
void add(int a, int b);
void add(double a, double b);
void add(char a[], char b[]);

//Declaring function for Part 2
void reverse(string regular, int loc);

//Declaring functions for Part 3
void gradeCheck();

int main() {
	char input;
	//
	//Exercise 1 – Function Overloading
	//

	//Ask what the user would like
	cout
			<< "Would you like to add 2 integers(i), doubles(d), or char arrays(a)?"
			<< endl;
	cin >> input;
	//Depending on the input, call the correct function
	if (input == 'a') {
		char a[10], b[10];
		cout << "Enter your two strings(10 char max)" << endl;
		cin >> a;
		cin >> b;
		add(a, b);
	}
	if (input == 'd') {
		double a, b;
		cout << "Enter your two numbers" << endl;
		cin >> a;
		cin >> b;
		add(a, b);
	}
	if (input == 'i') {
		int a, b;
		cout << "Enter your two numbers" << endl;
		cin >> a;
		cin >> b;
		add(a, b);
	}

	//
	//Part 2
	//
	char regular[11];
	int loc = 0;
	//We save the location
	for (; loc < 10; loc++) {
		cout << "Enter letter #" << loc + 1 << endl;
		cin >> regular[loc];
		//Check if the string has ended, then break. Otherwise, keep going until 10
		if (regular[loc] == '.') {
			break;
		}
	}
	//Insert the null character after the period b/c cout requires it to read the string properly
	regular[loc + 1] = '\0';
	reverse(regular, loc);

	//
	//Part 3
	//
	//We move the grade calculator to another function to be clean
	gradeCheck();

	return 0;
}
//Definitions for part 2
void add(int a, int b) {
	cout << a + b << endl;
}

void add(double a, double b) {
	cout << a + b << endl;
}

void add(char a[], char b[]) {
	cout << a << b << endl;
}

//Definitions for Part 2
void reverse(string regular, int loc) {
	cout << regular << " reversed is ";
	//Traverse the array backwards
	for (; loc >= 0; --loc)
		cout << regular[loc];
	cout << endl;
}

//Definitions for Part 3
void gradeCheck() {
	double entries[2][8];
	double averages[5];
	double overall;
	cout << "Please enter five HW scores [0 – 100]:" << endl;
	entries[0][6] = 0;
	entries[0][7] = 100;
	for (int i = 0; i < 5; i++) {
		cin >> entries[0][i];
		//Calculate the highest score
		if (entries[0][i] > entries[0][6])
			entries[0][6] = entries[0][i];
		//Calculate the lowest score
		if (entries[0][i] < entries[0][7])
			entries[0][7] = entries[0][i];
	}
	//Calculate the average best and worst
	entries[0][8] = (entries[0][6] + entries[0][7]) / 2;

	cout << "Please enter five Lab scores [0 – 100]:" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> entries[1][i];
		//Calculate the highest score
		if (entries[1][i] > entries[1][6])
			entries[1][6] = entries[1][i];
		//Calculate the lowest score score
		if (entries[1][i] < entries[1][7])
			entries[1][7] = entries[1][i];
		//Calculate the Lab and Homework Avg
		averages[i] = (entries[1][i] + entries[0][i]) / 2;
		//Calculate the Overall score
		overall += averages[i];
	}
	overall = overall / 5;
	//Calculate the average best and worst
	entries[1][8] = (entries[1][6] + entries[1][7]) / 2;

	//Output the final result
	//Format correctly

	cout.width(5);
	cout << 1;
	cout.width(5);
	cout << 2;
	cout.width(5);
	cout << 3;
	cout.width(5);
	cout << 4;
	cout.width(5);
	cout << 5 << endl << "    *********************" << endl;
	cout << "HW";

	for (int i = 0; i < 5; i++) {
		cout.width(5);
		cout << entries[0][i];
	}
	cout << "    BEST HW: " << entries[0][6] << "  WORST HW: " << entries[0][7]
			<< "  AVG HW: " << entries[0][8] << endl;

	cout << "LAB";
	for (int i = 0; i < 5; i++) {
		cout.width(5);
		cout << entries[1][i];
	}
	cout << "    BEST LAB: " << entries[1][6] << "  WORST LAB: "
			<< entries[1][7] << "  AVG LAB: " << entries[1][8] << endl;

	cout << "/nAVG";
	for (int i = 0; i < 5; i++) {
		cout.width(5);
		cout << averages[i];
	}
	//Calculate if the person passed the class
	cout << "   OVERALL: " << overall << endl;
	if (entries[0][8] >= 50) {
		if (entries[1][8] >= 50)
			cout << "Congratulations! You passed the class!";
		else
			cout
					<< "I’m sorry to inform you that you failed the class, because your performance in LABS was <50%. Try again next semester.";
	} else
		cout
				<< "I’m sorry to inform you that you failed the class, because your performance in HW was <50%. Try again next semester.";

}

/*OUTPUT
 *
 *
 *
 *
 *
 *
 *Would you like to add 2 integers(i), doubles(d), or char arrays(a)?
 d
 Enter your two numbers
 4.0
 2.6
 6.6
 Enter letter #1
 A
 Enter letter #2
 B
 Enter letter #3
 C
 Enter letter #4
 D
 Enter letter #5
 .
 ABCD. reversed is .DCBA
 Please enter five HW scores [0 – 100]:
 100
 70
 1
 40
 50
 Please enter five Lab scores [0 – 100]:
 60
 99
 10
 100
 100
 1    2    3    4    5
 *********************
HW  100    1   50   60   20    BEST HW: 100  WORST HW: 1  AVG HW: 30
LAB   30   30   30   30   30    BEST LAB: 30  WORST LAB: 30  AVG LAB: 30

AVG   65 15.5   40   45   25   OVERALL: 38.1
I’m sorry to inform you that you failed the class, because your performance in HW was <50%. Try again next semester.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
