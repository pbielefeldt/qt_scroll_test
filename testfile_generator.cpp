#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

/* compile with
g++ -Wall --pedantic -std=gnu++17 -o testfile_generator.o testfile_generator.cpp
*/

// Function to generate a random English word
std::string getRandomWord() {
    // List of sample English words for demonstration purposes
    std::vector<std::string> words = {
        "apple", "banana", "cherry", "dog", "elephant", "frog", "grape",
        "house", "igloo", "jungle", "kangaroo", "lemon", "monkey", "nest",
        "orange", "parrot", "quokka", "rabbit", "snake", "tiger", "umbrella",
        "vulture", "watermelon", "xylophone", "zebra"
    };

    // Get a random index
    int index = rand() % words.size();

    // Return the random word
    return words[index];
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    // Open the first output file (test_1.txt)
    std::ofstream outFile1("test_1.txt");

    if (!outFile1) {
        std::cerr << "Error: Could not open test_1.txt for writing." << std::endl;
        return 1;
    }

    // Generate 80 lines with line numbers and random words for test_1.txt
    for (int lineNumber = 1; lineNumber <= 80; ++lineNumber) {
        std::string word1 = getRandomWord();
        std::string word2 = getRandomWord();

        // Write the line to test_1.txt
        outFile1 << lineNumber << ": " << word1 << " " << word2 << "\n";
    }

    // Close the first file (test_1.txt)
    outFile1.close();

    std::cout << "Test file 'test_1.txt' generated successfully." << std::endl;

    // Open the second output file (test_2.txt)
    std::ofstream outFile2("test_2.txt");

    if (!outFile2) {
        std::cerr << "Error: Could not open test_2.txt for writing." << std::endl;
        return 1;
    }

    // Generate 96 lines with line numbers and random words for test_2.txt
    for (int lineNumber = 1; lineNumber <= 96; ++lineNumber) {
        std::string word1 = getRandomWord();
        std::string word2 = getRandomWord();

        // Write the line to test_2.txt
        outFile2 << lineNumber << ": " << word1 << " " << word2 << "\n";
    }

    // Close the second file (test_2.txt)
    outFile2.close();

    std::cout << "Test file 'test_2.txt' generated successfully." << std::endl;

    return 0;
}
