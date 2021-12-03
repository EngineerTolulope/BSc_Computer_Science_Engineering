	.org $4000
	bldsp $efff
	lda	$10
	inca
	pusha
	jmp [$4000]
	.end