/*
 * Filename: pa0.c
 * Author: TODO: Qiao Jia Lu
 * Userid: TODO: cs30xcq
 * Description: Main driver for PA0, will print out an array three times and
 *              calculate the sum of three numbers
 * Date: TODO: 1/13/2018
 * Sources of Help: TODO: Tutors, gdb, lecture paper and discussion paper
 */

#include <stdio.h>
#include <stdlib.h>
#include "pa0.h"

#define FIRST_NUM_TO_SUM 10
#define SECOND_NUM_TO_SUM 12
#define THIRD_NUM_TO_SUM 20

/*
 * Function Name: main()
 * Function Prototype: int main( void );
 * Description: Driver for PA0, creates an array then prints it out forwards,
 *              backwards, and forwards again. Then sums three numbers and
 *              prints out the result
 * Parameters: None
 * Side Effects: Prints out an array to stdout three times as well as the sum of
 *               three numbers
 * Error Conditions: None
 * Return Value: Always returns success
 */ 
int main( void ) {

  int intArray[SIZE];

  // Initialize intArray with even values starting with 0
  initArray( intArray, SIZE );

  // Print the values in the array
  for ( int i = 0; i < SIZE; i++ ) {
    printf( "%d\n", intArray[i] );
  }
  printf( "\n" );

  // Print the values in intArray in reverse order
  printReversed( intArray, SIZE );
  printf( "\n" );

  // Print the values in intArray in order
  printInOrder( intArray, SIZE );
  printf( "\n" );


  // Calculate the sum of v1, v2, v3 and print out the result
  int v1 = FIRST_NUM_TO_SUM;
  int v2 = SECOND_NUM_TO_SUM;
  int v3 = THIRD_NUM_TO_SUM;
  int sum;

  // Use the sum function to generate the sum
  sum = sum3( v1, v2, v3 );

  // Print out the three original numbers and the resulting sum
  printf( "The sum of %d + %d + %d = %d\n", v1, v2, v3, sum );

  return EXIT_SUCCESS;
}
