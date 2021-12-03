	.org $4000
	bldsp $efff
	bldiv interrup
      setim
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
interrup: clrim
	pusha
	lda [$f011]
	sta [$f031]
	popa
	rti
n:	.byte
	.end