def calcula_nota(nota):
    match nota:
        case (0|1|2|3|4):
            print("Suspenso")
        case (5|6):
            print("Suficiente")
        case (7|8):
            print("Notable")
        case (9|10):
            print("Sobresaliente")
        case _:
            print("Nota inválida")

nota = int(input("Introduce una nota entre 0 y 10: "))

calcula_nota(nota);