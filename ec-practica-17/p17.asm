	.data # Comienzo del segmento de datos
cad1: .asciz " Introduzca una letra: "
cad2: .asciz "\nLa letra introducida es: "
cad3: .asciz "\nLa cadena resultante es: "
letraleida: .space 2
cadleida: .space 11
######################################################
.data 0xFFFF0000 # Puerto de control del teclado
controlT: .space 1
######################################################
.data 0xFFFF0004 # Puerto de lectura del teclado
datosT: .space 1
######################################################
.data 0xFFFF0008 # Puerto de control de la pantalla
controlP: .space 1
######################################################
.data 0xFFFF000C # Puerto de escritura de la pantalla
datosP: .space 1
######################################################
	.globl main # Declaración de la etiqueta main como global
	.text # Comienzo del segmento de texto
# Función main
main :
  li a7, 4
  la a0, cad1
  ecall
  
  li t5, 0
  la t6, cadleida
  
comprueba_estado:
  la t1, letraleida
  la t4, controlT
  lb t3, (t4)
  #Se lee el byte del puerto de control
  andi t3, t3, 1
  #Se obtiene el bit de menos peso
  beq t3, zero, comprueba_estado
  # Mientras valga 0 , se sigue comprobando
  #Si el bit de menos peso vale 1 -> Se ha pulsado una tecla
  # Actualizar contador
  addi t5, t5, 1
  la t4, datosT
  lb t3, (t4)
  #Se lee el caracter que se ha pulsado
  sb t3, (t1)
  #Se almacena el caracter leido en la cadena
  addi t1, t1, 1 #Se actualiza el puntero de la cadena
  sb zero, (t1)
  #Se almacena el fin de cadena ’\0 ’ en la cadena
  # Ahora lo imprimimos por pantalla con consulta de estado :
  la t4, controlP
comprueba_estadoP:
  lb t3, (t4)
  #Se lee el byte del puerto de control
  andi t3, t3, 1
  #Se obtiene el bit de menos peso
  beq t3, zero, comprueba_estadoP
  # Mientras valga 0 , se sigue comprobando
  la t4, letraleida
  lb t0, (t4)
  #Se lee el carácter a imprimir
  la t4, datosP
  sb t0, (t4)
  #Se escribe en el puerto de la pantalla
  #También se puede imprimir con llamadas al sistema :
  li a7, 4
  la a0, cad2
  ecall

  li a7, 4
  la a0, letraleida
  ecall
  
  #Guardar letra en cadleida
  lb t1, letraleida
  sb t1, (t6)
  addi t6, t6, 1
  
  #Resetear puerto de control
  sb zero, (t4)
  
  li t1, 9
  ble t5, t1, comprueba_estado

  #Imprimir cadleida
  li a7, 4
  la a0, cad3
  ecall
  
  li a7, 4
  la a0, cadleida
  ecall

  li a7, 10
  ecall