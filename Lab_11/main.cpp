//Charles Dodge
//CIST 2362 CRN 63228
//Lab 11 Recursion Power Function
#include <iostream>

double pow(int, int);

int main() {
    //2^2
    std::cout << "2^2: " << pow(2, 2) << std::endl;
    //4^9
    std::cout << "4^9: " << pow(4, 9) << std::endl;
    //3^100
    std::cout << "3^100: " << pow(3, 100) << std::endl;
    while (true) {
        
    }
    return 0;
}

double pow(int base, int exp) {

    if (exp == 0) {
        return 1;
    } else if (exp == 1) {
        return base;
    } else {
        return base * pow(base, exp - 1);
    }
}/*

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
    auto overallStart = chrono::high_resolution_clock::now();

    for (int i = 1; i < 100000; i++) {
        addUpForm(i);
    }


    auto overallEnd = chrono::high_resolution_clock::now();
    auto durationMicro = chrono::duration_cast<chrono::microseconds>(overallEnd - overallStart).count();
    auto duration = chrono::duration_cast<chrono::seconds>(overallEnd - overallStart).count();

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
}

void addUpExample(int num) {
    auto start = chrono::high_resolution_clock::now();

    cout << "Sum of numbers from 0 - " << num << " recursively: " << addUp(num) << endl;
    auto end = chrono::high_resolution_clock::now();
    auto durationMicro = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "Execution time (microseconds): " << durationMicro << endl;


    start = chrono::high_resolution_clock::now();

    cout << "Sum of numbers 0 - " << num << " using formula: " << addUpForm(num) << endl;

    end = chrono::high_resolution_clock::now();
    durationMicro = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "Execution time (microseconds): " << durationMicro << endl << endl;
}*/