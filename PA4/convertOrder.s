/*
 * Filename: convertOrder.s
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: switch the order of the byte
 * Date: 3/4/2018
 * Source of Help: Tutors and Discussion slides
 */

@ Raspberry Pi direct
	.cpu	cortex-a53
	.fpu	neon-fp-armv8
	.syntax	unified

	.equ	FP_OFFSET, 20
        .equ	STRING_INDEX_TWO, 2
	.equ	STRING_INDEX_THREE, 3

	.global	convertOrder
	.type	convertOrder, %function
	.text
	.align	2

/*
 * Function name: convertOrder()
 * Function Prototype: void convertOrder ( unsigned char * toConvert );
 * Description: switch the order of byte
 * Parameters: toConvert - unsign character to be convert
 * Side effects: None
 * Error Conditions: None
 * Return Value: none
 *
 * Regisers Used:
 *	r0 - first parameter -- the string to be changed
 * 	r4 - store -- store the first index
 *	r5 - store -- store the last index
 *	r6 - store -- store the second index
 *	r7 - store -- store the third index
 */

convertOrder:

	push	{r4-r7, fp, lr}
	add	fp, sp, FP_OFFSET

	ldrb	r4, [r0]				@load the first byte
	ldrb	r5, [r0, STRING_INDEX_THREE]		@load the last byte

	strb	r4, [r0, STRING_INDEX_THREE]		@store first to last
	strb	r5, [r0]				@store last to first

	ldrb	r6, [r0, 1]				@load the second byte
	ldrb	r7, [r0, STRING_INDEX_TWO]		@load the third byte

	strb	r6, [r0, STRING_INDEX_TWO]		@store
	strb	r7, [r0, 1]				@store 

end:
	sub	sp, fp, FP_OFFSET
	pop	{r4-r7, fp, pc}
