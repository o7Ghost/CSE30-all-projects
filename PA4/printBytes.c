/*
 * Filename: printBytes.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: This Function will be responsiable for reading data
 * from file pointer and will output the bytes from the file according to the 
 * specified OutType
 * Date: 2/11/2018
 */

#include "pa4.h"
#include "pa4Strings.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
 * Function name: printBytes()
 * Function prototype: void printBytes( File *fp, OutType type, long endAddr
 *                                 int convertFlag );
 * Description: This Function will be responsiable for reading data from file
 * pointer and will output the bytes from the file according to the specified
 * OutType
 * Paramters: fp - the file to read from
 *            type - the type should be converted and printed
 *            endAddr - should read up to
 *            convertFlag - convert if endiness is not the same
 * Side Effects: None
 * Error Conditions: Memory allocation fail
 * Return Value: None
 */
void printBytes( FILE *fp, OutType type, long endAddr, int convertFlag ) {
  //declaration
  long totalBytesRead = endAddr - ftell(fp);
  long byteTracker = 0;
  unsigned char buf[BYTE_BUFFER_SIZE];
  char addressformat[BUFSIZ];
  char charformat[BUFSIZ];
  long byteRead = 0; 

  //format address
  if (type == HEX || type == ASCII ) {
    strncpy(addressformat, STR_OFFSET_HEX, BUFSIZ);
  }

  if ( type == OCTAL ) {
    strncpy(addressformat, STR_OFFSET_OCT, BUFSIZ); 
  }

  //format print
  if ( type == OCTAL ) {
    strncpy(charformat, STR_OCTAL_FMT, BUFSIZ);
  }

  if ( type == HEX ) {
    strncpy(charformat, STR_HEX_FMT, BUFSIZ);
  }

  if ( type == ASCII ) {
   strncpy(charformat, STR_ASCII_FMT, BUFSIZ);
  }

  for (long i = 0; i < totalBytesRead; i += BYTE_BUFFER_SIZE ) {

    //print line address
    if ( i == 0 ) {
      fprintf(stdout, addressformat, ftell(fp));
    }

    //print address every 16 bytes
    if ( i != 0 && i % BYTES_PER_LINE == 0 ) {
      fprintf(stdout, "\n");
      fprintf(stdout, addressformat, ftell(fp));
    }

    //read bytes and count howmany is read
    byteRead = fread(buf, sizeof(*buf), BYTE_BUFFER_SIZE, fp);
    byteTracker += BYTE_BUFFER_SIZE;
 
    //check if there is remainer
    if (byteTracker > totalBytesRead) {
      
      byteRead = byteTracker - totalBytesRead;
      byteRead = BYTE_BUFFER_SIZE - byteRead;

      if ( convertFlag != 0 ) {
        int pad;
        int numZero = BYTE_BUFFER_SIZE - byteRead;

        for ( pad = 0; pad < numZero; pad++) {
          buf[byteRead + pad] = 0;     
        }
        byteRead += pad;
      }
    }

    //check if it is less than three
    if (totalBytesRead < BYTE_BUFFER_SIZE) {

      byteRead = totalBytesRead; 

      if ( convertFlag != 0 ) {
        int pad;
        int numZero = BYTE_BUFFER_SIZE - byteRead;
        for ( pad = 0; pad < numZero; pad++) {
          buf[byteRead + pad] = 0;
        }
         byteRead += pad;
      } 
    }

    //check if needed to be converted
    if ( convertFlag != 0 ) {
      convertOrder(buf);
    }

    //loop and print the bytes
    for (int j = 0; j < byteRead; j++ ) {

      if ( type == ASCII ) {

        //check if it is ASCII type
        if ( isprint(buf[j]) != 0) {
          fprintf(stdout, charformat, buf[j]);
        }

        else {
          fprintf(stdout, STR_HEX_FMT, buf[j]);
        }
      }

      else {
        fprintf(stdout, charformat, buf[j]);
      }

      if ( (j + 1) % GROUP_SIZE == 0 ) {
        fprintf(stdout, STR_SPACE);
      }
    }
  }

  fprintf(stdout, "\n");
}
