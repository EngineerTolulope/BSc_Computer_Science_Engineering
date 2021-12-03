	.org $4000
	lda [a]
	cmpa $05
	jz [next]
	lda $05
	sta [b]
	jmp [cont]
next:	lda $00
	sta [b]
cont:	lda [b]
	inca
	sta [c]
	jmp [$0000]	

a:	.byte $03
b:	.byte $00
c:	.byte $00
	.end
