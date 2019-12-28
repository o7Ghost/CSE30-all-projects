/*
 * Filename: printReversed.c
 * Author: TODO: Qiao Jia Lu
 * Userid: TODO: cs30xcq
 * Description: Print out an array in reverse order
 * Date: TODO: 1/13/2018 
 * Sources of Help: TODO: gdb, tutors, Dicussion paper, and lecture paper
 *                  
 */

#include <stdio.h>

/*
 * Function Name: printReversed()
 * Function Prototype: void printReversed( int array[], int length );
 * Description: Prints out an array in reverse order
 * Parameters: array - the array to print
 *             length - the length of the array
 * Side Effects: Prints out the array in reverse order to stdout
 * Error Conditions: None
 * Return Value: None
 */
void printReversed( int array[], int length ) {
  for ( int j = length - 1; j >= 0; j--) {
    printf( "%d\n", array[j] );
  }
}

