/*
 * Filename: compareAnagram
 * Author: Qiao jia Lu
 * Userid: cs30xcq
 * Description: check if two Anagram word and key are the same
 * Date: 2/19/18
 * Source of Help: Tutor and discussion slides
 */

@ Raspberry Pi directive
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.equ	FP_OFFSET, 16
	.equ	MAX_WORD_LEN, 40

	.global	compareAnagram
	.type	compareAnagram, %function

	.text
	.align	2

/*
 * Function name: compareAnagram
 * Function Prototype: int compareAnagram ( const void *p1, const void * p2 )
 * Description: checks if two Anagram word and key are the same
 * Parameters: p1 - the pointer to the first struct element
 *             p2 - the pointer to the second struct element
 * Side Effects: None
 * Error Conditions: None
 * Return Value: -1 if the anagram that p1 points to either:
 * has a smaller key than does the anagram that p2 points to, or
 * has the same key but has a smaller word than does the 
 * anagram that p2 points to +1 if the anagram that p1 points to either
 * has a larger key than does the anagram that p2 points to, or
 * has the same key but has a larger word than does the anagram 
 * that p2 points to 0 if the two anagram pointers point to 
 * equal anagrams (same key and word) 
 *
 * Registers used:
 *	r0 - arg1 -- p1
 *	r1 - arg2 -- p2
 *	r4 - store -- stores offset
 *	r5 - store -- save arg1
 *	r6 - store -- save arg2
 */

compareAnagram:
@prologue

	push	{r4-r6, fp, lr}
	add	fp, sp, FP_OFFSET

	ldr	r4, =wordOffset
	ldr	r4, [r4]
	
	mov	r5, r0			@save p1 to r5
	mov	r6, r1			@save p2 to r6
	bl	compareKey		@compare the keys

	cmp	r0, 0			@compare the keys
	bne	end			@else check if key smaller or greater
	add	r0, r5, r4		@mov r5 to r0
	add	r1, r6, r4		@mov r6 to r1
	mov	r2, MAX_WORD_LEN	@put length to register
key_if:

	bl	strncmp			@compare the words
	cmp	r0, 0			@check word are same
	bne	word_else_if		@if word are not the same

word_if:

	mov	r0, 0			@return 0 if same
	b	end			@end function

word_else_if:

	blt	word_else		@p1 is less than p2
	mov	r0, 1			@p1 is larger
	b	end			@end program

word_else:

	mov	r0, -1			@return -1

@epilogue
end:

	sub	sp, fp, FP_OFFSET
	pop	{r4-r6, fp, pc}
