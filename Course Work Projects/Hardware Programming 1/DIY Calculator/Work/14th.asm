	.org $4000
read:	lda %00000001
led:  sta [$f021]
	shl
	cmpa %01000000
	jz [read]
	jmp [led]
	.end