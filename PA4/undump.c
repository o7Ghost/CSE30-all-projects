/*
 * Filename: undump.c
 * Author: Qiao Jia Lu
 * Description: This function is responsible for taking a previously created 
 * hex dump from our program and converting it back into the original 
 * file format.
 * Date: 3/12/2018
 * Source of Dicussion: Tutors and Discussion slides
 */

#include <stdio.h>
#include "pa4.h"
#include "pa4Strings.h"
/*
 * Function name: undump()
 * Function prototype: void undump ( FILE * infile, 
 *                                   FIle outfile, int convertFlag );
 * Description: This function is respondsible for taking a previously created
 * hex dump from out program and converting it back to the original file
 * file format.
 * paramters: infile - the file to be convert
 *            outfile - the file to be output
 *            convertFlag - if it needs to be converted
 * Side Effects: None
 * Error Condition: None
 * Return Value: None
 */
void undump ( FILE * infile, FILE * outfile, int convertFlag ) {
  //declaration
  int readAddress = 0;
  int bufIndexTwo = 2;
  int bufIndexThree = 3;
  int readSuccess1 = 0;
  int readSuccess2 = 0;
  int totalRead = 0;
  unsigned char buf[BYTE_BUFFER_SIZE];
  int numToPrint = 0;

  //loop through the whole file
  while (1) {
    //if the start of the file then skip the address
    if ( totalRead % BYTES_PER_LINE == 0 ) {
      readAddress = fscanf(infile, STR_SCANF_OFF);
    }

    //check if the address read in is end of file
    if ( readAddress < 0 ) {
      break;
    }
  
    //scan two bytes and increase the total amount read
    readSuccess1 = fscanf(infile, STR_SCANF, &buf[0], &buf[1]);
    totalRead += readSuccess1;

    if ( readSuccess1 <= 0 ) {
      break;
    }

    //scan two bytes and increase the total amount read
    readSuccess2 = fscanf(infile, STR_SCANF, &buf[bufIndexTwo], 
                          &buf[bufIndexThree]);
    totalRead += readSuccess2;

    //check if the second two bytes read in is end of file
    if ( readSuccess2 <= 0 ) {
      break;
    }

    //convert it
    if ( convertFlag != 0 ) {
      convertOrder(buf);
    }
   
    //check how many needs to be printed
    numToPrint = readSuccess1 + readSuccess2;

    //print the characters
    fwrite(buf, sizeof(char), numToPrint, outfile);
  }
}
