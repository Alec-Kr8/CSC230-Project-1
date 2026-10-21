/*
* Name : Alec Krishnakumar
* Date : September 18, 2025
* File Name : Project01.cpp
* Description: Word Search puzzle solver using wordsearch class. 
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Global
    int nrows;
    int ncols;
    char* input;
    char* output;


    // Initialize a new Word Search game given a data file name
    bool initGame(string filename) {
    ifstream fin(filename);
    
    // Check file was found
    if (!fin.is_open()) {
        cout << filename << " not found" << endl;
        return false;
    }
    // Read grid dimensions from filestream to initialize globals 
    fin >> nrows >> ncols;
    
    // Create new chars for both input and output 
    input = new char[nrows * ncols];
    output = new char[nrows * ncols];


    // Creates for loop that reads next row and column characters 
    for(int i = 0; i < nrows * ncols; ++i) {
        fin >> input[i];
        output[i] = '-';
    }


    // returns true if sucessful 
    return true;
}


    // Add Printgrid function 
    void printGrid(char input[]) {
    // Create nested for loop to add rows and columns to the grid
    for (int r = 0; r < nrows; ++r) {
        // Loop for coulumns
        for (int c = 0; c < ncols; ++c) {
            // Convert to sequential array index
            int i = r * ncols + c;
            // Add space in between each print
            cout << input[i] << " ";
        }
        cout << endl;
    }
}

    // Check if a word exists starting at (r,c) 
    bool isWordAtInput(string word, int r, int c, int rincr, int cincr) {
        for (int i = 0; i < (int)word.size(); i++) {
            // Checks boundaries
            if (r < 0 || r >= nrows || c < 0 || c >= ncols) {
                return false;
            }
            //check match
            if (input[r * ncols + c] != word[i]) {
                return false;
            }

            //move to next row or column
            r += rincr;
            c += cincr;
        }
        // word matches
        return true;
    }

            // Place a found word into the output grid
    void setWordAtOutput(string word, int r, int c, int rincr, int cincr) {
        for (int i = 0; i < (int)word.size(); i++) {
            output[r * ncols + c] = word[i];
            // Set char in output grid
            r += rincr; 
            c += cincr;
        }
    }
    
    // Search for the word in all directions and positions in the grid
    void findWord(string word) {
        for (int r = 0; r < nrows; r++) {
            for (int c = 0; c < ncols; c++) {
                for (int rincr = -1; rincr <= 1; rincr++) {
                    for (int cincr = -1; cincr <= 1; cincr++) {
                        if (rincr == 0 && cincr == 0) continue;
                            if (isWordAtInput(word, r, c, rincr, cincr)) {
                            setWordAtOutput(word, r, c, rincr, cincr);
                        }
                    }
                }
            }
        }
    }

// main function
int main(int argc, char* argv[]) {
    

    string filename(argv[1]);
    
    if (!initGame(filename)) { return -1; }
    
    // prints out the grid when searching
    printGrid(input);

    // for loop for when code is searching for word
    for (int i=2; i<argc; ++i) {
        string word(argv[i]);
        cout << "Searching for " << word << endl;
        findWord(word);
    }

    // print the output grid 
    printGrid(output);
// delete the input and output to present leak.
    delete[] input;

    delete[] output;

    return 0;
}






    