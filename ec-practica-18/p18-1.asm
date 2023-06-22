	.data
n1: .space 2
n2: .space 2
n3: .space 2
n4: .space 2
pedir_cadena: .asciz "Introduce una cadena de texto: "
pedir_numero: .asciz "\nIntroduce un número: "
cad_leida: .space 100
salto: .asciz "\n"
numero_caracteres: .asciz "\nLa cadena tiene este número de caracteres: "
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
  
  # Pedir números
  la t0, n1
  
  li a7, 4
  la a0, pedir_numero
  ecall
  
  li a7, 5
  ecall
  
  sb a0, (t0)
  sb zero, 1(t0)
  
  la t0, n2
  
  li a7, 4
  la a0, pedir_numero
  ecall
  
  li a7, 5
  ecall
  
  sb a0, (t0)
  sb zero, 1(t0)
  
  la t0, n3
  
  li a7, 4
  la a0, pedir_numero
  ecall
  
  li a7, 5
  ecall
  
  sb a0, (t0)
  sb zero, 1(t0)
  
  la t0, n4
  
  li a7, 4
  la a0, pedir_numero
  ecall
  
  li a7, 5
  ecall
  
  sb a0, (t0)
  sb zero, 1(t0)
  
  # Llamar a función que contabiliza caracteres de la cadena y caracteres iguaes a los números introducidos
  la a0, cad_leida
  lb a1, n1
  lb a2, n2
  lb a3, n3
  lb a4, n4
  jal x1, funcion
  
  # Guardar resultados
  mv t0, a0
  
  mv t1, a1
  mv t2, a2
  mv t3, a3
  mv t4, a4
  
  # Imprimir resultados
  li a7, 4
  la a0, numero_caracteres
  ecall
  
  li a7, 1
  mv a0, t0
  ecall
  
  li a7, 4
  la a0, salto
  ecall
  
  li a7, 1
  mv a0, t1
  ecall
  
  li a7, 4
  la a0, n1
  ecall
  
  li a7, 4
  la a0, salto
  ecall
  
  li a7, 1
  mv a0, t2
  ecall
  
  li a7, 4
  la a0, n2
  ecall
  
  li a7, 4
  la a0, salto
  ecall
  
  li a7, 1
  mv a0, t3
  ecall
  
  li a7, 4
  la a0, n3
  ecall
  
  li a7, 4
  la a0, salto
  ecall
  
  li a7, 1
  mv a0, t4
  ecall
  
  li a7, 4
  la a0, n4
  ecall
  
  li a7, 4
  la a0, salto
  ecall
  
  li a7, 10
  ecall
  
funcion:
  # Contador caracteres
  li t0, 0
  # Contadores de caracteres iguales
  li t1, 0
  li t2, 0
  li t3, 0
  li t4, 0
  li t5, '\n'
bucle:
  lb t6, (a0)
  beq t6, t5, fin
  # Actualizar contador de caracteres
  addi t0, t0, 1
  # Actualizar contadores de caracteres iguales
  beq t6, a1, contar1
  beq t6, a2, contar2
  beq t6, a3, contar3
  beq t6, a4, contar4
fin_contadores:
  # Mover puntero de la cadena
  addi a0, a0, 1
  j bucle

contar1:
  addi t1, t1, 1
  j fin_contadores
contar2:
  addi t2, t2, 1
  j fin_contadores
contar3:
  addi t3, t3, 1
  j fin_contadores
contar4:
  addi t4, t4, 1
  j fin_contadores
fin:
  mv a0, t0
  mv a1, t1
  mv a2, t2
  mv a3, t3
  mv a4, t4
  ret