	.org $4000
	bldsp $efff
read: lda [$f011]
	jn [read]
	jsr [proc]
	jmp [read]
proc: lda $23
	sta [$f031]
	rts
	.end