	.org $4000
	bldsp $efff
	bldx $0005
read:	lda [$f011]
	jn [read]
	cmpa $09
	jc [read]
	pusha
	decx
	jnz [read]
	bldx $0005
write: popa
	sta [$f031]
	decx
	jnz [write]
	jmp [$0000]
	.end