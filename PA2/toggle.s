/*
 * File name: toggle.s
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: toggle the lights
 * Date: 2/4/18
 * Source of Help: Tutor and Discussion slide
 */

@ Raspberry Pi directive
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.equ	FP_OFFSET,4

	.global	toggle
	.type	toggle, %function

	.text
	.align	2

/*
 * Function name: toggle
 * Function Prototype: void toggle( unsigned int lightBank[], 
 *                               const unsigned int pattern0,
 *                               const unsigned int pattern1 );
 * Description: toggle the lights in the light bank
 * Parameters: lightBank[] - the 64bit lights
 *             pattern0 - the pattern to be assign
 *             pattern1 - the pattern to be assign
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 *
 * Registers used:
 * 	r0 - arg 1 -- lightbank[]
 *	r1 - arg 2 -- pattern0
 *	r2 - arg 3 -- pattern1
 *	r3 - results -- holds the calculated toggle pattern
 */

toggle:
@prologue
	push	{fp, lr}
	add	fp, sp, FP_OFFSET

	ldr	r3, [r0]		@load the array
	eor	r3, r3, r1		@add the lights using or
	str	r3, [r0]		@put it in the index 0

	ldr	r3, [r0,FP_OFFSET]	@load index two
	eor	r3, r3, r2		@add lights
	str	r3, [r0, FP_OFFSET]	@put it index two

@epilogue
	sub	sp, fp, FP_OFFSET
	pop	{fp, pc}
