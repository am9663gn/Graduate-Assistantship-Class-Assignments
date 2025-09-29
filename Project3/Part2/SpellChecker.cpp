/**
 * @file SpellChecker.cpp
 * @brief A spell checker program that uses DoublyLinkedBag as a dictionary.
 *
 * Program workflow:
 *   1. Loads words from a dictionary file into a DoublyLinkedBag (all lowercase).
 *   2. Prompts the user for an input text file.
 *   3. Reads each word from the input file, converts it to lowercase.
 *   4. Prints words not found in the dictionary as "misspelled".
 *
 * Example run:
 *   Enter the name of the file that contains words to check: myreport.txt
 *
 *   The following words in the file "myreport.txt" are not spelled correctly:
 *   Stude
 *   Reseach
 *   Resul
 *   Outpt
 *
 *   Thanks for using the spell checker system.
 *
 * Author: Dinesh Seveti
 * Course: CSCI 301
 * Date: Fall 2025
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "DoublyLinkedBag.h"

using namespace std;

/**
 * Converts a string to lowercase.
 * @param word The input string.
 * @pre None.
 * @post Returns the lowercase version of the string.
 */
string toLowerCase(const string& word) {
    string result;
    for (char c : word) {
        result += tolower(c);
    }
    return result;
}

/**
 * Main driver for the spell checker program.
 * @pre "dictionary.txt" must exist in the current directory with lowercase words.
 * @pre The user must provide a valid input filename.
 * @post Outputs all misspelled words from the input file.
 * @return 0 upon successful execution, nonzero if file errors occur.
 */
int main() {
    DoublyLinkedBag<string> dictionary;

    // Load dictionary
    string dictFile = "dictionary.txt";
    ifstream dictStream(dictFile);
    if (!dictStream) {
        cerr << "Error: Cannot open dictionary file." << endl;
        return 1;
    }

    string word;
    while (dictStream >> word) {
        dictionary.add(toLowerCase(word));
    }
    dictStream.close();

    // Ask user for file to check
    string inputFile;
    cout << "Enter the name of the file that contains words to check: ";
    cin >> inputFile;

    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Error: Cannot open input file." << endl;
        return 1;
    }

    cout << "\nThe following words in the file \"" << inputFile
         << "\" are not spelled correctly:\n";

    bool foundMisspelled = false;
    while (inFile >> word) {
        string lower = toLowerCase(word);
        if (!dictionary.contains(lower)) {
            cout << word << endl;
            foundMisspelled = true;
        }
    }
    inFile.close();

    if (!foundMisspelled) {
        cout << "(No spelling errors found.)" << endl;
    }

    cout << "\nThanks for using the spell checker system." << endl;
    return 0;
}
