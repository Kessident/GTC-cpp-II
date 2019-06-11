//Charles Dodge
//CIST 2362 CRN 63228
//Lab 8 Text File Analysis
#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

int doContinue = 0;

ifstream attemptToOpen(string);
set<string> readFileToSet(string);

int main() {
    do {
        cout << "This program will perform various analysis on two text files\n";
        string fileOne, fileTwo;

        cout << "Please enter file location for file one: ";
        cin >> fileOne;
        set<string> wordsInFileOne = readFileToSet(fileOne);

        cout << "Please enter file location for file two: ";
        cin >> fileTwo;
        set<string> wordsInFileTwo = readFileToSet(fileTwo);

//setOne UNION setTWo
        vector<string> oneUNIONtwo;
        set_union(wordsInFileOne.begin(), wordsInFileOne.end(), wordsInFileTwo.begin(), wordsInFileTwo.end(), back_inserter(oneUNIONtwo));
        cout << "-----Unique words contained in both files-----\n";
        for (const string &s : oneUNIONtwo)
            cout << s << endl;

//setOne INTERSECTION setTwo
        vector<string> oneINTERSECTtwo;
        set_intersection(wordsInFileOne.begin(), wordsInFileOne.end(), wordsInFileTwo.begin(), wordsInFileTwo.end(), back_inserter(oneINTERSECTtwo));
        cout << "-----Words contained in BOTH files-----\n";
        for (const string &s : oneINTERSECTtwo)
            cout << s << endl;

//setOne - setTwo Difference
        vector<string> oneDIFFERENCEtwo;
        set_difference(wordsInFileOne.begin(), wordsInFileOne.end(), wordsInFileTwo.begin(), wordsInFileTwo.end(), back_inserter(oneDIFFERENCEtwo));
        cout << "-----Words that appear in the first file, but not the second-----\n";
        for (const string &s : oneDIFFERENCEtwo)
            cout << s << endl;

//setTeo - setOne Difference
        vector<string> twoDIFFERENCEone;
        set_difference(wordsInFileTwo.begin(), wordsInFileTwo.end(), wordsInFileOne.begin(), wordsInFileOne.end(), back_inserter(twoDIFFERENCEone));
        cout << "-----Words that appear in the second file, but not the first-----\n";
        for (const string &s : twoDIFFERENCEone)
            cout << s << endl;

//setOne OR setTwo, not BOTH
        vector<string> symmetricDifference;
        set_symmetric_difference(wordsInFileOne.begin(), wordsInFileOne.end(), wordsInFileTwo.begin(), wordsInFileTwo.end(), back_inserter(symmetricDifference));
        cout << "-----Words contained in either the first or second file, but not both-----\n";
        for (const string &s : symmetricDifference)
            cout << s << endl;

        cout << endl << "enter 1 to go again, anything else to exit ";
        cin >> doContinue;
        cin.ignore();
    } while (doContinue == 1);
    return 0;
}

ifstream attemptToOpen(string fileLoc){
    ifstream inputFile (fileLoc);
    //While file not open
    while (!inputFile) {
        cout << "Error opening " << fileLoc <<endl;
        cout << "Please try again: ";
        cin >> fileLoc;

        inputFile.open(fileLoc);
    }

    return inputFile;
}

set<string> readFileToSet(string fileLoc){
    ifstream inputFile = attemptToOpen(std::move(fileLoc));
    //set to be returned
    set<string> returnSet;
    string temp;

    //While data to read
    while (inputFile) {
        getline(inputFile, temp, ' ');
        returnSet.insert(returnSet.end(), temp);
    }

    return returnSet;
}

/*
//Lab 8 Capital Quiz
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <random>

using namespace std;
int doContinue = 0;

const string FILE_LOC = "State-Capitals.txt";

unordered_map<string, string> readCapitals(string);

int main() {
    do {
        unordered_map<string, string> stateCapitals = readCapitals(FILE_LOC);
        int correctAnswers = 0;
        int incorrectAnswers = 0;

        cout << "This program will quiz you on states and their capitals.\n";
        cout << "And display how many you got right and wrong at the end.\n";
        cout << "Note: as theses are proper nouns, capitalization matters.\n";
        cout << "     e.g. \"new hampsire\" != \"New Hampshire\"\n";

        int numGuesses;
        cout << "How many questions would you like? ";
        cin >> numGuesses;

        //Validate for integers
        while (cin.fail() || numGuesses < 1){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Please enter a number greater than 0: ";
            cin >> numGuesses;
        }

        //Random Number Gens, [0-stateCapitals.size())
        default_random_engine gen;
        uniform_int_distribution<int>distribution(0,stateCapitals.size()-1);
        auto rand = bind(distribution, gen);

        //Iterator used for random state/capital lookups
        auto randState = stateCapitals.begin();

        //Guessing Loop
        string userGuess;
        for (int i = 0; i < numGuesses; ++i) {
            //Select new random state/capital
            advance(randState, rand());

            //Get guesses
            cout << "----------Round " << (i + 1) << "----------\n";
            cout << "What is the capital of " << randState->first << "? ";
            cin >> userGuess;


            if (userGuess == randState->second){
                cout << "Correct\n";
                correctAnswers++;
            } else {
                cout << "Incorrect. The correct answer was " << randState->second << endl;
                incorrectAnswers++;
            }
            //Reset iterator
            randState = stateCapitals.begin();
        }

        cout << "----------Results----------\n";
        cout << "You got " << correctAnswers << " correct and " << incorrectAnswers << " incorrect\n";

        cout << endl << "enter 1 to go again, anything else to exit ";
        cin >> doContinue;
        cin.ignore();
    } while (doContinue == 1);
    return 0;
}

unordered_map<string, string> readCapitals(const string fileLoc) {
    unordered_map<string, string> stateCapitals;
    ifstream stateCapitalsFile(fileLoc);

    //File open successfully
    if (stateCapitalsFile) {
        //Temp storage for state and capital
        string state;
        string capital;
        //While data to read
        while (stateCapitalsFile) {
            //"State,Capital," format
            getline(stateCapitalsFile, state, ',');
            getline(stateCapitalsFile, capital, ',');
            stateCapitals.insert(pair<string, string>(state, capital));

        }
        stateCapitalsFile.close();

    } else {
        cout << "Error opening file";
        exit(-1);
    }
    return stateCapitals;
}*/