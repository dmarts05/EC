	.data
cad1: .asciz "Introduce un número: "
cad2 : .asciz "El resultado es: "
	.globl main
	.text
main:
  li a7, 4
  la a0, cad1
  ecall

  li a7, 5
  ecall
  
  jal x1, funcion
  
  mv t0, a0
  
  li a7, 4
  la a0, cad2
  ecall
  
  li a7, 1
  mv a0, t0
  ecall

  li a7, 10
  ecall
funcion:
  li t0, 0
  li t1, 2
bucle:
  div t2, a0, t1
  rem t3, a0, t1
  div a0, a0, t1
  beq t3, x0, bucle
  addi t0, t0, 1
  beq t2, x0, fin
  j bucle
fin:
  mv a0, t0
  ret