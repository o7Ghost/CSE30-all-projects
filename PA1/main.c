/*
 * Filename: main.c
 * Author: Qiao jia Lu
 * Userid: cs30xcq
 * Description: check and print error to stderr 
 * if no error print the diamond
 * Date: 1/31/18
 * Source of Help: Tutors and lecture paper
 */

#include <stdio.h>
#include <stdlib.h>
#include "pa1.h"
#include "pa1Strings.h"
#include <string.h>
#include <errno.h>

/* helper function and global variale declaration */
#define MAXARGV 5
#define ARGVTWO 2
#define ARGVTHREE 3
#define ARGVFOUR 4

long checkWidth( char* wArg );
long checkHeight( char* hArg, char* wArg, long cWidth );
int checkBorderChar( char* bArg );
int checkDiamondChar( char* dArg );
/*
 * Function for checking invalid input and display
 * diamond.
 *
 * int main ( int argc, char* argv[]) 
 *          argc - argument counter
 *         argv[] - argument array
 * 
 * Side Effects: None
 * Error Conditions: argc > 5 or agc < 1
 * Return value: returns failure if there is error
 * return succes if it is success
 */
int main ( int argc, char* argv[]) {

 //declaration
 errno = 0;

 //check if argument length is valid
 if ( argc !=  MAXARGV) {
  fprintf(stderr, STR_USAGE, argv[0], WIDTH_MIN, WIDTH_MAX, HEIGHT_MIN, 
          HEIGHT_MAX, ASCII_MIN, ASCII_MAX, ASCII_MIN, ASCII_MAX);

   return EXIT_FAILURE;
 }

 //check width erros
 long cWidth = checkWidth(argv[1]);
 long cHeight = checkHeight(argv[ARGVTWO], argv[1], cWidth);
 int cBoarder = checkBorderChar(argv[ARGVTHREE]);
 int cDiamond = checkDiamondChar(argv[ARGVFOUR]);
 
 //exit if there is an error
 if ( cWidth == -1 || cHeight == -1 || cBoarder == -1 || cDiamond == -1
      || cWidth == -2 ||  cWidth == 1 ) {
  
   fprintf(stderr, "\n");
   return EXIT_FAILURE;
 }

 //check if boader and diamond are the same
 if ( *argv[ARGVTHREE] == *argv[ARGVFOUR]  ) {

   fprintf(stderr, STR_ERR_BORDER_DIAMOND_DIFF, 
           *argv[ARGVTHREE], *argv[ARGVFOUR]);

   fprintf(stderr, "\n");
   return EXIT_FAILURE;
 }

 //display diamond if all error check
 displayDiamond( cWidth, cHeight, *argv[ARGVTHREE], *argv[ARGVFOUR] );

 return EXIT_SUCCESS;
}

/*
 * Function Name: checkWidth
 * Function Protype: checkWidth ( char* wArg );
 * Description : check if there is error for width
 * Paramters: wArg - width of the diamond
 * Side effects: changes errno to 0
 * Error Condition: width is too long, width is not
 * an integer.
 * Return Value: returns 1 if can't convert, returns
 * -1 if is even and not within change. return
 * the long integer if it is no error
 */
long checkWidth( char* wArg ) {

  //local variables
  char *endPtr;
  char errMess[BUFSIZ];
  long failOrSuccess = 0;

  long width = strtol(wArg, &endPtr, BASE);
  //check if you can convert 
  if ( errno != 0 ) {

    snprintf(errMess, BUFSIZ, STR_ERR_CONVERTING, STR_WIDTH, wArg, BASE);
    perror(errMess);
    failOrSuccess = -1;
    errno = 0; 
    return failOrSuccess;
  }

  //check if it is a number
  if ( *endPtr != '\0' ) {
     
    fprintf(stderr, STR_ERR_NOT_INT, STR_WIDTH, wArg);
    failOrSuccess = -1;
    
    return failOrSuccess;
  }

  //check value is in range
  if ( checkRange(width, WIDTH_MIN, WIDTH_MAX) == 0 ) {

    fprintf(stderr, STR_ERR_NUM_RANGE, STR_WIDTH, 
            width, WIDTH_MIN, WIDTH_MAX);
    failOrSuccess = 1;
  }

  //check if it's odd
  if ( isOdd(width) == 0 ) {
    fprintf(stderr, STR_ERR_ODD, STR_WIDTH, width);
    
    failOrSuccess = -2;
  }

  if ( failOrSuccess == 0 ) {
    failOrSuccess = width;
  }

  return failOrSuccess;
}


