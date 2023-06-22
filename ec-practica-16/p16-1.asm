	.data
cad1: .asciz "Introduce un número: "
cad2: .asciz "El resultado es par"
cad3: .asciz "El resultado es impar"
error: .asciz "Error, el número debe ser positivo"
salto: .asciz "\n"
destino: .space 100

	.globl main
	.text
	
main:
  jal x1, leer_numero
  
  jal x1, numero_divisores_par_impar
  
  beq a0, zero, espar
  la a0, cad3
  j sigue
  
espar:
  la a0, cad2
  
sigue:
  li a7, 4
  ecall

  li a7, 10
  ecall
  
leer_numero:
  li a7, 4
  la a0, cad1
  ecall

  li a7, 5
  ecall
  
  mv t0, a0
  
  blt t0, x0, error_leer_numero
  
  mv a0, t0
  ret
  
error_leer_numero:
  li a7, 4
  la a0, error
  ecall
  
  li a7, 4
  la a0, salto
  ecall
  
  j leer_numero
  
numero_divisores:
  li t0, 1
  li t1, 1
  mv t2, a0
bucle:
  beq t2, t1, fin
  rem t3, t2, t1
  bne t3, x0, nodivisor
  addi t0, t0, 1
nodivisor:
  addi t1, t1, 1
  j bucle
fin: 
  mv a0, t0
  ret
  
numero_divisores_par_impar:
  addi sp, sp, -4
  sw ra, (sp)
  
  jal x1, numero_divisores
  
  mv t1, a0
  li t0, 2
  
  remu a0, t1, t0
  
  lw ra, (sp)
  addi sp, sp, 4
  ret