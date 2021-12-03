	.org $4000
read:	lda [$f011]
	jn [read]
	cmpa $0f
	jc [read]
	sta [x]
	shl
	shl
	shl
	shl
	or [x]
	sta [$f023]
	jmp [read]
x:	.byte
	.end