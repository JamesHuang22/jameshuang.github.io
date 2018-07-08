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

	li 	$t5, -1
	sw 	$t5, result	#result =  -1

	li 	$t4, 2
	bge 	$t0, $t4, Then
	li	$t0, 2
	sw 	$t0, x 		# x = 2
	j 	Then
	
Then:	lw	$t2,  i
	sw	$t0,  i		# i = x

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


is_prime:		#prologue
	sub	$sp, $sp, 8	#set new stack pointer 
	sw	$ra, 8($sp)	#save return address in stack
	sw	$fp, 4($sp)	#save the new frame pointer in stack
	add	$fp, $sp, 8	#set the new frame pointer in stack

	li 	$t0, 2
	sw	$t0, ($sp)
	sub	$sp, $sp, 4

	lw 	$t1, 4($fp)
	sw	$t1, ($sp)
	sub 	$sp, $sp, 4

	jal	is_prime_helper

	add	$sp, $sp, 8

	lw	 $v1, ($sp)	#store the return value
	move $t5, $v0
	#epilogue
	lw	$ra, 8($sp)
	lw 	$fp, 4($sp)
	add	$sp, $sp, 8
	jr	$ra		

is_prime_helper:	#prologue
	sub	$sp, $sp, 12 	# set new stack pointer
	sw 	$ra, 12($sp)	#save return address in  stack
	sw 	$fp, 8($sp)	#save the new frame pointer in stack
	add	$fp, $sp, 12	#set the new frame pointer in stack

	li	$t0, 1
	lw	$t4, 4($sp)
	sw 	$t0, 4($sp)	#prime = 1
	lw	$t1, 8($fp)	#get the value of the argument
	lw	$t2, 4($fp)

	div 	$t3, $t2, 2
	add 	$t3, $t3, 1

	
	bge     $t1, $t2, ret	# if(k > n / 2 + 1) go to ret
	lw	$t4, 4($sp)
	beqz	$t4, ret	# if(prime == 0) go to ret

	rem 	$t5, $t2, $t1
	bnez	$t5, Else
	li	$t6, 0
	sw	$t6, 4($sp)	# prime = 0
	j 	ret

Else:	add 	$t7, $t1, 1	# push first argument k + 1 to the stack
	sw	$t7, ($sp)
	sub	$sp, $sp, 4

	sw	$t2, ($sp)	# push second argument n to the stack
	sub 	$sp, $sp, 4

	jal	is_prime_helper
	add	$sp, $sp, 8	# pop argument from stack

	sw 	$v0, 4($sp)	# prime = is_prime_helper(k+1, n)
	
ret: 	lw 	$v0, 4($sp)
		#epilogue
	lw	$ra, 12($sp)
	lw 	$fp, 8($sp)
	add	$sp, $sp, 12
	jr	$ra
	

	
