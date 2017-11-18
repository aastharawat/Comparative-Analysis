/*
************************************
*              MINOR               *
*             PROJECT              *
************************************
*/

/* It may take a little while to do all the processing
   while compilation.
   PLEASE HAVE PATITENCE. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//For using bool variable
#include <stdbool.h>

//Sorting Code container file
#include "sorting_codes.h"

//Searching Code container file (Out of Service)
//#include "searching_codes.h"

//Random Number generator file (Out of Service)
// #include "random_generator.h"

//Analysis file (Out of Service)
//#include "exec_analysis.h"

int main(){

	//RANDOM NUMBER GENERATOR CODE
	int n = 50000;
	int arr[n];
	clock_t t;
	/* Intializes random number generator */
	srand((unsigned) time(&t));
	for(int i = 0 ; i < n ; i++ ) 
    {
        arr[i] =  rand() % 1000000;
    }

	/* Temporary Array to save Original Array for all Sorting */
	int tmp[n];
	for(int i = 0 ; i < n ; i++ ) 
    {
        tmp[i] = arr[i];
    }

	//MERGE SORT
	clock_t begin_merge = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end_merge = clock();
	for(int i = 0 ; i < n ; i++ ) 
    {
        arr[i] = tmp[i];
    }

    //BUBBLE SORT
    clock_t begin_bubble = clock();
    bubbleSort(arr, n);
    clock_t end_bubble = clock();
    for(int i = 0 ; i < n ; i++ ) 
    {
        arr[i] = tmp[i];
    }

    //HEAP SORT
    clock_t begin_heap = clock();
    heapSort(arr, n);
    clock_t end_heap = clock();
    for(int i = 0 ; i < n ; i++ ) 
    {
        arr[i] = tmp[i];
    }

    //INSERTION SORT
    clock_t begin_insertion = clock();
    insertionSort(arr, n);
    clock_t end_insertion = clock();
    for(int i = 0 ; i < n ; i++ ) 
    {
        arr[i] = tmp[i];
    }

    //QUICK SORT
	clock_t begin_quick = clock();
    quickSort(arr, 0, n - 1);
    clock_t end_quick = clock();
    for(int i = 0 ; i < n ; i++ ) 
    {
        arr[i] = tmp[i];
    }

	//SELECTION SORT
    clock_t begin_selection = clock();
    selectionSort(arr, n);
    clock_t end_selection = clock();
    for(int i = 0 ; i < n ; i++ ) 
    {
        arr[i] = tmp[i];
    }

	//SHELL SORT
    clock_t begin_shell = clock();
    shellSort(arr, n);
    clock_t end_shell = clock();
    for(int i = 0 ; i < n ; i++ ) 
    {
        arr[i] = tmp[i];
    }

	//COCKTAIL SORT
    clock_t begin_cocktail = clock();
    cocktailSort(arr, n);
    clock_t end_cocktail = clock();
    for(int i = 0 ; i < n ; i++ ) 
    {
        arr[i] = tmp[i];
    }

	//BUCKET SORT
    clock_t begin_bucket = clock();
    bucketSort(arr, n);
    clock_t end_bucket = clock();
    for(int i = 0 ; i < n ; i++ ) 
    {
        arr[i] = tmp[i];
    }

	//Calculation of Execution Times and Printing them
    double time_spent_merge = (double)(end_merge - begin_merge) / CLOCKS_PER_SEC;
    printf("Time Taken by Merge Sort: %f \n", time_spent_merge);

    double time_spent_bubble = (double)(end_bubble - begin_bubble) / CLOCKS_PER_SEC;
    printf("Time Taken by Bubble Sort: %f \n", time_spent_bubble);

    double time_spent_heap = (double)(end_heap - begin_heap) / CLOCKS_PER_SEC;
    printf("Time Taken by Heap Sort: %f \n", time_spent_heap);

    double time_spent_insertion = (double)(end_insertion - begin_insertion) / CLOCKS_PER_SEC;
    printf("Time Taken by Insertion Sort: %f \n", time_spent_insertion);

    double time_spent_quick = (double)(end_quick - begin_quick) / CLOCKS_PER_SEC;
    printf("Time Taken by Quick Sort: %f \n", time_spent_quick);

    double time_spent_selection = (double)(end_selection - begin_selection) / CLOCKS_PER_SEC;
    printf("Time Taken by Selection Sort: %f \n", time_spent_selection);

    double time_spent_shell = (double)(end_shell - begin_shell) / CLOCKS_PER_SEC;
    printf("Time Taken by Shell Sort: %f \n", time_spent_shell);

    double time_spent_cocktail = (double)(end_cocktail - begin_cocktail) / CLOCKS_PER_SEC;
    printf("Time Taken by Cocktail Sort: %f \n", time_spent_cocktail);

    double time_spent_bucket = (double)(end_bucket - begin_bucket) / CLOCKS_PER_SEC;
    printf("Time Taken by Bucket Sort: %f \n", time_spent_bucket);


	return 0;
}

/* PS: All the algos have been checked individually
and they all are giving similar results after group execution
and solo execution. */

//Copyright ABSphreak Co. 2017