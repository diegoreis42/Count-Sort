# Count Sort

## Introduction

Counting sort is an algorithm for sorting a collection of objects according to keys that are small integers; that is, it is an integer sorting algorithm. It operates by counting the number of objects that have each distinct key value, and using arithmetic on those counts to determine the positions of each key value in the output sequence. Its running time is linear in the number of items and the difference between the maximum and minimum key values, so it is only suitable for direct use in situations where the variation in keys is not significantly greater than the number of items. However, it is often used as a subroutine in another sorting algorithm, radix sort, that can handle larger keys more efficiently.

To give a sense of how counting sort works, consider the following list of numbers: [1, 3, 2, 3, 4, 1, 6, 4, 3]. The maximum value in the list is 6, so we create a counting list of size 7 (since the maximum value + 1 is 7). This list is used to keep track of the count of each unique number in the input list. We iterate over the input list and increment the count of the number at the corresponding index in the counting list. The counting list after this iteration is [0, 2, 1, 3, 2, 0, 1]. The next step is to iterate over the counting list and add the current value to the previous value. This gives us the position of each number in the output list. The counting list after this iteration is [0, 2, 3, 6, 8, 8, 9]. Finally, we iterate over the input list in reverse order and place each number in the output list at the index given by the counting list. The output list after this iteration is [1, 1, 2, 3, 3, 3, 4, 4, 6].

For a more detailed explanation of counting sort, refer to the [Wikipedia page](https://en.wikipedia.org/wiki/Counting_sort).

This project compares the performance of counting sort with other two sorting algorithms: MergeSort, QuickSort and InsertionSort.

## How to run the code

```
make all 

make clean
```
