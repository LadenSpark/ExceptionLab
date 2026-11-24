/**
* @file Exceptions.cpp
 * @brief Implements the custom exception classes.
 *
 * This file provides the definitions for the constructors
 * and 'what()' methods for the custom exception classes.
 *
 * @author Jason Suits 
 * @date 11/01/2023
 * @version 1.Jay
 */

#include "Exceptions.h"

/**
 * @brief Returns the error message for FileOpenException.
 */
const char* FileOpenException::what() const noexcept {
    // .c_str() returns a const char* representation of the std::string
    return msg.c_str();
}

/**
 * @brief Returns the error message for ParseException.
 */
const char* ParseException::what() const noexcept {
    // .c_str() returns a const char* representation of the std::string
    return msg.c_str();
}

