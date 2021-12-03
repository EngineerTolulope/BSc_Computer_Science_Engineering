	.org $4000
back:	lda [$f000]
	xor %11111111
	sta [$f020]
	jmp [back]
	.end