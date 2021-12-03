#from 1 to 9
	.org $4000
here: lda [N]
	sta [$f031]
	inca
	sta [N]
	lda [x]
	deca
	jz [$0000]
	sta [x]
	jmp [here]
N:	.byte $01
X:	.byte $09
	.end



#	.org $4000
#h:	lda [n]
#	sta [$f031]
#	inca
#	sta [n]
#	cmpa $0A
#	jz [$0000]
#	jmp [h]
#n:	.byte $01
#	.end