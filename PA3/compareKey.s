/*
 * File name: compareKey.s
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: check if key in two structs are the same
 * Date: 2/18/2018
 * Source of Help: Tutors and discussion slides
 */

@ Raspberry Pi directive
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.equ	FP_OFFSET, 4
	.equ	MAX_WORD_LEN, 40

	.global	compareKey
	.type	compareKey, %function

	.text
	.align	2

/*
 * Function name: compareKey() 
 * Function Prototype: int compareKey ( const void * p1, const void * p2 )
 * Description: checks if key in two structs are the same
 * Parameters: p1 - the pointer to the first struct
 *             p1 - the pointer to the second struct
 * Side Effects: None
 * Error Conditions: None
 * Return Value: -1 if the anagram that p1 points to has a smaller key than 
 * the anagram that p2 points to, +1 if the anagram that p1 points to 
 * has a larger key than the anagram that p2 points to, 0 if the two anagram 
 * pointers point to anagrams with the same key
 * 
 * Registers used:
 * 	r0 - arg1 - p1
 *	r1 - arg2 - p2
 *	r3 - store -- saves the keyOffset
 */

compareKey:
@prologue

	push	{fp, lr}
	add	fp, sp, FP_OFFSET

	ldr	r2, =keyOffset		@load keyOffset	
	ldr	r3, [r2]		@dereference keyoffset

	add	r0, r0, r3		@increase memory address
	add	r1, r1, r3		@increase memory address
	mov	r2, MAX_WORD_LEN	@mov max length
	bl	strncmp			@compare

	cmp	r0, 0			@check what's return
	bne	else_if			@branch

if:
	mov	r0, 0			@return 0
	b	end			@end

else_if:

	blt	else			@branch
	mov	r0, 1			@return 1
	b	end			@end

else:

	mov	r0, -1			@return -1

@epilogue
end:

	sub	sp, fp, FP_OFFSET
	pop	{fp, pc}
