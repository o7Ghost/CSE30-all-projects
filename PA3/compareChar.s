/*
 * File name: compareChar.s
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: check char in reverse order
 * Date: 2/17/18
 * Source of Help: Tutors and discussion slides
 */

@ Raspberry Pi directive
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.equ	FP_OFFSET, 4
	
	.global compareChar
	.type	compareChar, %function

	.text
	.align	2

/*
 * Function name: compareChar
 * Function Prototype: int compareChar ( const void * p1, const void * p2 );
 * Description compare char in reverse order
 * Paramters: p1 - the pointer to the first char
 *            p2 - the pointer to the second char
 * Side Effects: None
 * Error Conditions: None
 * Return Value: -1 if the char that p1 points to should be ordered earlier 
 * than the char that p2 points to, +1 if the char that p1 points to should 
 * be ordered later than the char that p2 points to, 0 if the two char pointers 
 * point to the same char.
 * 
 * Registers used:
 * 	r0 - arg1 -- p1
 *	r1 - arg2 -- p2
 *	r2 - store -- saves the value in p1
 */

compareChar:
@prologue

	push	{fp ,lr}
	add	fp, sp, FP_OFFSET

	mov	r2, 1			@check one character
	
	bl	strncmp			@compare character
	cmp	r0, 0			@check return value
	bne	else_if			@go to else if 

if:
	mov	r0, 0			@return zero
	b	end

else_if:

	blt	else			@go to else
	mov	r0, -1			@return -1
	b	end
	
else:

	mov	r0, 1			@return 1

@epilogue
end:

	sub	sp, fp, FP_OFFSET
	pop	{fp ,pc}	
