//============================================================================
// Name        : LabExam2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <stdlib.h>

using namespace std;

void exercise1();
void exercise2();
void exercise3();
string num[10] = { "zero", "one", "two", "three", "four", "five", "six",
			"seven", "eight", "nine" };

class Diner {
public:
	Diner(string n, string c) {
		name = n;
		category = c;
		for(int i = 0; i < 5; i++)
			ratings[i] = 0;
		average = 0;
	}
	string getName() {
		return name;
	}
	void setName(string s) {
		name = s;
	}
	string getCategory() {
		return category;
	}
	void setCategory(string s) {
		category = s;
	}
	int getRating(int loc) {
		if (loc < 5 || loc >= 0)
			return ratings[loc];
		else
			return -1;
	}
	bool setRating(int loc) {
		//Setrating increments one rating at Rating-1 position. If you call the function with a rating 1,
		//It will increment the value at rating[0] by one. The final calculation takes this into account.
		if (loc <= 5 && loc > 0) {
			ratings[loc-1] = ratings[loc-1]+1;
			return true;
		} else {
			cout << "Not a valid rating." << endl;
			return false;
		}

	}

	double getAverage();
	bool operator==(Diner& obj1);
private:
	string name, category;
	int ratings[5];
	double average;
};

int main() {
	exercise1();
	return 0;
}

void exercise1() {
	int selection = 0;
	while (!(selection == 3)) {
		cout
				<< "Welcome to the main menu. Type (1) to enter exercise2, (2) to enter exercise 3, or (3) to end the program."
				<< endl;
		cin >> selection;
		if (selection == 1) {
			cout << "You have decided to execute exercise 2: " << endl;
			exercise2();
		}
		if (selection == 2){
			cout << "You have decided to execute exercise 3: " << endl;
		exercise3();
		}
	}
}

void exercise2() {
	ifstream infile;
	ofstream outfile;
	infile.open("input.txt");
	if (infile.fail()) {
		cout << "Could not find file. Exiting...";
		exit(1);
	}
	outfile.open("output.txt");
	if (outfile.fail()) {
		cout << "Could not open output file. Exiting...";
		exit(2);
	}
	string line;
	while (!(infile.eof())) {
		getline(infile, line);
		int g;
		//Sorry about this, line[i] was not behaving as I expected.
		for (int i = 0; i < line.size(); i++) {
			if (isdigit(line[i])) {
				if(line[i] == '1') g = 1;
				if(line[i] == '2') g = 2;
				if(line[i] == '3') g = 3;
				if(line[i] == '4') g = 4;
				if(line[i] == '5') g = 5;
				if(line[i] == '6') g = 6;
				if(line[i] == '7') g = 7;
				if(line[i] == '8') g = 8;
				if(line[i] == '9') g = 9;
				if(line[i] == '0') g = 0;
				line.replace(i, 1, num[g]);
			}
		}
		cout << line << endl;
		outfile << line << endl;
	}
	infile.close();
	outfile.close();
}

void exercise3() {
	string name1, name2, category1, category2;
	cout << "Name of diner 1: ";
	cin >> name1;
	cout << "Name of diner 2: ";
	cin >> name2;
	cout << "Category of diner 1: ";
	cin >> category1;
	cout << "Category of diner 2: ";
	cin >> category2;
	Diner diner1(name1, category1), diner2(name2, category2);
	int rating;
	for (int i = 0; i < 5; i++) {
		cout << "Enter rating #" << i + 1 << " for " << diner1.getName() << ": ";
		cin >> rating;
		if (!(diner1.setRating(rating)))
			i--;
	}
	for (int i = 0; i < 5; i++) {
		cout << "Enter rating #" << i + 1 << " for " << diner2.getName() << ": ";;
		cin >> rating;
		if (!(diner2.setRating(rating)))
			i--;
	}
	cout << "The two diner names are " << diner1.getName() << " and " << diner2.getName() << endl;
	cout << "Diner 1's category is " << diner1.getCategory() << " and Diner 2's category is " << diner2.getCategory() << " ." << endl;
	cout << "The average rating for Diner 1 was " << diner1.getAverage() << " and Diner 2's was " << diner2.getAverage() << endl;
	if(diner1 == diner2) cout << "The two have the same average." << endl;
	else cout << "The two do not have the same average." << endl;
}

double Diner::getAverage() {
	//Multiply the amount of ratings by their respective values
	int total = 1 * ratings[0] + 2 * ratings[1] + 3 * ratings[2]
			+ 4 * ratings[3] + 5 * ratings[4];
	//total amt of ratings equals people(although it's always 5 in this program)
	double people = ratings[0] + ratings[1] + ratings[2] + ratings[3]
			+ ratings[4];
	//divide them
	average = total / people;
	return average;
}

bool Diner::operator==(Diner& obj1) {
	if (this->getAverage() == obj1.getAverage())
		return true;
	else
		return false;
}

/*OUTPUT
 * Welcome to the main menu. Type (1) to enter exercise2, (2) to enter exercise 3, or (3) to end the program.
1
You have decided to execute exercise 2:
The price of the cup is four dollars. But it's on sale today at two for six dollars.
If you buy more, you can get three for eight dollars.
Welcome to the main menu. Type (1) to enter exercise2, (2) to enter exercise 3, or (3) to end the program.
2
You have decided to execute exercise 3:
Name of diner 1: Denny's
Name of diner 2: PizzaPlace
Category of diner 1: American
Category of diner 2: Italian
Enter rating #1 for Denny's: 5
Enter rating #2 for Denny's: 5
Enter rating #3 for Denny's: 4
Enter rating #4 for Denny's: 4
Enter rating #5 for Denny's: 5
Enter rating #1 for PizzaPlace: 2
Enter rating #2 for PizzaPlace: 4
Enter rating #3 for PizzaPlace: 4
Enter rating #4 for PizzaPlace: 3
Enter rating #5 for PizzaPlace: 3
The two diner names are Denny's and PizzaPlace
Diner 1's category is American and Diner 2's category is Italian .
The average rating for Diner 1 was 4.6 and Diner 2's was 3.2
The two do not have the same average.
Welcome to the main menu. Type (1) to enter exercise2, (2) to enter exercise 3, or (3) to end the program.
3
 *
 *
 *
 */
