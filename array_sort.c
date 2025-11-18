/*------------------------------------------------------
* Filename: array_sort.c
* Description: exercise
* Author: Amittai Kalisky
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
void print_pointers(int * pointers [SIZE]);
void swap(int *p1, int*p2);
void sort(int * pointers [SIZE]);

/**/
void sort(int * pointers [SIZE]){
    int *min; /*the pointer who points to the lowest number*/ 
    for(int i = 0; i < SIZE; i++){
        min = pointers[i];
        for(int j = i; j < SIZE; j++){
            if (*pointers[j] < *min){
                min = pointers[j];
            }
        }
        swap_places(min, pointers[i]);
    }
}


void swap_places(int * pointers[SIZE], int *p1, int *p2){
    int
}
/*------------------------------------------------------
* Function Name - swap
*
* Function Purpose - swaps values of two pointers
*
* Parameters –  two pointers p1, p2
*
* Return Values - void
*
* Author - Amittai Kalisky
-------------------------------------------------------*/
void swap(int *p1, int *p2){
    int helper = *p1;
    *p1 = *p2;
    *p2 = *p1;
}

/*------------------------------------------------------
* Function Name - print_pointers 
*
* Function Purpose - prints pointers location and value 
*
* Parameters –  list of pointers
*
* Return Values - void
*
* Author - Amittai Kalisky
-------------------------------------------------------*/
void print_pointers(int * pointers [SIZE]){
    printf("\n");
    for(int i =  0; i < SIZE; i++){
        printf("pointer %d points to number %d and holds the value of %x.\n", i, *pointers[i], pointers[i]);
    }
    printf("\n");
}
/*------------------------------------------------------
* Function Name - main
*
* Function Purpose - exercise
*
* Parameters –  None.
*
* Return Values - 0 if finished without excpetions, 1 else.
*
* Author - Amittai Kalisky
-------------------------------------------------------*/
int main() {
    int numbers [SIZE];
    int * pointers [SIZE];

    /*point the pointers to the array*/
    for(int i = 0; i< SIZE; i++){
        pointers[i] = &numbers[i];
    }

    /*get numbers to the array*/
    printf("please enter %d numbers:\n", SIZE);
    for(int i = 0 ; i< SIZE; i++){
        if(scanf("%d", &numbers[i]) != 1){
            printf("Wrong input!");
            return 1;
        }
    }

    print_pointers(pointers);




    print_pointers(pointers);

    return 0;
}