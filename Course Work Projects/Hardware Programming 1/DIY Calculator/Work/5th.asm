	.org $4000
	lda $01
	bldx $0009
here:	sta [$f031]
	inca
      decx
	jz [$0000]
	jmp [here]
	.end