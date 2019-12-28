 /*
 * Filename: isOdd.s
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: check if value is an odd number , using rem() function
 * Date: 1/24/18
 * Sources of Help: Tutor, discussion and lecture slides 
 *
 */

@ Raspberry Pi directives
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax unified

	.equ 	FP_OFFSET, 4
	.equ 	denominator, 2

	.global	isOdd
	.type	isOdd, %function

	.text
	.align 2

/*
 * Function Name: isOdd
 * Function Prototype: long isOdd( long value );
 * Description: check if value is an odd number , using rem() function
 * Parameters: value - the value to check if odd or even
 * Side Effects: None
 * Error Conditions: None
 * Return Value: 0 if the value is not odd, non-0 if the value is odd
 */

isOdd:
@ prologue
	push 	{fp, lr}		@ Save registers: fp, lr
	add	fp, sp, FP_OFFSET	@ Set fp to base of save registers

	mov	r0, r0			@ put numerator in r0
	mov	r1, denominator		@ put denominator in r1
	bl	rem			@ call remainder function

@ epilogue
	sub sp, fp, FP_OFFSET		@ Set sp to top of saved registers
	pop {fp, pc}			@ Restore fp
					@ return



