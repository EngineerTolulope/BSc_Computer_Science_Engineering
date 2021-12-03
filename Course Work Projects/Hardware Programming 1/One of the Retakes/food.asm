	.org $4000
	bldsp $efff
star:	lda [$f000]
	sta [A]
	jsr [diff]
	lda [B]
	sta [$f020]
	jmp [star]

diff:	lda [A]
	cmpa $00
	jz [zee]
	lda $ff
	sta [B]
	jmp [next]
zee:	lda $01
	sta [B]
next:	rts		

A:	.byte 
B:	.byte
	.end
