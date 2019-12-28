/*
 * Filename: sum3.s
 * Author: TODO: Qiao Jia Lu
 * Userid: TODO: cs30xcq
 * Description: Sum three numbers and return the result
 * Date: TODO: 1/13/2018
 * Sources of Help: TODO: tutors, gdb
 * discussion session and gdb
 *      
 */

@ Raspberry Pi directives
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.equ	FP_OFFSET, 4

	.global	sum3
	.type	sum3, %function

	.text
	.align 2

/*
 * Function Name: sum3()
 * Function Prototype: int sum3( int a, int b, int c );
 * Description: Returns the sum of the three input values
 * Parameters: a - the first value to sum
 *             b - the second value to sum
 *             c - the third value to sum
 * Side Effects: None
 * Error Conditions: None
 * Return Value: the sum of the three input values
 *
 * Registers used:
 *     r0 - arg 1 -- a
 *     r1 - arg 2 -- b
 *     r2 - arg 3 -- c
 *     r3 - result -- holds the sum of a, b, and c 
 */
sum3:
@ Standard prologue
	push	{fp, lr}		@ Save registers: fp, lr
	add	fp, sp, FP_OFFSET	@ Set fp to base of saved registers

	@ Incoming parameters in r0, r1, r2
	add	r3, r0, r1		@ Add param1 and param2; result into r3
	add	r3, r3, r2		@ Add previous result with param3;
					@   result into r3

	mov	r0, r3			@ Put return value in r0

@ Standard epilogue
	sub	sp, fp, FP_OFFSET	@ Set sp to top of saved registers
	pop	{fp, pc}		@ Restore fp; restore lr into pc for
					@   return

