# Sorting
This program does a different types of sorting.

it takes as input from command line:\
1- Algorithm number:\
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0. Selection Sort\
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1. Insertion Sort\
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2. Merge Sort\
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3. Quick Sort\
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4. Hybrid Sort (Insertion and quick)\
2-Path to file contains data to sort.\
3-Path to file contains the output sorted data.\
4-Path to file contains the time that the algorithm takes.\

## To Run
After compiling: g++ sort.cpp\
Execute and pass the argument from the comman line: ./a{.out file} {algo. number:1} {input path:data.txt} {output path:sorted_data.txt} {time path:running_time.txt}\

## Extra (Optional)
1-runscript:\
  it's a python script which generates random data to be sorted just give him the size and path to put the data in: python runscript.py 100 data.txt\\

2-run:\
  it's a bash script which run the two previous code to generate random data with fixed sizes and run the program on it.\
