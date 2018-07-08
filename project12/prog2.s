	.data
x:	.word 0
y:	.word 0
i:	.word 0
result:	.word 0
	.text

main:	li	$sp, 0x7ffffffc  # set up stack pointer
	li 	$v0, 5
	syscall
	move	$t0, $v0
	sw 	$t0, x		#scanf("%d", &x)

	li	$v0, 5
	syscall
	move 	$t1, $v0
	sw 	$t1, y		#scanf("%d", &y)

	li 	$t3, -1
	sw 	$t3, result	#result =  -1

	li 	$t4, 2
	bge 	$t0, $t4, Then
	li	$t0, 2
	sw 	$t0, x 		#x = 2
	j 	Then

Then:	lw 	$t2,  i
	sw	$t0,  i		#i = x

	blez 	$t1, End
	j 	loop

loop:	lw 	$t1, y
	lw	$t2, i
	lw	$t3, result
	li 	$t4, -1
	bgt	$t2, $t1, End      #if(i > y) leave the loop
	bne 	$t3, $t4, End      #if(result != -1) leave the loop

	lw	$t2, i
	sw	$t2, ($sp)	   #push argument i onto the stack
	sub 	$sp, $sp, 4
	jal 	is_prime
	add 	$sp, $sp, 4   	   #pop argument from stack
	move 	$t9, $v0	   # store the return value of the function

	beqz    $t9, else	   # if is_prime is 0, goto else
	sw 	$t2, result	   # result = i

	j 	loop

else:	add 	$t2, $t2, 1
	sw 	$t2, i		   # i++
	j	loop
	
	

End:	li	$v0, 1
	move	$a0, $t3
	syscall			#print("%d", result)

	li	$v0, 11
	li 	$a0, 10
	syscall			#print("\n")

	li 	$v0, 10
	syscall			#quit the program


				#prologue
is_prime:sub	$sp, $sp, 16     #set new stack pointer
	 sw	$ra, 16($sp)     #save return address in the stack
	 sw     $fp, 12($sp)     #save old frame pointer in the stack
	 add    $fp, $sp, 16	 #set the new frame pointer in stack
	
	 li 	$t0, 2
	 sw	$t0, 8($sp)   	 # k = 2

	 li     $t1, 1
	 sw 	$t1, 4($sp)      # prime = 1
    	 j 	Othloop
	
Othloop: lw	$t0, 4($fp)      # get the value of the argument
	 div    $t3, $t0, 2
	 add    $t3, $t3, 1

	 lw     $t7, 8($sp)
	 lw     $t8, 4($sp)
	 bge    $t7, $t3, ret    # if(k >= n / 2 + 1) leave the loop
	 beqz   $t8, ret         # if(prime == 0) leave the loop

	 rem    $t5, $t0, $t7
	 bnez   $t5, Else

	 li     $t6, 0
	 sw     $t6, 4($sp)      # prime = 0
	 j      Othloop

Else:    add    $t7, $t7, 1
	 sw     $t7, 8($sp)      # k++
	 j      Othloop

ret:     move  	$v0, $t8 
		#epilogue
	 lw 	$ra, 16($sp)
	 lw     $fp, 12($sp)
  	 add    $sp, $sp, 16
	 jr	$ra
