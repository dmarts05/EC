	.data
enteros: .space 20
ienteros: .space 20
cad1: .asciz "Introduce un número: "
salto: .asciz "\n"

	.globl main
	.text
	
main:
  jal x1, leer_numeros
  jal x1, enteros_inversos
  
  la t0, enteros
  lh t1, (t0)
  
  li a7, 1
  mv a0, t1
  ecall
  
  li a7, 4
  la a0, salto
  ecall
  
  la t0, ienteros
  lh t1, (t0)
  
  li a7, 1
  mv a0, t1
  ecall
  
  li a7 10
  ecall

leer_numeros:
  li t0, 10
  li t1, 0
  la t2, enteros
  
bucle:
  li a7, 4
  la a0, cad1
  ecall

  li a7, 5
  ecall
  
  mv t3, a0
  
  addi sp , sp , -2
  sh t3, (sp)
  
  sh t3, (t2)
  addi t2, t2, 2
  
  addi t1, t1, 1
  beq t0, t1, fin1
  j bucle
  
fin1:
  ret

enteros_inversos:
  li t0, 10
  li t1, 0
  la t2, ienteros
  
desapilar:
  lh t0, (sp)
  addi sp, sp, 2
  
  sh t0, (t2)
  addi t2, t2, 2
  beq t0, t1, fin2
  j desapilar
  
fin2:
  ret
