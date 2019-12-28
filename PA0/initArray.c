/*
 * Filename: initArray.c
 * Author: TODO: Qiao Jia Lu
 * Userid: TODO: csxcq
 * Description: Initialize an array with even numbers starting from 0
 * Date: TODO: 1/13/2018
 * Sources of Help: TODO: gdb, discussion paper, lecture paper, and tutors
 */

// Used for initializing the values in the array
#define EVEN_MULTIPLIER 2

/*
 * Function Name: initArray()
 * Function Prototype: void initArray( int array[], int length );
 * Description: Initializes values in an array to be even integers starting 
 *              from 0
 * Parameters: array - the array to initialize
 *             length - the length of the array
 * Side Effects: Initializes the values of the array
 * Error Conditions: None
 * Return Value: None
 */
void initArray( int array[], int length ) {
  int i = 0;

  while ( i < length ) {
    array[i] = EVEN_MULTIPLIER * i;
    i++;
  }
}
