#include <iostream>
#include <algorithm>  // For std::sort
#include <fstream>    // For file output
#include <random>     // For random number generation
#include <chrono>     // For measuring time
#include "sort.h"     // custom sort

// const size_t numValues = 10000000;


// random number generator
int RandomNumber() {
    static std::mt19937 generator(42);
    std::uniform_int_distribution<int> distribution(0, 99999); 
    return distribution(generator);  
}

int sort_pro_i() {
    
    const size_t numValues = 10000000;  // 10 m

    // Dynamic array of int to hold the 10m random numbers
    int* values = new int[numValues];

    // Generate 10m random numbers
    for (size_t i = 0; i < numValues; ++i) {
        values[i] = RandomNumber();  
    }

    // Measure time for sorting
    auto start = std::chrono::high_resolution_clock::now();

    // Sort the array of values in increasing order
    quicksort(values, 0, numValues-1);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sortDuration = end - start;
    std::cout << "Sorting took: " << sortDuration.count() << " seconds.\n";

    // Output the sorted values to a file
    std::ofstream outputFile("sorted_int_numbers.txt");
    if (outputFile.is_open()) {
        for (size_t i = 0; i < numValues; ++i) {
            outputFile << values[i] << "\n";  // Write each number followed by a newline
        }
        outputFile.close();
    } else {
        std::cerr << "Unable to open the file for writing.\n";
    }

    // Free the dynamic memory
    delete[] values;

    return 0;
}