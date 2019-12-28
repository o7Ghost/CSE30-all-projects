/*
 * Filename: spawnAnagram.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: This function will fill the anagram
 * Date: 2/20/18
 * Source of Help: Tutors and discussion slides
 */

@ Raspberry Pi directive
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.equ	FP_OFFSET, 28
	.equ	MAX_WORD_LEN, 40
	.equ	TERMINATE, 0

	.global	spawnAnagram
	.type	spawnAnagram, %function

	.text
	.align	2

/*
 * Function name: spawnAnagram
 * Function Prototype: void spawnAnagram( char const * orginalWord, 
 *                                        struct Anagram * anagram );
 * Description: create a Anagram
 * Paramters: originalWord - the pointer to the original word
 *            struct Anagram  - the pointer to the anagram
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 *
 * Registers used:
 *	r0 - arg 1 -- the orginal word
 *	r1 - arg 2 -- the anagram pointer
 *	r2 - store -- save the length of the string
 *      r4 - store -- save the offset of the word
 *      r5 - store -- save the off set of the key
 *      r6 - store -- save the constant word length
 *      r7 - store -- save the pointer of the const char
 *      r8 - store -- save the pointer of the struct
 *      r9 - store -- save the null terminator
 */

spawnAnagram:
@prologue

	push 	{r4-r9, fp, lr}
	add	fp, sp, FP_OFFSET

	ldr	r4, =wordOffset			@offset for word
	ldr	r5, =keyOffset			@offset for key
	mov	r9, TERMINATE			@store null terminator
	ldr	r4, [r4]			@int value for wordoffset
	ldr	r5, [r5]			@int value for keyoffset

	mov	r6, MAX_WORD_LEN		@load word length

	mov	r7, r0				@save pointer word
	mov	r8, r1				@save pointer struct

	add	r0, r1, r4			@get word location
	mov	r1, r7				@put word
	mov	r2, r6				@mov length to r2

	bl	strncpy				@copy the original 
						@word into array
	strb	r9, [r0, MAX_WORD_LEN - 1]	@add null character

	add	r0, r8, r5			@get key offset location
	mov	r1, r7				@mov word pointer
	mov	r2, r6				@mov size to r2

	bl	spawnKey			@spawn a key

@epilogue

	sub	sp, fp, FP_OFFSET
	pop	{r4-r9, fp, pc}	
