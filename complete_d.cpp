#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include "sort_d.h"  //custom sort


// bool limitToFiveDecimals = false;  // Limit precision to 5 decimal places
// Random number generator for double values
double RandomNumber(bool limitToFiveDecimals = false) {
    static std::mt19937 generator(42);
    std::uniform_real_distribution<double> distribution(0.0, 1.0); 
    
    // Generate a random number
    double number = distribution(generator);

    // If limiting precision to 5 decimal places, truncate it
    if (limitToFiveDecimals) {
        number = std::round(number * 100000.0) / 100000.0;  // Rounds to 5 decimal places
    }
    
    return number;  
}

int sort_pro_d(bool limitToFiveDecimals = false) {
    const size_t numValues = 10000000;  // 10 million

    // Dynamic array of double to hold the 10m random numbers
    double* values = new double[numValues];

    // Generate the 10m random double numbers
    for (size_t i = 0; i < numValues; ++i) {
        values[i] = RandomNumber(limitToFiveDecimals);
    }

    // Measure time for sorting
    auto start = std::chrono::high_resolution_clock::now();

    // Sort the array of values in increasing order
    quicksort_d(values, 0, numValues - 1);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sortDuration = end - start;
    std::cout << "Sorting took: " << sortDuration.count() << " seconds.\n";

    // Output the sorted values to a file
    if (limitToFiveDecimals == false){
        std::ofstream outputFile("sorted_double_numbers.txt");
        if (outputFile.is_open()) {
            for (size_t i = 0; i < numValues; ++i) {
                outputFile << values[i] << "\n";
            }
            outputFile.close();
        } else {
            std::cerr << "Unable to open the file for writing.\n";
        }
    }
    // if only 5 decimals
    else{
        std::ofstream outputFile("sorted_double_numbers_5decimals.txt");
        if (outputFile.is_open()) {
            for (size_t i = 0; i < numValues; ++i) {
                outputFile << values[i] << "\n";
            }
            outputFile.close();
        } else {
            std::cerr << "Unable to open the file for writing.\n";
        }
    }
    // Free the dynamic memory
    delete[] values;

    return 0;
}
