/*
 * Filename: printInOrder.c
 * Author: TODO: Qiao Jia Lu
 * Userid: TODO: cs30xcq
 * Description: Print out an array in order
 * Date: TODO: 1/13/2018 
 * Sources of Help: TODO: gdb, Tutors, lecutre paper, and
 * Discussion paper
 */

#include <stdio.h>

/*
 * Function Name: printInOrder()
 * Function Prototype: void printInOrder( int array[], int length );
 * Description: Prints out an array in order
 * Parameters: array - the array to print
 *             length - the length of the array
 * Side Effects: Prints out the array to stdout
 * Error Conditions: None
 * Return Value: None
 */
void printInOrder( int array[], int length ) {
  int k;

  // Print all of the values in array
  for ( k = 0; k < length; k++ ) {
    fprintf( stdout, "%d\n", array[k] );
  }
}
