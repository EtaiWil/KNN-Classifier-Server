
//Etai Wilentzik 211601653
	.data
b:	.quad 211601653
	.section	.rodata			#read only data section
format1:	.string	"%d\n"	#c+b
format3:	.string	"False\n"	#c+b
format4:	.string	"True\n"	#c+b
	########
	.text	#the beginnig of the code
.globl	main	#the label "main" is used to state the initial point of this program
	.type	main, @function	# the label "main" representing the beginning of a function
main:
    movq %rsp, %rbp #for correct debugging	# the main function:
	pushq	%rbp		#save the old frame pointer
	movq	%rsp, %rbp	#create the new frame pointer
	pushq	%rbx		#saving a callee save register.


	movq	$b, %rax	#geting the address of label "b"
	movq	$0, %rdx	#making sure %rdx will have zero in all its bits.
	movq	(%rax), %rax	#reading one word that starts at this address (reading 211601653).
	movq   %rax,%rsi
	#passing all the parameters for printf - from the last to the first (FIFO!), note the register usage
	#note that the seceond  in %rsi (b) and the fomrant will be in rdi 
	movq	$format1,%rdi	#the string is the first paramter passed to the printf function.
	movq	$0,%rax
	pushq	$0x41		#pushing a random value to the stack (causing the stack to be 16 byte aligned)
	call	printf		#calling to printf AFTER its arguments are passed (not that many arguments, therefore using registers only).
                  #return from printf, start the 2nd calculation:


	          #part 2
          movq	$b, %rax	#geting the address of label "b"
          movq	$0, %rdx	#making sure %rdx will have zero in all its bits.
          movq	(%rax), %rax	#reading one word that starts at this address (reading 211601653).
          shr         $8,%rax                # aritmetic right shift
          movq %rax,%rcx #copying the value of rax to rcx
          andq $1,%rcx   # doing and with 1 return a number after the caluclate to rcx 
       
        cmp $0,%rcx # if rcx-0 =1
        ja .L1 # if it above  zero move to l1
        #here is the else 
        
        #here if the answer 0 so need to divide by 3 the reminder 
      
        movq $b,%rax #Reading the data into rax
        movq	(%rax), %rax	#reading one word that starts at this address now the value is  (reading 211601653)
        movq $3,%r9 # want to divide later by 3 so insert it to %r9
        divq %r9 # divide unsigned the value in rax the modolo answer will be in rdx
        movq %rdx,%rsi; # movig the answser to rsi becuase its the second argument
          movq	$0, %rdx	#making sure %rdx will have zero in all its bits.
         
          
        #passing all the parameters for printf - from the last to the first (FIFO!), note the register usage
	#note that the seceond  in %rsi (b) and the fomrant will be in %rdi 
	movq	$format1,%rdi	#the string is the first paramter passed to the printf function.
	movq	$0,%rax
	call	printf		#calling to printf AFTER its arguments are passed (not that many arguments, therefore using registers only).
        jmp .L5
        # move here if the answer in above zero 
        .L1: 
        movq $b,%rax
        movq	(%rax), %rax	#reading one word that starts at this address (reading 211601653).
        imulq $3,%rax
        movq %rax,%rsi 
        	#passing all the parameters for printf - from the last to the first (FIFO!), note the register usage
	#note that the seceond  in %rsi (b) abd the fomrant will be in rdi 
	movq	$format1,%rdi	#the string is the first paramter passed to the printf function.
	movq	$0,%rax
	call	printf		#calling to printf AFTER its arguments are passed (not that many arguments, therefore using registers only).
       jmp .L5 #finished all and move to rest of the program.
       
       
       # part 3 of the assinment 
       .L5:
       movq	$b, %rax	#geting the address of label "b"
          movq	$0, %rdx	#making sure %rdx will have zero in all its bits.
          movq	(%rax), %rax	#reading one word that starts at this address (reading 211601653).
          movq       %rax,%rsi #move 211601653 from rax to rsi
          shr $16,%rsi  #do 16 right shift aritmetic. 
          xor %rsi,%rax #do xor between the result and store the result int rax. (checked and the first byte is the xor result)
          movq $8,%rsi # i want to run on the whille loop 8 times.
          movb $0,%cl # he will be the counter in the do while loop.
          movq $0,%r10 # he will be the sum of the first byte in unsigned.
          movq $1,%r11 # first byte is 1 becuase i want to do and to check the first byre stored in rax
         
            
          # the number i want to run on him in rax, the conter in cl(first byte of rcx) the sum in r10, the amount of loops in rsi.
          #%r11 will store the bit after i do and with 1 to check what is the number 0 or 1 
          #do while loop
        .L6:
          AND %rax,%r11 # store the lsb of the number in r11;   
          
          SAL %cl,%r11 # its doing (1/0)* 2^(r11) and store the value in r11.
         ADD %r11,%r10 # adding the calculate to r10 
         
          inc %cl #increase the counter in 1
          movq $1,%r11 # first byte is 1 becuase i want to do and to check the first byre stored in rax
          movzbq  %cl,%r12 #move to r12 because i need to compare quads and not byte and quad
          shr $1,%rax
          cmpq %rsi,%r12
       jl .L6 # if the counter of loop is less then 8 keep doing the loop.
 
 #after finsihed the loop the value in r10.
 movq $127,%r9
 cmpq %r9,%r10 # if r10 value >r9 value 
 ja .L7 # if you jump to l7 its mean that r10 value is bigger then r9 value 
 
 #this is the else: if r10 is not bigger then r9 value 
  movq	$format3,%rdi	#the string is the first paramter passed to the printf function.
	movq	$0,%rax
	call	printf		#calling to printf AFTER its arguments are passed (not that many arguments, therefore using registers only).
       jmp .L8 #finished all and move to rest of the program.
 
 
 
 .L7:
 movq	$format4,%rdi	#the string is the first paramter passed to the printf function.
	movq	$0,%rax
	call	printf		#calling to printf AFTER its arguments are passed (not that many arguments, therefore using registers only).
       jmp .L8 #finished all and move to rest of the program.
 .L8:
 #part 4 
          movq	$b, %rax	#geting the address of label "b"
          movq	$0, %rdx	#making sure %rdx will have zero in all its bits.
          movq	(%rax), %rax	#reading one word that starts at this address (reading 211601653).
          shr         $24,%rax # aritmetic right shift now the only byte that is not all zero is the first.
          
          
          
          
            movq $8,%rsi # i want to run on the whille loop 8 times.
          movb $0,%cl # he will be the counter in the do while loop.
          movq $0,%r10 # he will be the sum of the 1's in the byte  in unsigned.
          movq $1,%r11 # first byte is 1 becuase i want to do and to check the first byte stored in rax
         
            
          # the number i want to run on him in rax, the conter in cl(first byte of rcx) the sum in r10, the amount of loops in rsi.
          #%r11 will store the bit after i do and with 1 to check what is the number 0 or 1 
          #do while loop
        .L9:
          AND %rax,%r11 # store the lsb of the number in r11;   
          
         ADD %r11,%r10 # adding the calculate to r10 
         
          inc %cl #increase the counter in 1
          movq $1,%r11 # first byte is 1 becuase i want to do and to check the first byre stored in rax
          movzbq  %cl,%r12 #move to r12 because i need to compare quads and not byte and quad
          shr $1,%rax # logical right shift to take new lsb
          cmpq %rsi,%r12
       jl .L9 # if the counter of loop is less then 8 keep doing the loop.
       
       #exit the loop now want to print it.
       movq   %r10,%rsi #move that answer  to rsi to print it  the nubmer of 1 is the byte as an argument
	#passing all the parameters for printf - from the last to the first (FIFO!), note the register usage
	#note that the seceond  in %rsi (b) and the fomrant will be in rdi 
	movq	$format1,%rdi	#the string is the first paramter passed to the printf function.
	movq	$0,%rax
	
	call	printf		#calling to printf AFTER its arguments are passed (not that many arguments, therefore using registers only).
                  #return from printf, start the 2nd calculation:
             #return from printf first time - end of program:
	movq	$0, %rax	#return value is zero.
	movq	-8(%rbp), %rbx	#restoring the save register (%rbx) value, for the caller function.
	movq	%rbp, %rsp	#restore the old stack pointer - release all used memory.
	popq	%rbp		#restore old frame pointer (the caller function frame)
	ret			#return to caller function (OS).
