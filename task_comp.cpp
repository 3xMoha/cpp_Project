#include <iostream>
#include <algorithm>  // For std::sort
#include <fstream>    // For file output
#include <random>     // For random number generation
#include <chrono>     // For measuring time

// Function that simulates a random number generator with a seed
int RandomNumber3() {
    static std::mt19937 generator(42);
    std::uniform_int_distribution<int> distribution(0, 99999); 
    return distribution(generator);  
}

int sort_pre_int() {
    // Number of random values to generate
    const size_t numValues = 10000000;  // 10 million

    // Dynamically allocate an array to hold the generated numbers
    int* values = new int[numValues];

    // Generate 10,000,000 random numbers
    for (size_t i = 0; i < numValues; ++i) {
        values[i] = RandomNumber3();  // Call RandomNumber with i as the seed
    }

    // Measure time for sorting
    auto start = std::chrono::high_resolution_clock::now();

    // Sort the array of values in increasing order
    std::sort(values, values + numValues);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sortDuration = end - start;
    std::cout << "Sorting took: " << sortDuration.count() << " seconds.\n";

    // Output the sorted values to a file
    std::ofstream outputFile("sorted_numbers_pre_int.txt");
    if (outputFile.is_open()) {
        for (size_t i = 0; i < numValues; ++i) {
            outputFile << values[i] << "\n";  // Write each number followed by a newline
        }
        outputFile.close();
    } else {
        std::cerr << "Unable to open the file for writing.\n";
    }

    // Free the dynamically allocated memory
    delete[] values;

    return 0;
}
