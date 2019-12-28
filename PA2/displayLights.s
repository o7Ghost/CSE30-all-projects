/*
 * Filename: displayLights.
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: Display the lights one by one
 * Date 2/10/2018
 * Source of Help: Tutors and Discussion slides
 */

@ Raspberry Pi directives
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.equ	FP_OFFSET, 28
	.equ	COUNTER, 32
	.equ	S_COUNTER, 4
	.equ	SHIFT, 31
	.equ	SPACE, ' '
	.equ	NL, '\n'
	.equ	STAR, '*'
	.equ	UL, '-'

	.global	displayLights
	.type	displayLights, %function

	.text
	.align	2

/*
 * Function Name: displayLights()
 * Function Prototype: void displayLights( const unsigned int lightBank[] );
 * Description: Displays both on and off lights by using the symbol "_" and
 * "*"
 * Parameters: lightBank[] - the lights that is going to be displayed
 * Side Effects: None
 * Error Condition: None
 * Return Value: the sum of the three input values
 *
 * Registers used:
 *	r0 - arg 1 -- lightBank[]
 *	r4 - store -- store the lightBank 0
 *	r5 - counter -- loop counter
 *	r6 - counter - counter for space
 *	r7 - store - saves the most significant bit for both banks
 *	r8 - store - save the right side lights
 */

displayLights:
@ Standard prologue
	push	{r4-r8, fp, ip, lr}
	add	fp, sp, FP_OFFSET

@loop set up
	ldr	r4, [r0]			@get the left side lights
	ldr	r8, [r0, S_COUNTER]		@save right side lights
	mov	r5, 0				@set i to 0
	mov	r6, 0				@set space counter
	cmp	r5, COUNTER			@cmp loop counter with 0
	bge	rightlights			@skip to rightlights

@start of for loop
l_loop:
	lsr	r7, r4, SHIFT			@Save most significant
	cmp	r7, 0				@compare if its a 1 or 0
	bne	print_one			@if its a one then branch
	mov	r0, UL				@else print under line
	bl	printChar			@print under line
	add	r6, r6, 1			@incease space counter
	b	check_space			@check if there is 4 char

print_one:
	mov	r0, STAR			@move star char to r0
	bl	printChar			@print star character
	add	r6, r6, 1			@increase space counter

check_space:

	cmp	r6, S_COUNTER			@check if this is the 4 char
	bne	for_loop_end			@if not then skip to end for
	mov	r0, SPACE			@move space to r0
	bl	printChar			@print space
	mov	r6, 0				@reset counter

for_loop_end:
	lsl	r4, r4, 1			@prepare to check next bit
	add	r5, r5, 1			@increase loop counter
	cmp	r5, COUNTER			@check loop condition
	blt	l_loop				@loop again

@rightlights
rightlights:

	mov	r4, r8				@get the left side lights
	mov	r5, 0				@set i to 0
	mov	r6, 0				@set space counter
	cmp	r5, COUNTER			@cmp loop counter with 0
	bge	end

@start of for loop
r_loop:
	lsr	r7, r4, SHIFT			@Save most significant
	cmp	r7, 0				@compare if its a 1 or 0
	bne	print_r_one			@if its a one then branch
	mov	r0, UL				@else print under line
	bl	printChar			@print under line
	add	r6, r6, 1			@incease space counter
	b	check_r_space			@check if there is 4 char

print_r_one:
	mov	r0, STAR			@move star char to r0
	bl	printChar			@print star character
	add	r6, r6, 1			@increase space counter

check_r_space:
	cmp	r6, S_COUNTER			@check if this is the 4 char 
	bne     right_loop_end			@if not then skip to end for
	mov	r0, SPACE			@move space to r0
	bl	printChar			@print space
	mov	r6, 0				@reset counter

right_loop_end:
	lsl	r4, r4, 1			@prepare to check next bit
	add	r5, r5, 1			@increase loop counter
	cmp	r5, COUNTER			@check loop condition
	blt	r_loop				@loop again

	mov	r0, NL				@newline
	bl	printChar			@print newline

@epilogue
end:

	sub	sp, fp, FP_OFFSET
	pop	{r4-r8, fp,ip, pc}
