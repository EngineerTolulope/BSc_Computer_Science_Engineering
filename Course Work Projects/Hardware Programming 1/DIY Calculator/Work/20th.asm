	.org $4000
	bldsp $efff
	bldx $0001
read:	lda [$f011]
	jn [read]
	cmpa $01
	jc [read]
	jnz [zero]
	lda [$f000]
	pusha
	incx
	jmp [read]	
zero: decx
	jz [$0000]
	popa
	sta [$f020]
	jmp [read]
	.end
	