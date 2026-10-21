// Name: Alec Krishnakumar
// Date: 09/04/2025
// File Name: Lab02.cpp
// Description: The file loads a predetermined grid for a word search game.

#include <iostream>
#include <fstream>

using namespace std;

// Globals
int nrows;
int ncols;
char input[1000]; // Sufficiently large for any puzzle

// Function prototypes
bool initGame(string filename);         // Initialize Word Search from cin
void printGrid(char grid[]);  // Print Word Search grid to terminal

// Create main function
int main() {
        if (!initGame("grid1.txt")) { return -1; };
        printGrid(input);
        return 0;
}

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

    // Creates for loop that reads next row and column characters 
    for(int i = 0; i < nrows * ncols; ++i) {
        fin >> input[i];
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