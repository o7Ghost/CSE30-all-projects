/*
 * Filename: printUsage
 * Author: Qiao Jia Lu
 * Description: 
 * Date: 2/26/18
 * Source of Help: Discussion slude and tutor
 */

@ Raspberry Pi directive
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.equ	FP_OFFSET, 4

	.global	printUsage
	.type 	spawnAnagram, %function

	.text
	.align	2

/* 
 * Function name: printUsage
 * Function Prototype: void printUsage ( FILE * stream, const char * const 
 *                                       usageStr, const char * const 
 *                                       progName );
 * Description: using fprintf to print out messages
 * Paramters: stream - the place that the messsage will be print at
 *            usageStr - the formate to be printed
 *            progName - the string to be printed
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 *
 * Registers used:
 *	r0 - arg 1 -- the place to be printed
 *	r1 - arg 2 -- the format the the string
 *	r2 - arg 3 -- the string to be printed into the formate
 */

printUsage:
@prologue

	push	{ fp, lr }
	add	fp, sp, FP_OFFSET

	bl	fprintf			@call fprintf to print

@epilogue
	sub	sp, fp, FP_OFFSET
	pop	{ fp, pc }
