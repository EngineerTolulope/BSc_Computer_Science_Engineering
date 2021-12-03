	.org $4000
	bldsp $efff
read: lda [$f011]
	jn [read]
	cmpa $09
	jc [read]
	jsr [cd]
	lda $20
	sta [$f031]
	jmp [read]
cd:	sta [$f031]
	deca
	jnz [cd]
	rts
	.end