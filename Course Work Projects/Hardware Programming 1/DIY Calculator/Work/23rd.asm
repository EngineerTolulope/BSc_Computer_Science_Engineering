	.org $4000
	bldsp $efff
	lda $01
again:sta [$f020]
	jsr [next]
	jmp [again]
next: shl
	cmpa $00
	jnz [gohome]
	lda $01
gohome: rts
	.end