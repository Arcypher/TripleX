#include <iostream>
#include <stdlib.h>
#include <string>
#include <regex>
#include <time.h>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

/**
 * Data structure to hold the keycode values
 * 
 */
struct Keycode {
    int a;
    int b;
    int c;
};

//static variables
vector<int> guessesStorage;

//static functions
int sumOfKeycodes(Keycode &keycode);
int productOfKeycodes(Keycode &keycode);
int sumOfGuesses();
int productOfGuesses();

string generateGuesses(Keycode &keycode);

vector<int> storeGuesses(const string &guesses);

char choosePlayCode();

void showIntroPrompt();
void showCodePrompt(Keycode &keycode);
void generateKeycodeNumbers(Keycode &keycode);
void processGuesses(Keycode &keycode);
void checkResults(Keycode &keycode);
void initialize();

/**
 * Main driver of the program.
 * 
 */
int main() {
    initialize();
    return 0;
}

/**
 * Handles the multiple functions necessary for the game to run.
 * 
 */
void initialize() {
    Keycode keycode; //Structure will be referenced to get values.
    char playCode;
    do {
        generateKeycodeNumbers(keycode);
        showIntroPrompt();
        showCodePrompt(keycode);
        processGuesses(keycode);
        checkResults(keycode);
        playCode = choosePlayCode();
    } while (playCode != 'q');
    cout << "Good-bye!" << endl;
}

/**
 * Take the values of keycodes a,b,c and return the sum
 * 
 */
int sumOfKeycodes(Keycode &keycode) {
    return keycode.a + keycode.b + keycode.c;
}

/**
 * Take the values of keycodes a,b,c and return the product.
 * 
 */
int productOfKeycodes(Keycode &keycode) {
    return keycode.a * keycode.b * keycode.c;
}

/**
 * Show the introduction
 * 
 */
void showIntroPrompt() {
    cout << endl;
    cout << "You are a secret agent breaking into a secure server room..." << endl;
    cout << "Enter the correct code to continue..." << endl;
    cout << endl;
}

/**
 * Show the sum and product of the three keycodes
 * 
 */
void showCodePrompt(Keycode &keycode) {
    cout << "There are three numbers in the code." << endl;
    cout << "The codes add-up to: " << sumOfKeycodes(keycode) << endl;
    cout << "The codes multiply to: " << productOfKeycodes(keycode) << endl;
    cout << endl;
}

/**
 * Generate the keycode values randomly
 * 
 */
void generateKeycodeNumbers(Keycode &keycode) {
    srand(time(nullptr)); //seed initialize random
    //values (for now) will be from 1 - 10
    //can add a parameter to replace "10" so range can be from 1 to n
    //This change will be based on difficulty
    keycode.a = rand() % 10 + 1;
    keycode.b = rand() % 10 + 1;
    keycode.c = rand() % 10 + 1;
}

/**
 * Process the guesses so they can account
 * for multiple cases.
 */
void processGuesses(Keycode &keycode) {
    string guesses = generateGuesses(keycode);
    guessesStorage = storeGuesses(guesses);
}

/**
 *  Parse the string of guesses into integer values
 *  and store them into a vector. 
 * 
 */
vector<int> storeGuesses(const string &guesses) {
    vector<int> tempStorage;
    stringstream ss(guesses);
    string token;
    while (getline(ss, token, ' ')) {
        tempStorage.push_back(stoi(token));
    }
    return tempStorage;
}

/**
 * Take in user input.
 * (Will modify for difficulty sake)
 */
string generateGuesses(Keycode &keycode) {
    string guesses;
    regex inputValidator("^\\d*\\s\\d*\\s\\d*$");
    cout << "Enter in three numbers from 1 - 10 with spaces in between: ";
    while (getline(cin, guesses)) {
        if (!regex_match(guesses, inputValidator)) {
            cout << "This is not valid input! Please try again." << endl;
        } else {
            break;
        }
        cout << "Enter in three numbers from 1 - 10 with spaces in between: ";
    }
    return guesses;
}

/**
 * Returns the sum of the numbers from user input
 * 
 */
int sumOfGuesses() {
    int sum = 0;
    for (vector<int>::size_type i = 0; i < guessesStorage.size(); i++) {
        sum += guessesStorage.at(i);
    }
    return sum;
}

/**
 * Returns the product of the numbers from user input
 * 
 */
int productOfGuesses() {
    int product = 1;
    for (vector<int>::size_type i = 0; i < guessesStorage.size(); i++) {
        product *= guessesStorage.at(i);
    }
    return product;
}

/**
 * Checks to see if the user has won or not
 * 
 */
void checkResults(Keycode &keycode) {
    int guessSum = sumOfGuesses();
    int guessProduct = productOfGuesses();

    if ((guessSum == sumOfKeycodes(keycode)) && (guessProduct == productOfKeycodes(keycode))) {
        cout << "Congrats! You escaped!" << endl;
    } else {
        cout << "You died! How unfortunate..." << endl;
    }
    cout << endl;
}

/**
 * Ask the user to play again.
 * 
 */
char choosePlayCode() {
    char playCode;
    cout << "Would you like to play again?" << endl;
    cout << "Press any key except \'q\' to play again. Press \'q\' to quit: ";
    cin >> playCode;
    cin.ignore();
    return playCode;
}