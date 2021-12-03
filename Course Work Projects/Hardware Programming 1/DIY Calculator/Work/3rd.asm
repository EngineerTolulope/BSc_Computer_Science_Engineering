	.org $4000
	lda $09
loop:	sta [$f031]
	deca
	jz [$0000]
 	jmp [loop]
	.end