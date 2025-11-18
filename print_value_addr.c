/*------------------------------------------------------
* Filename: print_value_addr.c
* Description: exercise
* Author: Amittai Kalisky
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

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
    int nums [SIZE];
    char chars [SIZE];

    /*get nums*/
    printf("Enter %d numbers:\n", SIZE);
    for(int i = 0; i < SIZE; i++){
        if(scanf("%d", &nums[i]) != 1){
            printf("Invalid input!");
            return 1;
        }
    }
    /*get chars*/
    printf("Enter %d chars:\n", SIZE);
    for(int i = 0; i < SIZE; i++){
        if(scanf(" %c", &chars[i]) != 1){
            printf("Invalid input!");
            return 1;
        }
    }

    for(int i = 0; i < SIZE; i++){
        printf("%d %d %x \n", nums[i], *(nums + i), (nums + i));
    }

    for(int i = 0; i < SIZE; i++){
        printf("%c %c %x \n", chars[i], *(chars + i), (chars + i));
    }
    printf("\n");

    return 0;
}