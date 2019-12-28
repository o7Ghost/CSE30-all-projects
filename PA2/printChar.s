/*
 * File name: printChar
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: prints one char
 * Date: 1/31/2018
 * Source of Help: Write up
 */

@ Raspberry Pi directives
	.cpu	cortex-a53
 	.fpu	neon-fp-armv8
  	.syntax	unified

   	.section	.rodata

	.equ FP_OFFSET, 4

fmt: 	.asciz	"%c"

	.global	printChar
	.type	printChar, %function

	.text
	.align 2

/*
 * Function name: printChar
 * Function Prototype: void printChar( char ch );
 * Description: print one character
 * Paramters: ch - the char that will be printed
 * side Effects: None
 * Error Conditions: None
 * Return Value: None
 * 
 * Register used:
 * 	r0 - arg 1 - the character to be printed
 */

printChar:
	push 	{fp, lr} 		@ Saves registers on the stack.
	add 	fp, sp, 4 		@ Adjusts fp to be at bottom of 
					@ current stack.

	mov 	r1, r0			@ Copy of formal parameter 
					@ to the second arg of printf.
	ldr 	r0, =fmt		@ Gets address of format string.
	bl 	printf			@ Calls printf.

	sub 	sp, fp, 4
	pop 	{fp, pc}		@ Returns from function.

