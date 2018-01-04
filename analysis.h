#include <string.h>
struct node{
  double time;
  char index[50];
}ar[9];

void bsortDesc(struct node ar[9], int s);
int comparison(double t[])
{
    int i,j;
    double temp;
    char temp1[50];

    ar[0].time = t[0];
    ar[1].time = t[1];
    ar[2].time = t[2];
    ar[3].time = t[3];
    ar[4].time = t[4];
    ar[5].time = t[5];
    ar[6].time = t[6];
    ar[7].time = t[7];
    ar[8].time = t[8];

    strcpy(ar[0].index, "Merge Sort");
    strcpy(ar[1].index, "Bubble Sort");
    strcpy(ar[2].index, "Heap Sort");
    strcpy(ar[3].index, "Insertion Sort");
    strcpy(ar[4].index, "Quick Sort");
    strcpy(ar[5].index, "Selection Sort");
    strcpy(ar[6].index, "Shell Sort");
    strcpy(ar[7].index, "Cocktail Sort");
    strcpy(ar[8].index, "Bucket Sort");

    int n = sizeof(ar)/sizeof(ar[0]);
    bsortDesc(ar, n);
    return 0;
}


void bsortDesc(struct node ar[9], int s)
{
    int i, j;
    struct node temp;
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (ar[j].time < ar[j + 1].time)
            {
                temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            } 
        }
    }
    printf("\nSorting Name \t Time Complexities\n");
    printf("------------ \t -----------------\n");

    for(int i = 0; i<9; i++){
        printf("%s \t %lf\n",ar[i].index, ar[i].time);
    }
    printf("\nSorting Algorithm with least Execution Time is %s which took %f ms.\n\n", ar[8].index, ar[8].time);

}


