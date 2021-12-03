lcd:	.equ	$f031
clr:	.equ	$10
ram:	.equ	$4000
rom:	.equ	$0000
	.org	ram		#we always use it
	lda [x]
	inca 
	sta [x]
	sta [$f031]
	jmp [$0000]
x:	.byte $05	
	.end