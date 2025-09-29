/**
 * @file SpellChecker.cpp
 * @brief Spell checker program using DoublyLinkedBag as dictionary.
 *
 * The program:
 *  1. Loads a dictionary of lowercase words into a DoublyLinkedBag.
 *  2. Prompts user for the name of an input text file.
 *  3. Reads words from the file, converts them to lowercase.
 *  4. Prints words not found in dictionary as misspelled.
 *
 * Example run:
 *  Enter the name of the file that contains words to check: myreport.txt
 *  The following words in the file "myreport.txt" are not spelled correctly:
 *  Stude
 *  Reseach
 *
 * @author Dinesh Seveti
 * @course CSCI 301
 * @date Fall 2025
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
 * @post Returns the string converted to lowercase.
 */
string toLowerCase(const string& word) {
    string result;
    for (char c : word) {
        result += tolower(c);
    }
    return result;
}

/**
 * Main driver for spell checker.
 * @pre dictionary.txt must exist and contain lowercase words.
 * @pre User provides a valid input filename when prompted.
 * @post Program prints words not contained in dictionary.
 */
int main() {
    DoublyLinkedBag<string> dictionary;

    // Load dictionary
    string dictFile = "dictionary.txt";
    ifstream dictStream(dictFile);
    if (!dictStream) {
        cerr << "Error: Cannot open dictionary file.\n";
        return 1;
    }

    string word;
    while (dictStream >> word) {
        dictionary.add(toLowerCase(word));
    }
    dictStream.close();

    // Prompt user for file
    string inputFile;
    cout << "Enter the name of the file that contains words to check: ";
    cin >> inputFile;
    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Error: Cannot open input file.\n";
        return 1;
    }

    cout << "\nThe following words in the file \"" << inputFile 
         << "\" are not spelled correctly:\n";

    while (inFile >> word) {
        string lower = toLowerCase(word);
        if (!dictionary.contains(lower)) {
            cout << word << endl;
        }
    }
    inFile.close();

    cout << "\nThanks for using the spell checker system.\n";
    return 0;
}
