	.data
datos1:
  .byte 14 , 23
  .align 2
  .word 47
  .align 1
  .half 9 , 12 , 15
  .align 2

datos2 :
  .space 4
  .byte 'c', 'o'

salto: .asciz "\n"

	.globl main
	.text
	
main:
  la t0, datos1
  lw t1, 4(t0)
  lh t2, 12(t0)
  add t3, t1, t2
  sw t3, 16(t0)
  
  li a7, 1
  lw a0, 16(t0)
  ecall
  
  li a7, 4
  la a0, salto
  ecall
  
  la t0, datos2
  lb t1, 4(t0)
  addi t1, t1, 1
  lb t2, 5(t0)
  addi t2, t2, 1
  
  sb t1, -6(t0)
  sb t2, -5(t0)
  
  li a7, 1
  lb a0, -6(t0)
  ecall
  
  li a7, 4
  la a0, salto
  ecall
  
  li a7, 1
  lb a0, -5(t0)
  ecall
 
  li a7, 10
  ecall