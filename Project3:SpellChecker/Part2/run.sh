#!/bin/bash
echo "Compiling SpellChecker..."
g++ -std=c++11 SpellChecker.cpp -o spellchecker

echo "Running SpellChecker..."
./spellchecker <<EOF
myreport.txt
EOF
