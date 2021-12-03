	.org $4000
	bldx $0000
next:	lda [txt,x]
	jz  [$0000]
      sta [$f031]
      incx
      jmp [next]

txt:	.byte $48,$45,$4C,$4C,$4F,$00
	.end