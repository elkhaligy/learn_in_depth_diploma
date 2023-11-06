	.cpu cortex-m3
	.arch armv7-m
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"main.c"
	.text
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #12
	add	r7, sp, #0
	ldr	r3, .L7
	ldr	r3, [r3]
	ldr	r2, .L7
	orr	r3, r3, #16
	str	r3, [r2]
	ldr	r3, .L7+4
	ldr	r3, [r3]
	ldr	r2, .L7+4
	bic	r3, r3, #15728640
	str	r3, [r2]
	ldr	r3, .L7+4
	ldr	r3, [r3]
	ldr	r2, .L7+4
	orr	r3, r3, #2097152
	str	r3, [r2]
.L6:
	ldr	r2, .L7+8
	ldrh	r3, [r2]	@ movhi
	bfc	r3, #13, #1
	strh	r3, [r2]	@ movhi
	movs	r3, #0
	str	r3, [r7, #4]
	b	.L2
.L3:
	ldr	r3, [r7, #4]
	adds	r3, r3, #1
	str	r3, [r7, #4]
.L2:
	ldr	r3, [r7, #4]
	ldr	r2, .L7+12
	cmp	r3, r2
	bls	.L3
	ldr	r2, .L7+8
	ldrh	r3, [r2]	@ movhi
	orr	r3, r3, #8192
	strh	r3, [r2]	@ movhi
	movs	r3, #0
	str	r3, [r7]
	b	.L4
.L5:
	ldr	r3, [r7]
	adds	r3, r3, #1
	str	r3, [r7]
.L4:
	ldr	r3, [r7]
	ldr	r2, .L7+12
	cmp	r3, r2
	bls	.L5
	b	.L6
.L8:
	.align	2
.L7:
	.word	1073877016
	.word	1073811460
	.word	1073811468
	.word	199999
	.size	main, .-main
	.ident	"GCC: (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)"
