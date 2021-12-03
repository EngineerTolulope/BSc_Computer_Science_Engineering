	.org $4000
read:	lda %00000001
leda:  sta [$f021]
	sta [led]
	lda [$f000]
here:	deca
	jnz [here]
	lda [led]
	shl
	cmpa %01000000
	jz [read]
	jmp [leda]
led:	.byte
	.end	