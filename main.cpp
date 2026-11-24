/**
 * @file main.cpp
 * @brief Main client program for the ShapeFile Parser.
 *
 * This program reads shape data from a file, validates it, and calculates
 * areas. It handles all file and data exceptions.
 *
 * @author Jason Suits
 * @date 11/23/2026
 * @version 1.0
 */

#include <iostream>
#include <fstream>      // For file I/O (ifstream)
#include <string>       // For std::string
#include <iomanip>      // For std::setprecision
#include <stdexcept>    // For std::invalid_argument
#include <exception>    // For std::exception

#include "GeometryUtils.h"
#include "Exceptions.h"
#include "FileUtils.h"
#include <limits>      // For std::numeric_limits

using namespace std;

/**
 * @brief Main entry point for the ShapeFile Parser.
 *
 * This function contains all client logic. It handles:
 * 1. Prompting for an initial filename.
 * 2. Calling the file-opening utility.
 * 3. Reading the file line by line.
 * 4. Catching ParseException for unknown shape types.
 * 5. Catching std::invalid_argument for invalid shape dimensions.
 * 6. Catching std::exception for any other unexpected errors.
 */
int main() {
    // Set up clean console output for floating point numbers
    cout << fixed << setprecision(2);

    string filename;
    ifstream file;
    int lineNumber = 0;

    // --- 1. File Opening Logic ---
    cout << "Enter filename: ";
    cin >> filename;

    openFileForReading(file, filename);

    // --- 2. File Parsing Logic ---
    cout << "--- Processing Shapes ---" << endl;
    string shapeType;

    while (file >> shapeType) {
        lineNumber++;

        try {
            if (shapeType == "square") {
                double side;
                file >> side;
                double area = calculateArea(side);
                cout << "Line " << lineNumber << ": Square Area: " << area << endl;
            }
            else if (shapeType == "rectangle") {
                double length, width;
                file >> length >> width;
                double area = calculateArea(length, width);
                cout << "Line " << lineNumber << ": Rectangle Area: " << area << endl;
            }
            else if (shapeType == "circle") {
                double radius;
                file >> radius;
                double area = calculateCircleArea(radius);
                cout << "Line " << lineNumber << ": Circle Area: " << area << endl;
            }
            else {
                throw ParseException("Unknown shape type: " + shapeType);
            }
        }
        catch (const ParseException& e) {
            cerr << "Line " << lineNumber << ": Parse Error - " << e.what() << endl;
        }
        catch (const std::invalid_argument& e) {
            cerr << "Line " << lineNumber << ": Invalid Argument - " << e.what() << endl;
        }
        catch (const std::exception& e) {
            cerr << "Line " << lineNumber << ": Unexpected Error - " << e.what() << endl;
        }
    }

    // --- 3. Cleanup ---
    cout << "--- Processing Complete ---" << endl;
    file.close();

    cout << "\nPress Enter to exit...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;

    return 0;
}