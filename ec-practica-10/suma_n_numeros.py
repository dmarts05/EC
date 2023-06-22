def suma_n_primeros(n):
    result = 0

    for i in range(1, n + 1):
        result += i;
    
    return result;

while True:
    num = int(input("Introduce un número positivo: "))
    if (num >= 0):
        break;
    else:
        print("Error, el número no es positivo, vuelva a intentarlo")

result = suma_n_primeros(num)
print("Resultado: " + str(result))