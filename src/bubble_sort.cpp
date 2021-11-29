#include "bubble_sort.h"

void bubbleSort(std::vector<int>& arr){
    int n = arr.size();
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            std::swap(arr[j], arr[j+1]);
}


