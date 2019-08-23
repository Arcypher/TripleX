#include <iostream>
#include <stdlib.h>
#include <time.h>

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

int sumOfKeycodes(Keycode &keycode);
int productOfKeycodes(Keycode &keycode);
void showIntroPrompt();
void showCodePrompt(Keycode &keycode);
void generateKeycodeNumbers(Keycode &keycode);
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
    generateKeycodeNumbers(keycode);
    showIntroPrompt();
    showCodePrompt(keycode);
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
    cout << "The codes multiply to give: " << productOfKeycodes(keycode) << endl;
    cout << endl;
}

/**
 * Generate the keycode values randomly
 * 
 */
void generateKeycodeNumbers(Keycode &keycode) {
    srand(time(nullptr)); //seed initialize random
    keycode.a = rand() % 10 + 1;
    keycode.b = rand() % 10 + 1;
    keycode.c = rand() % 10 + 1;
}