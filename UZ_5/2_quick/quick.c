/* C implementation QuickSort */
#include<stdio.h> 

#define NUMBERS 4, \
                6, \
                2, \
                11, \
                3, \
                7,

#define SWAP(x,y) { int t = x;x = y;y = t; }

#define PRINTINT(x) printf("%d", x);

#define TAB "\t"

#define NEWLINE "\n"

#define FOR(a,b,c,d) for(int a = b; a <= c; d++)

#define QUICK(x,y,z); quickSort(x,y,z)


/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int * arr, int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    FOR (j, low, high-1, j){ 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            SWAP(arr[i], arr[j]); 
        } 
    } 
    SWAP(arr[i + 1], arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int *arr, int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        QUICK(arr, low, pi - 1);
        QUICK(arr, pi + 1, high);

    } 
} 
  
/* Function to print an array */
void printArray(int *arr, int size) 
{ 
    // int i; 
    FOR(i,0,size-1,i){
        PRINTINT(arr[i]);
        fflush(stdout);
        printf(TAB);
    }
} 
  
// Driver program to test above functions 
int main() 
{ 
    int arr[] = {NUMBERS}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    QUICK(arr, 0, n-1); 
    printf(NEWLINE);
    printArray(arr, n);
    printf(NEWLINE);
    return 0; 
} 
