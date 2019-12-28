/*
 * Filename: parseLong.s
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: parse the char array into a long
 * Date: 3/4/2018
 * Source of Help: Tutors and Discussion slides
 */

@ Raspberry Pi directive
		.cpu		cortex-a53
		.fpu		neon-fp-armv8
		.syntax		unified

		.section	.rodata

		.equ		FP_OFFSET, 20
		.equ		PTR, 8
		.equ		END_PTR, 24

ERROR_NOT_INT:	.asciz	"Error: %s could not be converted to an integer.\n"

		.global		parseLong
		.type		parseLong, %function

		.text
		.align		2

/*
 * Function name: parseLong
 * Function Prototype: long parseLong ( char * str, int * errorFlag );
 * Description: parse the char array into a long
 * Parameters: str - the string that is gonna be parsed
 *             errorFlag - set the error flag if there is a error
 * Side effects: None
 * Error Conditions: Error converting to long
 * Return Value: return the long value that was parse from str
 *
 * Register Used
 *	r0 - parameter 1 -- the string to be parsed
 *	r1 - parameter 2 -- errorflag to save to 
 * 	r4 - store -- save first paramter
 *      r5 - store -- the address of errorflag
 *      r6 - store -- stores the endPter
 *      r7 - store -- store value of errno
 */

parseLong:

	push	{r4-r7, fp, lr}
	add	fp, sp, FP_OFFSET
	
	sub	sp, sp, PTR		@make space for endptr
	mov	r4, r0			@save address to r4
	mov	r5, r1			@save address to r5
	sub	r6, fp, END_PTR		@get the address of the pointer

	bl	__errno_location	@get the location of the errno
	mov	r2, 0
	str	r2, [r0]		@set it to zero
	mov	r7, r0			@save errno to r6

	mov	r0, r4			@param1
	mov	r1, r6			@param2
	mov	r2, 0			@param3

	bl	strtol			@call function
	
	ldr	r7, [r7]		@get the value of errno
	cmp	r7, 0			@check overflow
	bne	error			@if overflow
	b	check_int		@check if its a int

error:

	ldr	r0, =stderr		@load file stream
	ldr	r0, [r0]
	ldr	r1, =ERROR_NOT_INT	@load formate
	mov	r2, r4			@mov the string name
	bl	fprintf			@print the error string
	mov	r2, 1			@set flag
	str	r2, [r5]		@set errorflag 
	b	end			@end program

check_int:

	ldr	r6, [r6]		@load the value of the ptr
	ldrb	r6, [r6]                @dereference twice
	cmp	r6, 0			@compare to null terminator
	bne	error			@is not an int
	b	end			@all errors cleared
end:
	sub	sp, fp, FP_OFFSET
	pop	{r4-r7, fp, pc}	
