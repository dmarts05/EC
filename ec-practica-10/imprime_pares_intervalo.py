def imprime_pares_intervalo(n1, n2):
    for i in range(n2 , n1 + 1, -1):
        if ((i % 2) == 0):
            print(i, end = " ")

while True:
    n1 = int(input("Introduce el primer número: "))
    n2 = int(input("Introduce el segundo número: "))

    if (n1 < n2):
        break
    else:
        print("El número 1 es mayor que el número 2, vuelva a intentarlo\n")

imprime_pares_intervalo(n1, n2)