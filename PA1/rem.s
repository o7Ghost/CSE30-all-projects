/*
 * File name: rem.s
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: calculates the remainder of the divsion
 * between arguments
 * Date: 1/24/18
 * Source of Help: Tutors, discussion and lecture slides
 */

@ Raspberry Pi directives
	.cpu    cortex-a53
	.fpu neon-fp-armv8
	.syntax unified

	.equ FP_OFFSET, 4

	.global rem
	.type rem, %function
 
	.text
	.align 2

/*
 * Function name: rem
 * Function Prototype: long rem( long dividend, long divisor );
 * Description: calculates the remainder of the division between arguments
 * Parameters: dividend - the value to be divided
 *             divisor - the value as divisor
 * side Effects: None
 * Error Conditions: None
 * Return Value: remainder as a 32 bit signed integer
 */

rem: 
@ prologue
	push 	{fp, lr}		@ Save registers: fp, lr
	add 	fp, sp, FP_OFFSET	@ set fp to base of saved registers

	sdiv	r2, r0, r1		@ save the quotient into r2
	mul	r3, r2, r1		@ save product into r3
	sub	r0, r0, r3		@ return the remainder

@ epilogue
	sub 	sp, fp, FP_OFFSET	@ Set sp to top of the saved registers
	pop 	{fp, pc}		@ Restore fp
					@ return
