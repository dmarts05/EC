def potencia(base, exponente):
    return pow(base, exponente)

while True:
    base = int(input("Introduce un número positivo para la base: "))
    exponente = int(input("Introduce un número positivo para el exponente: "))
    if (base >= 0 & exponente >= 0):
        break;
    else:
        print("Error, alguno o los dos números no son positivos, vuelva a intentarlo")

resultado = potencia(base, exponente)
print("Resultado: " + str(resultado))