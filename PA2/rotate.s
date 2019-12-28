/*
 * File name: rotate.s
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: rotate the lights around
 * Date: 2/5/18
 * Source of Help: Tutors and discussion slides
 */

 @ Raspberry Pi directive
 	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.equ	FP_ELM, 4
	.equ	FP_OFFSET, 24
	.equ	MASK, 0x3F
	.equ	SHIFTL, 31
	.equ	SHIFTR, 31

	.global	rotate
	.type	rotate, %function

	.text
	.align	2

/*
 * Function name: rotate
 * Function Prototype: void rotate( unsign int lightBank[]
 *                                 , const int rotateCnt );
 * Description: roates the lights right or left 
 * Paramters: lightBank[] - 64 bit lights
 *            shiftCnt - the amount lights to be shift
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 *
 * Registers used:
 *	r0 - arg 1 -- lightBank[]
 *	r1 - arg 2 -- rotateCnt
 *	r2 - store -- saves lightBank 0
 *	r3 - store -- saves lightBank 1
 *	r4 - store -- store the last 6 bits 
 *	r5 - counter -- counter for the loop
 *	r6 - store -- saves the most or least significant bit for lightBank 0
 *	r7 - store -- saves the most or least significant bit for lightBank 1
 *	
 */

rotate:
@prologue

	push	{r4-r7, fp, ip, lr}
	add	fp, sp, FP_OFFSET

@variable inilization

	ldr	r2, [r0]		@load first 32 lights
	ldr	r3, [r0, FP_ELM]	@load second 32 lights
	
@if for shift right

	cmp	r1, 0			@check is positive
	blt	else			@else
	and	r4, r1, MASK		@get last 6 bits

@initialize loop

	mov	r5, 0			@set counter
	cmp	r5, r4			@set loop end
	bge	end			@end loop

loop1:

	lsl	r6, r2, SHIFTL		@save most significant r2
	lsl	r7, r3, SHIFTL		@save most significant r3
	lsr	r2, r2, 1		@shift r 1
	lsr	r3, r3, 1		@shift r 1
	orr	r2, r2, r7		@put the saved bit in array[0]
	orr	r3, r3, r6		@put the saved bit in array[1]
	add	r5, r5, 1		@increase counter
	cmp	r5, r4			@check counter
	blt	loop1			@go in loop again

put1:

	str	r2, [r0]		@put in register
	str	r3, [r0, FP_ELM]	@put in register
	b	end			@end program

@shitf left for negative

else:

	mov	r4, r1			@save shift count
	mov	r1, -1			@put -1 into r1
	mul	r4, r4, r1 		@turn shift count to pos
	and	r4, r4, MASK		@save last 6 bits

@initialize loop

	mov	r5, 0			@set counter
	cmp	r5, r4			@set loop end
	bge	end			@end loop

loop2:

	lsr	r6, r3, SHIFTR		@save least significant
	lsr	r7, r2, SHIFTR		@save least significant
	lsl	r2, r2, 1		@shift left by 1
	lsl	r3, r3, 1		@shift left by 1
	orr	r2, r2, r6		@put the save bit into array[0]
	orr	r3, r3, r7		@put the save bit into array[1]
	add	r5, r5, 1		@increase counter
	cmp	r5, r4			@check counter
	blt	loop2			@go in loop again

put2:
	str	r2, [r0]		@put in register
	str	r3, [r0, FP_ELM]	@put in register
end:

	sub	sp, fp, FP_OFFSET
	pop	{r4-r7,fp, ip, pc}	
