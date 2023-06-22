.data
pedir_numero: .asciz "\nIntroduzca el número de iteraciones para fibonacci: "
resultado: .asciz "\nEl resultado es: "
	.text
	.globl main
main:
  # Pedir número
  li a7, 4
  la a0, pedir_numero
  ecall
  
  li a7, 5
  ecall
  
  mv t0, a0
  
  li a0, 0
  li a1, 1
  mv a2, t0
  jal x1, fibonacci
  
  # Imprimir resultado
  li a7, 1
  ecall
  
  li a7, 10
  ecall
  
fibonacci:
  li t0, 1
  mv t1, a2
bucle:
  beq t0, t1, fin
  mv t2, a0
  mv t3, a1
  add t4, t2, t3
  addi t0, t0, 1
  mv a0, t3
  mv a1, t4
  j bucle
fin:
  mv a0, t4
  ret