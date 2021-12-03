	.org $4000
start: lda $01
next: sta [$f032]
	shl
	sta [n]
	lda $80
wait:	deca
	jnz [wait]
	lda [n]
	cmpa %01000000
	jz [start]
	jmp [next]
n:	.byte
	.end