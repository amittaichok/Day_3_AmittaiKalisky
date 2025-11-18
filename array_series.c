/*------------------------------------------------------
* Filename: array_series.c
* Description: exercise
* Author: Amittai Kalisky
-------------------------------------------------------*/
#include <stdio.h>
#define SERIES_SIZE 15
#define TRUE 1
#define FALSE 0
/*------------------------------------------------------
* Function Name - main
*
* Function Purpose - get a series and print if its increasing, decreasing, constant or changing.
*
* Parameters –  None.
*
* Return Values - 0 if finished without excpetions, 1 else.
*
* Author - Amittai Kalisky
-------------------------------------------------------*/
int main() {
    int i = 0;
    int series[SERIES_SIZE];
    /*these are boolean variablese. We assume TRUE and will later eliminate.*/
    int is_increasing = TRUE;
    int is_decreasing = TRUE;
    int is_constant = TRUE;
    int diff;

    /*this is a loop to get the series and check it*/
    printf("Please enter an integer for series value number %d: ", i);
    if(scanf("%d", &series[i]) != 1){
        printf("Wrong input!");
        return 1;
    }
    while (i < (SERIES_SIZE-1)){
        i++;
        printf("Please enter an integer for series value number %d: ", i);
        if(scanf("%d", &series[i]) != 1){
            printf("Wrong input!");
            return 1;
        }
        
        diff = series[i] - series[i-1];
        if (diff > 0){
            /*increase between two points*/
            is_decreasing = FALSE;
            is_constant = FALSE;
        }
        else if (diff < 0){
            /*decrease between two points*/
            is_increasing = FALSE;
            is_constant = FALSE;
        }
        else{
            /*constant between two points*/
            is_increasing = FALSE;
            is_decreasing = FALSE;
        }
    }

    if (is_increasing && !is_decreasing && !is_constant){
        printf("The array is increasing");
    }
    else if (is_decreasing && !is_increasing && !is_constant){
        printf("The array is decreasing");
    }
    else if (!is_decreasing && !is_increasing && is_constant){
        printf("The array is constant");
    }
    else{
        printf("The arrray is messed up");
    }

    return 0;
}