	.org $4000
	bldsp $efff
	lda [$f000]
	sta [A]
	lda [$f001]
	sta [B]
	jsr [diff]
	lda [C]
	sta [$f020]
	jmp [$0000]

diff:	lda [B]
	cmpa [A]
	jc [car]
	lda [A]
	sub [B]
	sta [C]
	jmp [next]
car:	sub [A]
	sta [C]
next:	rts		

A:	.byte 
B:	.byte 
C:	.byte 
	.end
