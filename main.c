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
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "sorting_codes.h"
#include "searching_codes.h"
#include "analysis.h"

//Function declaration
int searching(int arr[], int n);
int sorting(int arr[], int n);

int main(){
	int i; //FOR FIRST SWITCH CASE
    int o; //FOR SECOND SWITCH CASE
    char filename[50];

    int n = 50000;
    int arr[n];

    printf("\nWELCOME TO ANALYSIS OF ALGORITHMS: \n");

    //MENU FOR ENTERING THE CUSTOM INPUT
    printf("Do you want to add custom input?\n");
    printf("1. Yes\n2. No\n");
    printf("> ");
    scanf("%d", &o);
    switch(o)
    {
        case 1:
        {
            //CUSTOM FILE INPUT
            printf("\nPlease Enter a file name: \n");
            printf("> ");
            scanf("%s", filename); //Take Filename
            n = 5000;
            FILE *finp; //File Pointer
            int ctr = 0;
            finp = fopen(filename, "r");
            //IF FILE IS NOT THERE, STOP!
            if(NULL == finp)
            {
                printf("Unable to open file\n");
                exit(-1);
            }
            //CREATING ARRAY FROM TEXT FILE
            while((!feof(finp)) && (ctr < n))
            {
                fscanf(finp, "%d ", &arr[ctr++]);
            }

            printf("File has been loaded...\n");
            fclose(finp); //Close the file pointer
            break;
        }

        case 2:
        {
            //RANDOM ARRAY GENERATOR CODE
            clock_t t;
            srand((unsigned) time(&t));
            for(int i = 0 ; i < n ; i++ ) 
            {
                arr[i] =  rand() % 1000000;
            }
            break;
        }
        default:
            printf("You seem to have mistyped!\n");
            exit(-1);
    }

    //SELECTION MENU FOR SORTING / SEARCHING
    printf("\nPlease Select Algorithm type you wish to compare:\n");
	printf("1. Sorting\n2. Searching\n");
    printf("> ");
	scanf("%d", &i);
	switch(i)
	{
        case 1:
            sorting(arr, n);
            break;
        case 2:
            searching(arr, n);
            break;
        default:
            printf("You seem to have mistyped!\n");
            exit(-1);
	}

return 0;
}

//SEARCHING FUNCTION
int searching(int arr[], int n){

    //Element to search (Middle one in Array)
    int x = arr[rand() % n];

    clock_t begin_linear = clock();
    int lin = linearSearch(arr, n, x);
    clock_t end_linear = clock();
	
    clock_t begin_binary = clock();
    int bin = binarySearch(arr, 0, n-1, x);
    clock_t end_binary = clock();

    double time_spent_linear = (double)(end_linear-begin_linear)/CLOCKS_PER_SEC;
    printf("\nTime Taken by Linear Search: %f \n", time_spent_linear);

    double time_spent_binary = (double)(end_binary-begin_binary)/CLOCKS_PER_SEC;
    printf("Time Taken by Binary Search: %f \n\n", time_spent_binary);

	return 0;
}

//SORTING FUNCTION
int sorting(int arr[], int n){

    printf("\nInitializing...\n");
    printf("Creating random array...\n");

    /* Temporary Array to save Original Array for all Sorting */
    int tmp[n];
    for(int i = 0 ; i < n ; i++ ) 
    {
        tmp[i] = arr[i];
    }
	
    printf("Sorting...\n");
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

    printf("Comparing...\n");
    //Calculation of Execution Times
    double time_spent_merge = (double)(end_merge - begin_merge) / CLOCKS_PER_SEC;
    double time_spent_bubble = (double)(end_bubble - begin_bubble) / CLOCKS_PER_SEC;
    double time_spent_heap = (double)(end_heap - begin_heap) / CLOCKS_PER_SEC;
    double time_spent_insertion = (double)(end_insertion - begin_insertion) / CLOCKS_PER_SEC;
    double time_spent_quick = (double)(end_quick - begin_quick) / CLOCKS_PER_SEC;
    double time_spent_selection = (double)(end_selection - begin_selection) / CLOCKS_PER_SEC;
    double time_spent_shell = (double)(end_shell - begin_shell) / CLOCKS_PER_SEC;
    double time_spent_cocktail = (double)(end_cocktail - begin_cocktail) / CLOCKS_PER_SEC;;
    double time_spent_bucket = (double)(end_bucket - begin_bucket) / CLOCKS_PER_SEC;

    //COMPARISION
    double timecomplexities[9];
    timecomplexities[0] = time_spent_merge;
    timecomplexities[1] = time_spent_bubble;
    timecomplexities[2] = time_spent_heap;
    timecomplexities[3] = time_spent_insertion;
    timecomplexities[4] = time_spent_quick;
    timecomplexities[5] = time_spent_selection;
    timecomplexities[6] = time_spent_shell;
    timecomplexities[7] = time_spent_cocktail;
    timecomplexities[8] = time_spent_bucket;
    comparison(timecomplexities);

    return 0;
}




