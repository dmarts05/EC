lista = [-4, -2, 0, 2, 4]

lista_sin_negativos = [i for i in lista if i >= 0]

for i in lista_sin_negativos:
    print(i, end = " ")