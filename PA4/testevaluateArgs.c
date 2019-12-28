/*
 * Filename: testevaluateArgs.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: Unit test program to test the function evaluateArgs().
 * Date: 3/4/2018
 * Sources of Help: Tutors and Discussion slides
 */ 
#include <string.h>
#include <getopt.h>
#include "test.h"
#include "pa4.h"

/*
 * Unit Test for evaluateArgs.c
 *
 * int evaluateArgs(int argc, char * argv[], char ** infile, char ** outfile, 
 *                  char ** rangeStr, OutType * type, int * convert)
 *
 * Test after function returns if the file strings are correct
 * also test if the user has enter correct amount of flags
 */
void testevaluateArgs() {
  
  extern int optind;

  /* generate our own argv for testing */
  char * argv1[3];
  argv1[0] = "myxd";
  argv1[1] = "-o";
  argv1[2] = "infile";
  int argc = 3;

  /* variables to hold return values */
  char * infile;
  char * outfile;
  char * rangeStr;
  OutType type;
  int convert;

  /* call evaluateArgs and save the return value */
  int result = evaluateArgs(argc, argv1, &infile, &outfile,
                            &rangeStr, &type, &convert);

  /* check the return value */
  TEST( result == 0 );
  /* check that infile was set properly */
  TEST( strncmp(infile, "infile", strlen("infile")) == 0 );
  /* check that type was set properly */
  TEST( type == OCTAL );

  /* now, reset the value of optind before the next call to evaluateArgs */
  /* read the man page for getopt_long to understand why we need this */
  optind = 1;

  /* generate new values of argv for error example */
  char * argv2[4];
  argv2[0] = "myxd";
  argv2[1] = "-c";
  argv2[2] = "infile";
  argv2[3] = "extrafile";
  argc = 4;

  result = evaluateArgs(argc, argv2, &infile, &outfile,
                        &rangeStr, &type, &convert);

  /* check that the return value is correct */
  TEST( result == -1 );

  optind = 1;
  /* ****IMPORTANT***** 
   * YOU NEED TO CHECK THE OUTPUT TO TERMINAL TO ENSURE THE CORRECT ERROR
   * MESSAGE WAS PRINTED
   */

  char * argv3[4];
  argv3[0] = "myxd";
  argv3[1] = "-c";
  argv3[2] = "-x";
  argv3[3] = "file";
  argc = 4;

  result = evaluateArgs(argc, argv3, &infile, &outfile,
                        &rangeStr, &type, &convert);

  TEST( result == -1 );

  /* now, reset the value of optind before the next call to evaluateArgs */
  optind = 1;

  char * argv4[4];
  argv4[0] = "myxd";
  argv4[1] = "-b";
  argv4[2] = "-l";
  argv4[3] = "file";
  argc = 4;

  result = evaluateArgs(argc, argv4, &infile, &outfile,
                        &rangeStr, &type, &convert);

  TEST( result == -1 );

  /* now, reset the value of optind before the next call to evaluateArgs */
  optind = 1;

  char * argv5[6];
  argv5[0] = "myxd";
  argv5[1] = "-b";
  argv5[2] = "-l";
  argv5[3] = "-x";
  argv5[4] = "-c";
  argv5[5] = "file";
  argc = 6;

  result = evaluateArgs(argc, argv5, &infile, &outfile,
                        &rangeStr, &type, &convert);

  TEST( result == -1 );

  /* now, reset the value of optind before the next call to evaluateArgs */
  optind = 1;

  char * argv6[4];
  argv6[0] = "myxd";
  argv6[1] = "-x";
  argv6[2] = "infile";
  argv6[3] = "-r";
  argc = 4;

  result = evaluateArgs(argc, argv6, &infile, &outfile,
                        &rangeStr, &type, &convert);

  TEST( strncmp(infile, "infile", strlen("infile")) == 0 );
  TEST( result == -1 );
  optind = 1;

  char * argv7[3];
  argv7[0] = "myxd";
  argv7[1] = "-b";
  argv7[2] = "infile";
  argc = 3;

  result = evaluateArgs(argc, argv7, &infile, &outfile,
                        &rangeStr, &type, &convert);

  TEST( result == 0 );
  TEST( convert == 1 );
  optind = 1;

  char * argv8[3];
  int convertlittle;
  argv8[0] = "myxd";
  argv8[1] = "-l";
  argv8[2] = "infile";
  argc = 3;

  result = evaluateArgs(argc, argv8, &infile, &outfile,
                        &rangeStr, &type, &convertlittle);

  TEST( result == 0 );
  TEST( convertlittle == 0 );
  optind = 1;

  char * argv9[3];
  argv9[0] = "myxd";
  argv9[1] = "infile";
  argv9[2] = "-o";
  argc = 3;

  result = evaluateArgs(argc, argv9, &infile, &outfile,
                        &rangeStr, &type, &convert);

  TEST( result == 0 );
  TEST( strncmp(infile, "infile", strlen("infile")) == 0 );
  TEST( type == OCTAL );

  optind = 1;

  char * argv10[3]; 
  argv10[0] = "myxd";
  argv10[1] = "-x";
  argv10[2] = "infile";
  argc = 3;

  /* call evaluateArgs and save the return value */
  result = evaluateArgs(argc, argv10, &infile, &outfile,
                            &rangeStr, &type, &convert);

  /* check the return value */
  TEST( result == 0 );
  /* check that infile was set properly */
  TEST( strncmp(infile, "infile", strlen("infile")) == 0 );
  /* check that type was set properly */
  TEST( type == HEX );

  optind = 1;

  char * argv11[3]; 
  argv11[0] = "myxd";
  argv11[1] = "-s";
  argv11[2] = "infile";
  argc = 3;

  /* call evaluateArgs and save the return value */
  result = evaluateArgs(argc, argv11, &infile, &outfile,
                            &rangeStr, &type, &convert);

  /* check the return value */
  TEST( result == 0 );
  /* check that infile was set properly */
  TEST( strncmp(infile, "infile", strlen("infile")) == 0 );
  /* check that type was set properly */
  TEST( type == STRING );

  optind = 1;

  char * argv12[3]; 
  argv12[0] = "myxd";
  argv12[1] = "-c";
  argv12[2] = "infile";
  argc = 3;

  /* call evaluateArgs and save the return value */
  result = evaluateArgs(argc, argv12, &infile, &outfile,
                            &rangeStr, &type, &convert);

  /* check the return value */
  TEST( result == 0 );
  /* check that infile was set properly */
  TEST( strncmp(infile, "infile", strlen("infile")) == 0 );
  /* check that type was set properly */
  TEST( type == ASCII );

  optind = 1;
  char * argv13[2]; 
  argv13[0] = "myxd";
  argv13[1] = "-h";
  argc = 2;

  /* call evaluateArgs and save the return value */
  result = evaluateArgs(argc, argv13, &infile, &outfile,
                            &rangeStr, &type, &convert);
  TEST ( result == 1 );

  optind = 1;
  char * argv14[3]; 
  argv14[0] = "myxd";
  argv14[1] = "-u";
  argv14[2] = "infile";
  argc = 3;

  /* call evaluateArgs and save the return value */
  result = evaluateArgs(argc, argv14, &infile, &outfile,
                            &rangeStr, &type, &convert);

  TEST ( result == -1 ); 
  TEST( strncmp(outfile, "infile", strlen("infile")) == 0 );


  optind = 1;
  char * argv15[3]; 
  argv15[0] = "myxd";
  argv15[1] = "-r";
  argv15[2] = "0:1";
  argc = 3;

  /* call evaluateArgs and save the return value */
  result = evaluateArgs(argc, argv15, &infile, &outfile,
                            &rangeStr, &type, &convert);

  TEST ( result == -1 ); 
  TEST( strncmp(rangeStr, "0:1", strlen("0:1")) == 0 );
}

int main() {
  printf("Running tests on evaluateArgs()\n");
  testevaluateArgs();
  printf("Finished running tests on evaluateArgs()\n");
  return 0;
}
