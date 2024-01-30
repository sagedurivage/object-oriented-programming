#include "minFunc.h"

const int * min(const int arr[], int arrSize) {
    // base case 1: empty list
    if (arrSize == 0) {
        return nullptr;
    }
    // base case 2: list of 1 element
    else if (arrSize == 1) {
        return arr;
    }
    // recursive case
    else {
        // pointer to end of list
        const int * i = arr + (arrSize - 1);
        // pointer to min
        const int * j = min(arr, arrSize - 1);
        if (*j < *i) {
            return j;
        } else {
            return i;
        }
    }
}