dni_num = int(input("Introduce los números de tu DNI: "))
resto = dni_num % 23

lista_dni = ['T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E']

print("Letra del DNI: " + lista_dni[resto])