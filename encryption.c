/*------------------------------------------------------
* Filename: encryption.c
* Description: exercise
* Author: Amittai Kalisky
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#define MESSAGE_SIZE 26
char * decrypt(int encryption[MESSAGE_SIZE]);

/*------------------------------------------------------
* Function Name - decrypt 
*
* Function Purpose - decrypt a message by instructions

* Parameters –  (int [MESSAGE_SIZE]) the encrypted message
*
* Return Values - (char [MESSAGE_SIZE]) the decrypted message
*
* Author - Amittai Kalisky
-------------------------------------------------------*/
char * decrypt(int encryption[MESSAGE_SIZE]){
    int * helper [MESSAGE_SIZE];
    char * decryption = malloc(MESSAGE_SIZE * sizeof(char));

    printf("debug 1\n"); /*debug*/
    /*step 7*/
    for(int i = MESSAGE_SIZE / 2; i < MESSAGE_SIZE; i++){
        helper[i-(MESSAGE_SIZE / 2)] = encryption[i];
    }
    for(int i = 0; i < MESSAGE_SIZE / 2; i++){
        helper[i+(MESSAGE_SIZE / 2)] = encryption[i];
    }
    printf("debug 2\n"); /*debug*/

    for (int i = 0; i < MESSAGE_SIZE; i++) {
        encryption[i] = helper[i];
    }

    printf("debug 3\n"); /*debug*/

    /*step 6*/
    for(int i = MESSAGE_SIZE - 1; i > 0; i--){
        encryption[i] -= helper[i-1];
    }
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        helper[i] = encryption[i];
    }
    printf("debug 4\n"); /*debug*/

    /*step 5*/
    for(int i = 0; i < MESSAGE_SIZE; i++){
        encryption[i] = helper[(i+5) % MESSAGE_SIZE];
    }
    helper = encryption;
    printf("debug 5\n"); /*debug*/

    /*step 4*/
    for(int i = 0; i < MESSAGE_SIZE; i++){
        if(i % 2 == 0){
            encryption[i] /= 2;
        }
    }
    printf("debug 6\n"); /*debug*/

    for (int i = 0; i < MESSAGE_SIZE; i++) {
        helper[i] = encryption[i];
    }
    /*step 3*/
    for(int i = 0; i < MESSAGE_SIZE; i++){
        encryption[i] = helper[(MESSAGE_SIZE+i-4) % MESSAGE_SIZE];
    }
    printf("debug 7\n"); /*debug*/

    for (int i = 0; i < MESSAGE_SIZE; i++) {
        helper[i] = encryption[i];
    }
    /*step 2*/
    for(int i = 0; i < MESSAGE_SIZE; i++){
        encryption[i] -= 5;
    }
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        helper[i] = encryption[i];
    }    
    printf("debug 8\n"); /*debug*/

    /*step 1*/
    for(int i = 0; i < MESSAGE_SIZE; i++){
        decryption[i] = (char) encryption[i];
    }
    printf("debug 9\n"); /*debug*/

    return decryption;
}
/*------------------------------------------------------
* Function Name - main
*
* Function Purpose - decrypt a message,
*
* Parameters –  None.
*
* Return Values - 0 if finished without excpetions, 1 else.
*
* Author - Amittai Kalisky
-------------------------------------------------------*/
int main() {
    int message[MESSAGE_SIZE];
    char * decrypted_message;

    /*get encryption from user*/
    for(int i = 0; i < MESSAGE_SIZE; i++){
        printf("Enter the %d part of the encrypted message: ", (i+1));
        if(scanf("%d", &message[i]) != 1){
            printf("Wrong input!");
            return 1;
        }
    }

    decrypted_message = decrypt(message);

    for(int i = 0; i < MESSAGE_SIZE; i++){
        printf("%c", decrypted_message[i]);
    }

    free(decrypted_message);
    return 0;
}