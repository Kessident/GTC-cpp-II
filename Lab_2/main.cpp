//Charles Dodge
//CIST 2361 CRN 63228

/*
//Lab 2 Sum of Digits

#include <iostream>
#include <cstring>

using namespace std;

int doContinue = 0;

int main() {
    do {
        const int LEN = 30;
        char longNumber[LEN];

        cout << "This program will sum all the digits in a number" << endl;
        cout << "Please enter a number no more than 30 digits: ";

        cin.getline(longNumber, LEN);

        int sum = 0, high = 0, low = 9;
        for (char c : longNumber) {
            if (isdigit(c)) {
                c -= '0';
                sum += c;
                if (c > high) {
                    high = c;
                } else if (c < low) {
                    low = c;
                }
            }
        }

        cout << "Sum: " << sum << endl;
        cout << "Largest digit was: " << high << endl;


        cout << endl << "enter 1 to go again, anything else to exit ";
        cin >> doContinue;
    } while (doContinue == 1);

    return 0;
}*/

/*
//Lab 2 Name Arranger

#include <iostream>
#include <cstring>

using namespace std;

int doContinue = 0;

int main() {
    do {
        const int LEN = 31;
        char first[LEN], middle[LEN], last[LEN];
        cout << "Please enter your first name: ";
        cin.getline(first, LEN);

        cout << "Please enter your middle name: ";
        cin.getline(middle, LEN);

        cout << "Please enter your last name: ";
        cin.getline(last, LEN);

        char fullName[91];

        strcat(fullName, last);
        strcat(fullName, ", ");
        strcat(fullName, first);
        strcat(fullName, " ");
        strcat(fullName, middle);

        cout << "Full name: " << fullName;

        cout << endl << "enter 1 to go again, anything else to exit ";
        cin >> doContinue;
    } while (doContinue == 1);

    return 0;
}*/


//Lab 2 Word Counter
#include <iostream>
#include <cstring>

using namespace std;

int getNumWords(char[]);

int doContinue = 0;

int main() {
    do {
        const int LEN = 51;
        char someString[LEN];
        cout << "This program will tell you how many words are in an entered string"
             << "(A word is some characters, separated by a space)" << endl;
        cout << "Up to 50 characters will be handled at once: ";
        cin.getline(someString, LEN);

        cout << getNumWords(someString) << " words in \"" << someString << "\"" << endl;

        cout << endl << "enter 1 to go again, anything else to exit ";
        cin >> doContinue;
    } while (doContinue == 1);

    return 0;
}

int getNumWords(char string[]) {
    //All strings will be at least one 'word'
    int numWords = 1;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == ' ') {
            numWords += 1;
        }
    }
    return numWords;
}