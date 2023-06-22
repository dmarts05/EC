	.data
datos1: .half 4, 7, 2
  .align 2
  .word 1, -5
  .byte 4
  .align 1
  .half 3
  .align 2
  .word -3
  .space 2
  .byte 'c'
datos2: .byte 2, 3, 5, 7
salto: .asciz "\n"
	.globl main
	.text
main:
  la t0, datos1
  lw t1, 8(t0)
  lh t2, 18(t0)
  add t1, t1, t2
  sb t1, 24(t0)
  lb t2, 24(t0)
  
  li a7, 1
  mv a0, t2
  ecall
  
  li a7, 4
  la a0, salto
  ecall
  
  la t1, datos2
  addi t2, x0, 'e'
  sb t2, 4(t1)
  lb t3, 4(t1)
  sb t3, 16(t0)
  lb t3, 16(t0)
  
  li a7, 1
  mv a0, t3
  ecall

  li a7, 10
  ecall
