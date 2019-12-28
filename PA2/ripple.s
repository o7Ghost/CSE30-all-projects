/*
 * Filename: ripple.s
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: rotates the current light pattern in the light banks
 * by rippleCnt
 * Date: 2/10/18
 * Source of Help: Tutors and Discussion slides
 */

@ Raspberry Pi directives
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.equ	FP_OFFSET, 20

	.global	ripple
	.type	ripple, %function
	
	.text
	.align	2

/*
 * Function Name: ripple()
 * Function ProtoType: void ripple( unsigned int lightBank[],
 *                                  const int rippleCnt );
 * Description: rotates the current light pattern in the light banks
 * Parameters: lightBank - the light patterns
 *             rippleCnt - the number of times it should rotate
 *
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 *
 * Registers used:
 *	r0 - arg 1 -- lightBank[]
 *	r1 - arg 2 -- rippleCnt
 *	r4 - local variable -- saves arg1
 *	r5 - counter -- counter for the loop
 *	r6 - store -- sat shifting to negative
 *	r7 - store -- store lightbank so it doesn't get override
 */

ripple:
@ Prologue
	push	{r4-r7, fp, lr}
	add	fp, sp, FP_OFFSET

	mov	r4, r1			@save r1 in r4
	mov	r5, 0			@set counter
	cmp	r4, 0			@check is negative or positive
	blt	neg			@branch to negative
	mov	r6, 1			@set shifting to positive
	b	loop_set		@go into loop

neg:
	mov	r3, -1			@mov -1 to r3
	mul	r4, r4, r3		@make loop counter positive
	mov	r6, -1			@set shifting to negative

loop_set:

	cmp	r5, r4			@compare
	bge	end			@if larger then end

loop:

	mov	r1, r6			@mov shift left or right to r6
	bl	rotate			@call rotate
	mov	r7, r0			@save light bank
	bl	displayLights		@display the lights
	mov	r0, r7			@put light bank back
	add	r5, r5, 1		@increase counter
	cmp	r5, r4			@check to see if loop continues
	blt	loop			@run the loop

end:
	sub	sp, fp, FP_OFFSET
	pop	{r4-r7, fp, pc}	
