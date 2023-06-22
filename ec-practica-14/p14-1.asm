	.data
cad1: .asciz "Introduzca una cadena: "
cad2: .space 100
cad3: .asciz "La longitud de la cadena es: "
cad4: .asciz "La suma de los valores ascii de la cadena es: "
salto: .asciz "\n"
	.globl main
	.text
main:
  # Imprimir petición de cadena
  li a7, 4
  la a0, cad1
  ecall
  
  # Pedir cadena de máximo 100 caracteres
  li a7, 8
  la a0, cad2
  li a1, 100
  ecall
  
  # Llamar a función
  la a0, cad2
  jal x1, funcion
  
  # Guardar suma ascii y longitud cadena
  mv t0, a0
  mv t1, a1
  
  # Imprimir resultados
  li a7, 4
  la a0, cad3
  ecall
  
  li a7, 1
  mv a0, t0
  ecall
  
  li a7, 4
  la a0, salto
  ecall
  
  li a7, 4
  la a0, cad4
  ecall
  
  li a7, 1
  mv a0, t1
  ecall

  li a7, 10
  ecall
funcion:
  li t0, 0
  li t1, 0
  li t3, '\n'
bucle:
  lb t2, (a0)
  beq t2, t3, fin
  addi t0, t0, 1
  add t1, t1, t2
  addi a0, a0, 1
  j bucle
fin:
  mv a0, t0
  mv a1, t1
  ret