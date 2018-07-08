		.data
		n:	.word 0
		k:	.word 0
		prime:	.word 0
		eoln:   .asciiz "\n"

		.text

	main: 	li		$v0, 5         # scanf("%d", &n)
	syscall
	move 		$t0, $v0
	sw 		$t0, n

	li 		$t3, 2		
	bge		$t0, $t3, Else
	li		$t0, 0
	sw 		$t0, prime
	j		End


	Else:	li 		$t1, 2
	sw 		$t1, k
	li		$t2, 1
	sw 		$t2, prime
	j    		loop

	 loop:	div		$t4, $t0, 2      # n / 2
	 add		$t4, $t4, 1   	 #n / 2 + 1

		bge		$t1, $t4, End 	 #if(k>=n/2+1) leave the loop
		beqz 		$t2, End   	 #if(prime == 0) leave the loop
		rem 		$t5, $t0, $t1
		bnez 		$t5, Oelse	 #if(n % k != 0) goto Oelse
		li 		$t2, 0
		sw 		$t2, prime	 #prime = 0
		j		loop

		Oelse:	add 		$t1, $t1, 1
		sw 		$t1, k		 # k++
		j 		loop

	End: 	li        	$v0, 1          #printf("%d", prime)
	move 		$a0, $t2
	syscall

		la         	$a0, eoln       #printf("%c", '\n')
		li         	$v0, 4
		syscall

		li		$v0, 10		#quit program
		syscall 
		
		

