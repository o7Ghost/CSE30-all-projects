/*
 * Filename: huntForAnagrams.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: ask the user for a word, hunt for anagrams of said word 
 * in the anagramsArray, and then report the results of the hunt.
 * Date: 2/26/18
 * Source of Help: Tutors and Disccusion slids
 */

#include <strings.h>
#include <string.h>
#include "pa3.h"
#include "pa3Strings.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Function name: huntForAnagrams()
 * Function prototype: huntForAnagrams( struct Anagram * anagramsArray,
 *                                      int numAnagrams );
 * Description: ask the user for a word, hunt for anagrams of said word 
 * in the anagramsArray, and then report the results of the hunt.
 * Side Effects: None
 * Error Condition: None
 * Return value: None
 */
void huntForAnagrams( struct Anagram * anagramsArray, int numAnagrams ) {

  //declaration
  struct Anagram tmp;
  char buf[BUFSIZ] = { 0 };
  struct Anagram * bPointer;
  char displayString[BUFSIZ];
  struct Anagram *tmpPointer;

  //prompt the user first
  fprintf(stdout, STR_USER_PROMPT);

  //take in user input
  while (fgets(buf, BUFSIZ, stdin)) {

    //change the newline character to null
    *(strrchr(buf, '\n')) = '\0';

    spawnAnagram(buf, &tmp);
   
    tmpPointer = &tmp;

    //clear the concat string
    displayString[0] = '\0'; 

    //find the key
    bPointer = bsearch(tmpPointer, anagramsArray, numAnagrams,
                        sizeof(struct Anagram), compareKey);  

    //check if key is found
    if ( bPointer == NULL ) {
      fprintf(stdout, STR_NO_ANAGRAMS);
    } 

    //key is found
    else {

      //find head
      while ( compareKey(bPointer, tmpPointer) == 0 ) {

        //check out of bound
        if (bPointer == anagramsArray ) {
          break;
        }

        //decrease pointer
        bPointer = bPointer - 1; 
      }

      if (bPointer != anagramsArray ) {
      //put pointer back
      bPointer = bPointer + 1;
}
      //find the end
      while ( compareKey(bPointer, tmpPointer) == 0 ) {

        //check out of bound
        if (bPointer == anagramsArray + numAnagrams) { 
          break;
        }
        
        //concat if there is same key
        if (strncasecmp(bPointer->word, buf, strlen(buf)) != 0) {
          strncat(displayString, STR_SPACE_CHAR, BUFSIZ);
          strncat(displayString, bPointer->word, BUFSIZ);

        }
        
        //increase pointer
        bPointer = bPointer + 1;
      }
     
      //decrease pointer back to the right one
      bPointer = bPointer - 1;

      //display only the ones that are the same and not the only
      //word in dictionary
      if ( strlen(displayString) != 0 ) {
        fprintf(stdout, STR_FOUND_ANAGRAMS);
        fprintf(stdout, "%s\n", displayString);
      }

      else {  
        fprintf(stdout, STR_NO_ANAGRAMS);
      }
    }

    //repompt
    fprintf(stdout, STR_USER_PROMPT);
  }
  
  //reprint a new line after control D
  fprintf(stdout, "\n");
}
