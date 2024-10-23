#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include "sort_d.h"
#include "complete_d.h"
#include "complete_i.h"

#include "compare.h"
#include "task_comp.h"
#include "task_comp_d.h"


int main() {
    sort_pro_i();
    sort_pro_d();
    sort_pro_d(true);
    std::cout << "Now lets compare with a pre-build sorting algorithm\n";
    std::cout << "This will be done for the Int and the complete floats\n";
    std::cout << "------------------------------------------------------\n"; 
    sort_pre_int();
    sort_pre_d();
    comparing("sorted_int_numbers.txt", "sorted_numbers_pre_int.txt");
    comparing("sorted_double_numbers.txt", "sorted_numbers_pre_double.txt");

    return 0;
}