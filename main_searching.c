/*
************************************
*              MINOR               *
*             PROJECT              *
************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//For using bool variable
#include <stdbool.h>

//Searching Codes
#include "searching_codes.h"

int main(){
	//RANDOM NUMBER GENERATOR CODE
	int n = 50000;
	int arr[n];
	clock_t t;
	/* Intializes random number generator */
	srand((unsigned) time(&t));
	for(int i = 0 ; i < n ; i++ ) {
        arr[i] =  rand() % 1000000;
    }

    //Element to search (Middle one in Array)
    int x = arr[n/2];
    printf("This is going to be searched %d \n", x);

	clock_t begin_linear = clock();
    int lin = linearSearch(arr, n, x);
    clock_t end_linear = clock();
	
	clock_t begin_binary = clock();
    int bin = binarySearch(arr, 0, n-1, x);
    clock_t end_binary = clock();

    double time_spent_linear = (double)(end_linear - begin_linear) / CLOCKS_PER_SEC;
    printf("Time Taken by Linear Search: %f \n", time_spent_linear);
	
	double time_spent_binary = (double)(end_binary - begin_binary) / CLOCKS_PER_SEC;
    printf("Time Taken by Binary Search: %f \n", time_spent_binary);

	return 0;
}
//These two algorithms take very less time to execute...
//Perhaps increase the dataset size.
//Copyright ABSphreak Co. 2017