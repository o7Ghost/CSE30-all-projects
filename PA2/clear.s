/*
 * File name: clear.s
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: clear the lights
 * Date: 2/4/18
 * Source of Help: Tutor and Discussion slide
 */

@ Raspberry Pi directive
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.equ	FP_OFFSET,12
	.equ	FP_ELM, 4

	.global	clear
	.type	clear, %function

	.text
	.align	2

/*
 * Function name: clear()
 * Function Prototype: void clear( unsigned int lightBank[], 
 *                               const unsigned int pattern0,
 *                               const unsigned int pattern1 );
 * Description: turn off light according to the pattern
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
 *	r3 - results -- holds the value that turns the lights off
 *      r4 - save light -- saves light bank 1 and 2
 */

clear:
@prologue
	push	{r4, fp, ip, lr}
	add	fp, sp, FP_OFFSET

	ldr	r4, [r0]		@load the array
	and	r3, r4, r1		@and lights with pattern
	eor	r3, r3, r4		@turn off the lights
	str	r3, [r0]		@put it back

	ldr	r4, [r0,FP_ELM]		@load index two		
	and	r3, r4, r2		@and lights with pattern
	eor	r3, r3, r4		@turn off the lights
	str	r3, [r0, FP_ELM]	@put it back

@epliogoue
	sub	sp, fp, FP_OFFSET
	pop	{r4, fp, ip, pc}	