/*
 * Function Name: checkHeight
 * Function Protype: checkHeight ( char* hArg );
 * Description : check if there is error for height
 * Paramters: hArg - width of the diamond
 * Side effects: changes errno to 0
 * Error Condition: height is too long, height is not
 * an integer.
 * Return Value: returns 1 if can't convert, returns
 * -1 if is even and not within change. return
 * the long integer if it is no error
 */
long checkHeight( char* hArg, char* wArg,  long width ) {

  //local variables
  char *endPtr;
  char errMess[BUFSIZ];
  int failOrSuccess = 0;
   
  long height = strtol(hArg, &endPtr, BASE);
  //check if you can convert 
  if ( errno != 0 ) {
  
    snprintf(errMess, BUFSIZ, STR_ERR_CONVERTING, STR_HEIGHT, hArg, BASE);
    perror(errMess);
    failOrSuccess = -1;
    errno = 0;
    return failOrSuccess;
  }

  //check if it is a number
  if ( *endPtr != '\0' ) {
     
    fprintf(stderr, STR_ERR_NOT_INT, STR_HEIGHT, hArg);
    failOrSuccess = -1;

    return failOrSuccess;
  }

  //check value is in range
  if ( checkRange(height, HEIGHT_MIN, HEIGHT_MAX) == 0 ) {

    fprintf(stderr, STR_ERR_NUM_RANGE, STR_HEIGHT, 
            height, HEIGHT_MIN, HEIGHT_MAX);
    failOrSuccess = -1;
  }

  //check if it's odd
  if ( isOdd(height) == 0 ) {

    fprintf(stderr, STR_ERR_ODD, STR_HEIGHT, height);  
    failOrSuccess = -1;
  }
  
  //check if height is larger than width
  if ( width != -1 && width != 1 ) {
     if ( height >= strtol(wArg, &endPtr, BASE)) {
       fprintf(stderr, STR_ERR_HEIGHT_LESS_THAN_WIDTH, height, 
               strtol(wArg, &endPtr, BASE));
      failOrSuccess = -1;
     }
  }

  if ( failOrSuccess != -1 ) {
    failOrSuccess = height;
  }

  return failOrSuccess;
}

/* Function Name: checkBorderChar
 * Function Prototype: checkBorderChar( char* bArg );
 * Description: check if the border symbol is a valid input
 * Side Effects: None
 * Error Conditions: bArg is more than one character 
 * and if its not in range
 * Return Value: -1 input in invalid
 */
int checkBorderChar( char* bArg ) {

  //local variable
  long stringL = strlen(bArg);
  int failOrSuccess = 0;


  //check for single character
  if (stringL > 1) {

    fprintf(stderr, STR_ERR_SINGLE_CHAR, STR_BORDER_CHAR, bArg);
    failOrSuccess = -1;
    return failOrSuccess;
  }

  //check character is in range
  
  if ( checkRange(*bArg, ASCII_MIN, ASCII_MAX) == 0 ) {

    fprintf(stderr, STR_ERR_ASCII_RANGE, STR_BORDER_CHAR, 
            *bArg, ASCII_MIN, ASCII_MAX);
    failOrSuccess = -1;
  }
  
  return failOrSuccess;
}


/* Function Name: checkDiamondChar
 * Function Prototype: checkDiamondChar( char* dArg );
 * Description: check if the diamond symbol is a valid input
 * Side Effects: None
 * Error Conditions: bArg is more than one character 
 * and if its not in range
 * Return Value: -1 input in invalid
 */
int checkDiamondChar( char* dArg ) {

  //local variable
  long stringL = strlen(dArg);
  int failOrSuccess = 0;

  //check for single character
  if (stringL > 1) {

    fprintf(stderr, STR_ERR_SINGLE_CHAR, STR_DIAMOND_CHAR, dArg);
    failOrSuccess = -1;
    return failOrSuccess;
  }

  //check character is in range
  if ( checkRange(*dArg, ASCII_MIN, ASCII_MAX) == 0 ) {

    fprintf(stderr, STR_ERR_ASCII_RANGE, STR_DIAMOND_CHAR, 
            *dArg, ASCII_MIN, ASCII_MAX);
    failOrSuccess = -1;
  }
  
  return failOrSuccess;
}
