lcd:	.equ	$f031
clr:	.equ	$10
ram:	.equ	$4000
rom:	.equ	$0000
	.org	ram		#we always use it
	lda	clr 		#load the clear code which is $10 in hexadecimal
	sta	[lcd]		#store the address of the calculator interface
	jmp	[rom] 	#it is like the return 0, to show it has ended
	.end 			#end of the source code, like using a speciaL card to say it has ended