	.org $4000
read:	lda [$f011]
	jn [read]
	jz [display]
	cmpa $05
	jc [read]
	lda [num]
	inca
	sta [num]
	jmp [read]
display: lda [num]
	sta [$f031]
	jmp [$0000]

num: .byte $00
	.end
