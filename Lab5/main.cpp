//============================================================================
// Name        : lab5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class studentRecord {
public:
	studentRecord();
	int getQuiz1() {
		return quiz1;
	}
	int getQuiz2() {
		return quiz2;
	}
	int getMidterm() {
		return midterm;
	}
	int getFinal() {
		return final;
	}
	double getAvg() {
		return avg;
	}
	void setQuiz1(int quiz) {
		quiz1 = quiz;
	}
	void setQuiz2(int quiz) {
		quiz2 = quiz;
	}
	void setMidterm(int mid) {
		midterm = mid;
	}
	void setFinal(int fin) {
		final = fin;
	}
	void calcAvg();

private:
	int quiz1, quiz2, midterm, final;
	double avg;
};

class CounterType {
public:
	CounterType();
	CounterType(int specifier);
	void incrementCount() {
		count++;
	}
	void decrementCount() {
		if (count > 0)
			count--;
		else
			cout << "Count would be below zero; cannot decrement" << endl;
	}
	int getCount() {
		return count;
	}
	void streamOut(ostream &stream) {
		stream << count;
	}
private:
	int count;
};

void testEx1() {
	studentRecord student;
	int a, b, c, d;
	cout << "Test for: Exercise 1" << endl;
	cout << "Enter quiz1 : ";
	cin >> a;
	cout << "\nEnter quiz2 : ";
	cin >> b;
	cout << "\nEnter midterm : ";
	cin >> c;
	cout << "\nEnter final : ";
	cin >> d;
	student.setQuiz1(a);
	student.setQuiz2(b);
	student.setMidterm(c);
	student.setFinal(d);
	student.calcAvg();
	cout << "Your quiz scores were " << student.getQuiz1() << " and "
			<< student.getQuiz2() << ", your midterm score was "
			<< student.getMidterm() << ", your final score was "
			<< student.getFinal() << ", and your average was "
			<< student.getAvg() << "." << endl;

}

void testEx2() {
	int temp = 0;
	cout << "Test for: Exercise 2" << endl;
	cout << "Enter a value for count: ";
	cin >> temp;
	CounterType count(temp);
	cout << "The current value is " << count.getCount() << endl;
	count.incrementCount();
	cout << "Count + 1 equals " << count.getCount() << endl;
	count.decrementCount();
	count.decrementCount();
	cout << "Count - 1 equals " << count.getCount() << endl;
	count.incrementCount();
	cout <<"Passing the osstream object cout to the count class prints: ";
	count.streamOut(cout);
	cout << ", which is the value of count.";
}

int main() {
//	testEx1();
	testEx2();
	return 0;
}


studentRecord::studentRecord() {
	quiz1 = 0;
	quiz2 = 0;
	midterm = 0;
	final = 0;
	avg = 0;
}
void studentRecord::calcAvg() {
	avg = (((quiz1 + quiz2) / 20.0) * (0.25) + ((midterm / 100.0) * (0.25))
			+ ((final / 100.0) * (0.50))) * 100.0;
}

CounterType::CounterType() {
	count = 0;
}

CounterType::CounterType(int input) {
	if (input >= 0)
		count = input;
	else {
		cout << "Input was negative, count was initialized to zero" << endl;
		count = 0;
	}
}

/*OUTPUT
 *
 *Test for: Exercise 1
Enter quiz1 : 10

Enter quiz2 : 10

Enter midterm : 80

Enter final : 82
Your quiz scores were 10 and 10, your midterm score was 80, your final score was 82, and your average was 86.
Test for: Exercise 2
Enter a value for count: 5
The current value is 5
Count + 1 equals 6
Count - 1 equals 4
Passing the osstream object cout to the count class prints: 5, which is the value of count.
 *
 *TESTING EX2 BOUNDARIES
 *
 *Test for: Exercise 2
Enter a value for count: -1
Input was negative, count was initialized to zero
The current value is 0
Count + 1 equals 1
Count would be below zero; cannot decrement
Count - 1 equals 0
Passing the osstream object cout to the count class prints: 1, which is the value of count.
 *
 */

