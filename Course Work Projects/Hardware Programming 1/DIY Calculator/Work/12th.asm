	.org $4000
start:lda %00000001
left:	sta [$f020]
	shl
	jn [right]
	jmp [left]
right: sta [$f020]
	shr
	and %01111111
	jz [start]
	jmp [right]
	.end
