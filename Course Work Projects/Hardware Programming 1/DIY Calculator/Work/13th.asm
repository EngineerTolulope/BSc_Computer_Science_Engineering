	.org $4000
read:	lda [$f011]
	jn [read]
	cmpa $0f
	jc [read]
	sta [$f021]
	sta [$f022]
	sta [$f023]
	jmp [read]
	.end