# C++ Sorting Numbers

## Compilation

To compile the code, run the following command:

```bash
g++ main.cpp sort.cpp sort_d.cpp complete_d.cpp complete_i.cpp task_comp.cpp task_comp_d.cpp compare.cpp -o sorting_program
```
## Running the code

Since the compiled `sorting_program.exe` already exists, with a working installation of C++, you should be able to execute `.\sorting_program.exe` inside the working folder to run the program.

## Expected Output

The following output is expected in the terminal:

```bash
Sorting took: 1.09141 seconds.
Sorting took: 1.09572 seconds.
Sorting took: 1.1199 seconds.
Now lets compare with a pre-build sorting algorithm
This will be done for the Int and the complete floats
------------------------------------------------------
Sorting took: 0.978548 seconds.
Sorting took: 1.2099 seconds.
sorted_int_numbers.txt   and   sorted_numbers_pre_int.txt   are IDENTICAL
sorted_double_numbers.txt   and   sorted_numbers_pre_double.txt   are IDENTICAL
```
This is creating the sorted files, comparing the times and checking that the sorting between the pre-build function and the one presented are actually equal.

## Explaining the different .txt

* sorted_double_numbers_5decimals.txt --> Double precision numbers (5 decimal places) sorted by the hand-build algorithm
* sorted_double_numbers.txt           --> All double precision numbers sorted by the custom algorithm
* sorted_int_numbers.txt              --> Int numbers sorted by hand-build algorithm
* sorted_numbers_pre_double.txt       --> All decimals numbers sorted by pre-build algorithm (imported library)
* sorted_numbers_pre_int.txt          --> Int numbers sorted by pre-build algorithm (imported library)
* sorting_program.exe                 --> Executable generated by compiling with the initial compilation command

## Explaining the compare

The idea is that, if the hand-build sorting algorithm provides the same result as the pre-build algorithm then it should be a correct result, We compare 2 cases:

* sorted_int_numbers.txt   and   sorted_numbers_pre_int.txt  
* sorted_double_numbers.txt   and   sorted_numbers_pre_double.txt

Both proven to be identical, chequed line by line.
