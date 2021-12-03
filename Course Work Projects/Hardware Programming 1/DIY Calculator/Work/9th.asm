	.org $4000
read:	lda [$F011]
	JN [read]
	cmpa $09
	jc [read]
	sta [$f031]
	jmp [read]
	.end
	