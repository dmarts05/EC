	.data
pedir_cadena: .asciz "Introduzca una cadena de texto: "
pedir_numero: .asciz "\nIntroduzca un número: "
cad_leida: .space 100
resultado: .asciz "\nEl resultado es: "
	.text
	.globl main
main:
  # Pedir cadena
  li a7, 4
  la a0, pedir_cadena
  ecall
  
  li a7, 8
  la a0, cad_leida
  li a1, 100
  ecall
  
  # Pedir número
  li a7, 4
  la a0, pedir_numero
  ecall
  
  li a7, 5
  ecall
  
  mv t0, a0
  
  la a0, cad_leida
  mv a1, t0
  jal x1, menor_igual_numero_caracteres
  
  mv t0, a0
  
  # Imprimir resultado
  li a7, 4
  la a0, resultado
  ecall
  
  li a7, 1
  mv a0, t0
  ecall
  
  li a7, 10
  ecall
  
menor_igual_numero_caracteres:
  mv t0, a1
  
  # Apilar ra por función anidada
  addi sp, sp, -4
  sw ra, (sp)
  jal x1, numero_caracteres
  
  mv t1, a0
  ble t0, t1, retornar0
  li a0, 1
fin:
  # Desapilar ra
  lw ra, (sp)
  addi sp, sp, 4
  ret

retornar0:
  li a0, 0
  j fin

numero_caracteres:
  li t1, 0
  li t2, '\n'
bucle:
  lb t3, (a0)
  beq t3, t2, fin_bucle
  addi t1, t1, 1
  addi a0, a0, 1
  j bucle  
fin_bucle:
  mv a0, t1
  ret