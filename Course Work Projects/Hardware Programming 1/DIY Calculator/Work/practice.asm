	.org $4000
	bldsp $efff
read:	lda $01
	sta [$f020]
	jsr [cd]
	jmp [read]
cd:	shl
	cmpa $00
	jz [home]
	sta [$f020]
	jmp [cd]
home:	rts	
	.end

