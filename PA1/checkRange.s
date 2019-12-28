/*
 * Filename: checkRange.s
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: check if value is in between minRange and maxRange
 * Date: 1/24/18 
 * Source of Help: Tutors, discussion and lecture slide 
 */

@ Raspberry Pi directives
	.cpu	cortex-a53
	.fpu neon-fp-armv8
	.syntax unified

	.equ FP_OFFSET, 4

	.global checkRange
	.type checkRange, %function

	.text
	.align 2

/*
 * Function name: checkRange 
 * Function Prototype: checkRange( long value, long minRange, long maxRange )
 * Description: check if value is between minRange and maxRange
 * Parameters: value - the value that needs to be check
 *             minRange - the minium range that the value has to be in
 *             maxRange - the maxium Range that the value has to be in
 * Side effects: None
 * Error Condition: minRange is greater than maxRange
 * return Value: if any error, return -1. Otherwise, return 1 to
 * represent true, 0 to represent false
 */

checkRange:
@ prologue
	push	{fp, lr}		@ Save registers: fp, lr
	add	fp, sp, FP_OFFSET	@ set fp to base of saved registers
	cmp	r1, r2			@ compare minRange and maxRange
	bgt 	errorHandle		@ error if min is greater than max

	cmp 	r0, r1			@ value is greater or equal to min
	blt 	else			@ value is less than min

	cmp 	r0, r2			@ value is smaller or equal to max
	bgt 	else			@ if value is greater than max
	
	mov 	r0, 1			@ statement is true set return to one
	b 	end			@ end program

errorHandle:
	mov 	r0, -1			@ return negative one
	b 	end			@ end program

else:
	mov 	r0, 0			@ return zero
	b 	end			@ end program

@ epilogue
end:
	sub 	sp,fp, FP_OFFSET	@ Set sp to top of saved registers 
	pop	{fp,pc}			@ Restore fp
					@ return
