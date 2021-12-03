	.org $4000
	lda [x]
	cmpa $05
	jnz [else]
	lda [x]
	inca
	sta [x]
	jmp [next]
else:	lda [x]
	deca
	sta [x]
next:	sta [$f031]
	jmp [$0000]
x:	.byte $04
	.end
