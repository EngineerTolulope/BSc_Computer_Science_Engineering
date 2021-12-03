	.org $4000
here:	lda [$f000]
	sta [$f020]
	jmp [here]
	.end	