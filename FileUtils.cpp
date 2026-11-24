//
// Modded by Jason Suits on 10/29/25.
//
/**
 * @file FileUtils.cpp
 * @brief Implements utility functions for handling file operations.
 *
 * @author Jason Suits 
 * @date 11/01/2023
 * @version 1.Jay
 */

#include "FileUtils.h"
#include "Exceptions.h"     // Include for student's custom exceptions
#include <iostream>         // For cout, cerr, cin
#include <string>           // For string
#include <fstream>          // For ifstream
#include <cstdlib>         // For exit()


using namespace std;

/**
 * @brief Attempts to open a file, handling failures and retries.
 * * This function contains the logic that the student must
 * convert to use try...catch with FileOpenException.
 *
 * @param file The ifstream object to be opened (passed by reference).
 * @param initialFilename The first filename to try.
 */
void openFileForReading(std::ifstream& file, std::string initialFilename) {

    
    try {
        file.open(initialFilename);
        if (!file.is_open()) {
            throw FileOpenException("Error: Failed to open file: " + initialFilename);
        } else {
            cout << "File opened successfully: " << initialFilename << endl;
        }
    }

    catch (const FileOpenException& e) {
        cerr << "Caught FileOpenException: " << e.what() << endl;

            string alternativeFilename;
            cout << "Enter alternative filename: ";
            cin >> alternativeFilename;
            file.open(alternativeFilename);

            if (!file.is_open()) {
                cerr << "Error: Failed to open alternative file: " << alternativeFilename << endl;
                exit(EXIT_FAILURE);
            } else {
                cout << "Alternative file opened successfully: " << alternativeFilename << endl;
            }
    }

}

