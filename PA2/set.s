/*
 * File name: set.s
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: set the lights
 * Date: 2/4/18
 * Source of Help: Tutor and Discussion sludes
 */

@ Raspberry Pi directive
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.equ	FP_OFFSET,4

	.global	set
	.type	set, %function

	.text
	.align	2

/*
 * Function name: set()
 * Function Prototype: void set( unsigned int lightBank[], 
 *                               const unsigned int pattern0,
 *                               const unsigned int pattern1 );
 * Description: set the lights according to pattern
 * Parameters: lightBank[] - the 64bit lights
 *             pattern0 - the pattern to be assign
 *             pattern1 - the pattern to be assign
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 *
 * Registers used:
 * 	r0 - arg 1 -- lightBank[]
 *	r1 - arg 2 -- pattern 0
 *	r2 - arg 3 -- pattern 1
 *	r3 - save light bank - holds light bank 1 and 2
 */

set:
@prologue
	push	{fp, lr}
	add	fp, sp, FP_OFFSET

	ldr	r3, [r0]		@load the array
	orr	r3, r3, r1		@add the lights using or
	str	r3, [r0]		@put it in the index 0

	ldr	r3, [r0,FP_OFFSET]	@load index two
	orr	r3, r3, r2		@add lights
	str	r3, [r0, FP_OFFSET]	@put it index two

@epilogue
	sub	sp, fp, FP_OFFSET
	pop	{fp,pc}

