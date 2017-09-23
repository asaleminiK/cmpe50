//============================================================================
// Name        : helloworld.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	//Part 1
	cout << "A fool thinks himself to be wise, but a wise man knows himself to be a fool" << endl;

	//Part 2
	int value;
	cout << "Enter value:";
	cin >> value;
	value = value*value;
	cout << "\nThe square is " << value << endl;

	//Part 3
	int k;
	bool isprime;
	cout << "Enter value:";
	cin >> k;
	for(int i = 3; i < k; i++){
		isprime = true;
		//Check if current variable is prime
		for(int check = i-1; check > 1;  check--){
			if ((i%check) == 0) isprime = false;
		}
		if (isprime) cout << i << " is a prime" << endl;
	}

	return 0;
}

/* Output of program
 * Part 1
 * A fool thinks himself to be wise, but a wise man knows himself to be a fool
 *
 * Part 2
 * Enter value:3
 * The square is 9
 *
 * Part 3
 * Enter value:21
 * 3 is a prime
 * 5 is a prime
 * 7 is a prime
 * 11 is a prime
 * 13 is a prime
 * 17 is a prime
 * 19 is a prime
 */
