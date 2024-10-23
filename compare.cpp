#include <iostream>
#include <fstream>  // for opening file and geting line

bool compareFiles(const std::string& file1, const std::string& file2) {
    std::ifstream f1(file1);
    std::ifstream f2(file2);

    if (!f1.is_open() || !f2.is_open()) {
        std::cerr << "there is a missing file " << file1 << ", " << file2 << std::endl;
        return false;
    }

    std::string line1, line2;

    // Compare files line by line
    while (std::getline(f1, line1) && std::getline(f2, line2)) {
        if (line1 != line2) {
            return false;  // Lines are different
        }
    }

    // Check if either file has extra content
    if (std::getline(f1, line1) || std::getline(f2, line2)) {
        return false;  // One file has extra content 
                        //(this should not happen since we forced the files to have the same number of lines)
    }

    return true;  // Files are identical
}

int comparing(const std::string& file1, const std::string& file2) {
    // std::string file1 = "sorted_double_numbers.txt";
    // std::string file2 = "sorted_numbers_pre_double.txt";

    bool result = compareFiles(file1, file2);

    if (result) {
        std::cout << file1 << "   and   " << file2 << "   are IDENTICAL" <<std::endl;
    } else {
        std::cout << file1 << "   and   " << file2 << "   are DIFFERENT" <<std::endl;
    }

    return 0;
}
