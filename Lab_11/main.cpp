//Charles Dodge
//CIST 2362 CRN 63228


/*
//Lab 11 isMember

#include <iostream>
#include <array>

using namespace std;

template<class T>
bool isMember(T[], int, T);

const int SIZE = 10;


int main() {
    int array[SIZE] = {77, 2, 61, 88, 84, 45, 22, 24, 3, 67};

    int num;
    while (true) {
        cout << "Enter a number to search for (-1 to exit): ";
        cin >> num;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a number to search for: ";
            cin >> num;
        }

        if (num == -1)
            return 0;

        if (isMember(array, SIZE, num)) {
            cout << num << " is part of the array" << endl;
        } else {
            cout << num << " is not part of the array" << endl;
        }
    }
}

template<class T>
bool isMember(T array[], int size, T obj) {
    //If at end, false
    if (*array == array[size]) {
        return false;
    }

    //If found, true
    if (*array == obj) {
        return true;
        //else increment, try again
    } else {
        return isMember(array + 1, size, obj);
    }
}*/


/*
//Lab 11 Sum of Numbers
#include <iostream>

using namespace std;

double sumOf(int);

int main(){
    while (true) {
        int num;
        cout << "Enter a positive number or 0 to exit: ";
        cin >> num;

        while (cin.fail() || num < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a positive number: ";
            cin >> num;
        }

        if (num == 0)
            return 0;

        cout << "Σn from 1 to " << num << " = " << sumOf(num) << endl;
    }
}

//Return sum of numbers from 1 -> num
double sumOf(int num) {
    if (num <= 0)
        return 0;
    return num + sumOf(num - 1);
}*/


/*
//Lab 11 Recursion Power Function
#include <iostream>

using namespace std;

double pow(int, int);

int main() {
    //2^2
    cout << "2^2: " << pow(2, 2) << endl;
    //4^9
    cout << "4^9: " << pow(4, 9) << endl;
    //3^100
    cout << "3^100: " << pow(3, 100) << endl;

    while (true) {
        int base, exponent;
        cout << "Enter a number (0 to exit): ";
        cin >> base;

        while(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number: ";
            cin >> base;
        }

        if (base == 0)
            return 0;

        cout << "Enter another number: ";
        cin >> exponent;
        while(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number: ";
            cin >> exponent;
        }

        cout << base << "^" << exponent << " = " << pow(base, exponent) << endl;
    }
}

double pow(int base, int exp) {

    if (exp == 0) {
        return 1;
    } else if (exp == 1) {
        return base;
    } else {
        return base * pow(base, exp - 1);
    }
}*/


/*
#include <iostream>
#include <vector>

double factorial(int);

double factorialDynamic(int);

double addUp(int);

double addUpForm(int);


void addUpExample(int);

using namespace std;
const int MAX_SIZE = 1000000000;
//vector<double> result(100000000,0);
double result[MAX_SIZE] = {0};

int main() {
    auto start = chrono::high_resolution_clock::now();

    for (int i = 1; i < 100000; i++) {
        addUpForm(i);
    }


    auto end = chrono::high_resolution_clock::now();
    auto durationMicro = chrono::duration_cast<chrono::microseconds>(end - start).count();
    auto durationSeconds = chrono::duration_cast<chrono::seconds>(end - start).count();

    cout << "Execution time (microseconds): " << durationMicro << endl;

    return 0;
}

double factorialDynamic(int num) {
    if (num >= 0) {
        result[0] = 1;
        for (int i = 1; i <= num; ++i) {
            result[i] = i * result[i - 1];
        }
        return result[num];
    }

    return -1;
}

double factorial(int num) {
    if (num == 0) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}


double addUp(int num) {
    if (num > 0) {
        return num + addUp(num - 1);
    } else {
        return 0;
    }
}

double addUpForm(int n) {
    return (n * (n + 1)) / 2.0;
} */