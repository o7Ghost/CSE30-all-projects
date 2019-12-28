/*
 * File name: displayDiamond
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: display a diamond in the symbol that user want
 * Date: 1/31/2018
 * Source of Help: Source code from write up
 */

 @ Raspberry Pi directives
 	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified
		
	.equ	ROW_STEP, 2
	.equ	VERT_MARGIN, 2
	.equ	HALF_DIVISOR, 2
	.equ	BASE, 10
	.equ	NL, '\n'
	.equ	FP_OFFSET, 32

	.global	displayDiamond
	.type displayDiamond, %function

	.text
	.align 2

/*
 * Function name: displayDiamond
 * Function Prototype: displayDiamond (long width, long height,
 *                                     char border, char diamond);
 * Description draw a diamond according to the symbol that user
 * add in
 * Paramters: width - the width of the diamond
 *            height - the height of the diamond
 *            border - the symbol that the diamond border is
 *            diamond - the symbol of the diamond
 * side Effects: None
 * Error Condition: None
 * Return value: None:
 */

displayDiamond:
@ prologue
	push	{r4 - r10, fp, lr}
	add	fp, sp, FP_OFFSET
	
@start
	mov 	r4, r0			@put width to r4
	mov	r5, r1			@put height to r5
	mov	r6, r2			@put border to r6
	mov	r7, r3			@put diamond to r7
	mov	r8, 1			@r8 col and set to 1
	cmp	r8, r4			@cmp col with width
	bge	pchar			@move to next for loop

@print the top border
loop1:

	mov	r0, r6			@mov border to r0
	bl	printChar		@call printChar function
	add	r8, r8, 1		@add col counter
	cmp	r8, r4			@cmp col with width
	ble	loop1			@if less than run again
pchar:

	mov	r0, NL			@put NL in param
	bl	printChar		@print on newline

@print top half of the diamond
@set up outer2_loop

	mov	r8, 1			@assign row to 1 to r8
	mov	r9, VERT_MARGIN		@set constants
	sub	r10, r5, r9		@sub 2 from height
	cmp	r8, r10			@cmp row vs height - 2
	bgt	bottom_diamond		@mov to bottom for

loop2_outer:

@first inner loop assign
	sub	r9, r4, r8		@set outer inner for
	mov	r0, HALF_DIVISOR
	sdiv	r9, r9, r0		@set outer innter for
	cmp	r9, 1			@cmp outer vs 1
	blt	loop2_inner2		@go to second for loop

loop2_inner:

	mov	r0,r6			@put border into param
	bl	printChar		@print border
	sub	r9, r9, 1		@decrease outer
	cmp	r9, 1			@cmp to 1
	bge	loop2_inner		@go into loop2 inner

@loop2_inner2 assignment

	mov	r9, 1			@assign inner to 1
	cmp	r9, r8			@compare inner vs row
	bgt	loop2_inner3		@branch to loop3

loop2_inner2:

	mov	r0, r7			@set diamond to param
	bl	printChar		@print diamond
	add	r9, r9, 1		@increase inner count
	cmp	r9, r8			@cmp row with inner
	ble	loop2_inner2		@if true then keep running loop
	
@loop3 assignment
	
	sub	r9, r4, r8		@set outer inner for
	mov	r0, HALF_DIVISOR
	sdiv	r9, r9, r0		@set outer innter for
	cmp	r9, 1			@cmp outer vs 1
	blt	end_loop2_outer		@go to second for loop

loop2_inner3:

	mov	r0,r6			@put border into param
	bl	printChar		@print border
	sub	r9, r9, 1		@decrease outer
	cmp	r9, 1			@cmp to 1
	bge	loop2_inner3		@go into loop3 inner

end_loop2_outer:
	
	mov	r0, NL			@put NL in param
	bl	printChar		@print on newline
	mov	r0, ROW_STEP
	add	r8, r8, r0		@increase counter for rol
	cmp	r8, r10			@compare rol with height - 2
	ble     loop2_outer		@if true then for loop again

@bottom half

bottom_diamond:

	mov	r8, r5			@assign row to 1 to r8
	cmp	r8, 0			@cmp row vs height - 2
	blt	last_for		@mov to bottom for

bottom_outer:

@first inner loop assign
	sub	r9, r4, r8		@set outer inner for
	mov	r0, HALF_DIVISOR
	sdiv	r9, r9, r0		@set outer innter for
	cmp	r9, 1			@cmp outer vs 1
	blt	bottom_inner2		@go to second for loop

bottom_inner:

	mov	r0,r6			@put border into param
	bl	printChar		@print border
	sub	r9, r9, 1		@decrease outer
	cmp	r9, 1			@cmp to 1
	bge	bottom_inner		@go into loop2 inner

@loop2_inner2 assignment

	mov	r9, 1			@assign inner to 1
	cmp	r9, r8			@compare inner vs row
	bgt	bottom_inner3		@branch to loop3

bottom_inner2:

	mov	r0, r7			@set diamond to param
	bl	printChar		@print diamond
	add	r9, r9, 1		@increase inner count
	cmp	r9, r8			@cmp row with inner
	ble	bottom_inner2		@if true then keep running loop
	
@loop3 assignment
	
	sub	r9, r4, r8		@set outer inner for
	mov	r0, HALF_DIVISOR
	sdiv	r9, r9, r0		@set outer innter for
	cmp	r9, 1			@cmp outer vs 1
	blt	end_bottom_outer	@go to second for loop

bottom_inner3:

	mov	r0,r6			@put border into param
	bl	printChar		@print border
	sub	r9, r9, 1		@decrease outer
	cmp	r9, 1			@cmp to 1
	bge	bottom_inner3		@go into loop3 inner

end_bottom_outer:
	
	mov	r0, NL			@put NL in param
	bl	printChar		@print on newline
	mov	r0, ROW_STEP
	sub	r8, r8, r0		@increase counter for rol
	cmp	r8, 0			@compare rol with height - 2
	bge     bottom_outer		@if true then for loop again

last_for:

	mov	r8, 1			@r8 col and set to 1
	cmp	r8, r4			@cmp col with width
	bge	last_new_line		@move to next for loop

@print the top border
border_loop:

	mov	r0, r6			@mov border to r0
	bl	printChar		@call printChar function
	add	r8, r8, 1		@add col counter
	cmp	r8, r4			@cmp col with width
	ble	border_loop		@if less than run again

last_new_line:
	
	mov	r0, NL			@put NL in param
	bl	printChar		@print on newline
end:
	sub	sp, fp, FP_OFFSET
	pop	{r4 - r10, fp, pc}
