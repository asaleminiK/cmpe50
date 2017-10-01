//============================================================================
// Name        : lab4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <string.h>
#include <limits>

using namespace std;

string sexistCheck(string c);

int main() {
    //
    cout << "Exercise 1" << endl;
    //
    char sentence[101];
    cout << "Enter input:\n";
    //Input up to 100 chars or a period
    cin.getline(sentence, 100, '.');
    //Get the length
    int length = strlen(sentence) + 1;

    //Replace the whitespace with spaces
    for (int i = 0; i < length; i++) {
        if (sentence[i] == '\n' || sentence[i] == '\t')
            sentence[i] = ' ';
    }
    //Check if the next index is a space, a period(end of sentence), or if the first index has a space, then shift the array to remove it.
    for (int index1 = 0; index1 < length;) {
        if ((sentence[index1] == ' ' && sentence[index1 + 1] == ' ')
            || (sentence[index1] == ' ' && sentence[index1 + 1] == '.')
            || (sentence[0] == ' '))
            for (int i = index1; i < length - 1; i++)
                sentence[i] = sentence[i + 1];
        else
            index1++;
    }
    //Set everything but the first to lowercase
    for (int i = 1; i < length; ++i)
        sentence[i] = tolower(sentence[i]);
    sentence[0] = toupper(sentence[0]);
    cout << sentence << '.' << endl;
    //Clear the hanging charecters, if any

    cin.clear();
    string throwaway;
    getline(cin, throwaway);
    //
    cout << endl <<"Exercise 2" << endl;
    //
    string s = "", word = "";
    int count = 0;
    char check;
    do {
        //fix the hanging /n issue with getline
        cout << "Enter sentence to check. Press the enter key to cut off the sentence" << endl;
        getline(cin, s);
        //Check if the current index is a letter. If it is, add it to word, and check if it is sexist. If it is, replace it.
        for (int i = 0; i < s.size() + 1; i++) {
            if (isalpha(s[i])) {
                word += s[i];
                count++;
            } else {
                word = sexistCheck(word);
                s.replace(i - count, count, word);
                //We need to push i forward by the size of the replaced word. If it isn't, it will keep re-checking and replacing.
                i = i - count + word.size();
                //reset the cars
                word = "";
                count = 0;
            }
        }
        s[0] = toupper(s[0]);
        cout << s << endl;
        cout << "Would you like to try again?(y/n)" << endl;
        cin >> check;
        cin.ignore();
    } while (check == 'y');

}

string sexistCheck(string c) {
    c[0] = tolower(c[0]);
    if (c == "he" || c == "she") c = "she or he";
    if (c == "him" || c == "her") c = "her or him";
    if (c == "his" || c == "hers") c = "hers or his";
    return c;

}


/*
 *
 *
 *
 * OUTPUT
 *
 *
 *
 * Exercise 1
Enter input:
   noW  iS   thE    TiMe  fOr  aLl
         gOOD MEN TO  ComE TO   tHe
  		aId
oF


   ThE  CounTRY.
Now is the time for all good men to come to the aid of the country.

Exercise 2
Enter sentence to check. Press the enter key to cut off the sentence
See an adviser, talk to him, and listen to him.
See an adviser, talk to her or him, and listen to her or him.
Would you like to try again?(y/n)
y
Enter sentence to check. Press the enter key to cut off the sentence
Everyone loves his rice.
Everyone loves hers or his rice.
Would you like to try again?(y/n)
n

Process finished with exit code 0
 */
