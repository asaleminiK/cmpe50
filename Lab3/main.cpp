//============================================================================
// Name        : lab2.cpp
// Author      : Ameen Saleminik
// Version     :
// Copyright   :
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

//Exercise 1 Declarations
void fileUpperCase();

void fileFail();

//Exercise 2 Declarations
void intSort();

void simpleSort(int input[], int length);

//Exercise 2 Declarations
void mergeSorter(string input1, string input2, string output);

int main() {
    fileUpperCase();
    intSort();
    mergeSorter("LabInput3-3.txt", "LabInput3-4.txt", "LabOutput34.txt");
}

void fileUpperCase() {
    ifstream infile;
    char inarray[1000];
    infile.open("LabInput3-1.txt");
    if (infile.fail()) {
        fileFail();
    }
    int count = 0;
    while (infile >> inarray[count++]) {
        if (iswspace(inarray[count])) {
            for (int j = count; j < 999; j++) {
                inarray[j] = inarray[j + 1];
            }
        }
        inarray[count] = toupper(inarray[count]);
    }
    inarray[count + 1] = '\0';
    ofstream outfile("LabOutput3-1.txt");
    if (outfile.is_open()) {
        outfile << inarray;
    } else
        cout << "Unable to open file";
}

//This function takes numbers from the user or from a file and
void intSort() {
    char choice = ' ';
    char fileName[50];
    int entries[50];
    int occurrences[50][2];
    int count = 0;
    ifstream infile;
    cout << "Would you like to input values(i) or read them from a file?(f)"
         << endl;
    cin >> choice;

    if (choice == 'i') {
        int max = 0;
        cout
                << "How many values would you like to enter? (must be smaller than or equal to 50)"
                << endl;
        cin >> max;
        for (; count < max; ++count) {
            cin >> entries[count];
        }
    }

    if (choice == 'f') {

        cout << "Enter the file name" << endl;
        cin >> fileName;
        infile.open(fileName);
        if (infile.fail()) {
            fileFail();
        }
        while (infile >> entries[count++]) {};
        count--;
    }
    //Sort the Array
    simpleSort(entries, count);

    //Algorithm for removing duplicates. It starts at the first index, checks if there are similar entries,
    //then shifts the array over and decrements the length. It also counts the number of times a variable
    //appears.
    int i, j, k, occurations;
    for (i = 0; i < count; i++) {
        occurations = 1;
        occurrences[i][0] = entries[i];
        for (j = i + 1; j < count;) {
            if (entries[i] == entries[j]) {
                for (k = j; k < count - 1; ++k)
                    entries[k] = entries[k + 1];
                --count;
                occurations++;
            } else j++;
        }
        occurrences[i][1] = occurations;
    }
    //Format the cout, and print out the array backwards because it was sorted decreasing to increasing.
    cout << "N    " << "Count" << endl;
    ofstream outfile("LabOutput3-2.txt");
    for (int i = count - 1; i >= 0; i--) {
        cout << occurrences[i][0] << "     " << occurrences[i][1] << endl;
        outfile << occurrences[i][0] << "     " << occurrences[i][1] << endl;
    }
}

void mergeSorter(string input1, string input2, string output) {
    int entries[100];
    ifstream infile1, infile2;
    infile1.open(input1);
    infile2.open(input2);
    if (infile1.fail() || infile2.fail())
        fileFail;
    int count = 0;
    //We will place both inputs into a common array
    while (infile1 >> entries[count++]);
    while (infile2 >> entries[count++]);
    count -= 2;
    //We will sort this array
    simpleSort(entries, count);
    //Output the sorted array into a file that was specified when the function was called.
    ofstream outfile(output);
    if (outfile.is_open()) {
        for (int i = 0; i < count; i++) {
            outfile << entries[i] << endl;
        }
    } else
        cout << "Unable to open file";
}

//An adaptation of bubblesort
void simpleSort(int input[], int length) {
    int i, j;
    for (i = 0; i <= length - 1; i++)
        for (j = 0; j < length - i - 1; j++)
            if (input[j] > input[j + 1]) {
                int temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
}


void fileFail() {
    cout
            << "File opening failed. The file is probably not in the correct location"
            << endl;
    cout
            << "A file called 'Testpath.txt' has been created to show where the program expects where the input file should be"
            << endl;
    ofstream testfile("Testpath.txt");
    testfile << "This is the test file";
    exit(1);
}


/* OUTPUT
 *
 *
 * This is Exercise Two's output. It is also it its respective file.
 *
 *   Would you like to input values(i) or read them from a file?(f)
 *   i
 *   How many values would you like to enter? (must be smaller than or equal to 50)
 *   10
 *
 *   60
 *   70
 *   60
 *   50
 *   4
 *   4
 *   2
 *   3
 *   3
 *   3
 *
 *   N    Count
 *   70     1
 *   60     2
 *   50     1
 *   4     2
 *   3     3
 *   2     1
 *
 *   PT-2
 *  Would you like to input values(i) or read them from a file?(f)
    f
    Enter the file name
    LabInput3-2.txt
    N    Count
    4     2
    3     1
    1     2
    -3     1
 *
 * */
