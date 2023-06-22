import math

def menu():
    while True:
        option = int(input("Volumen cono (1)\nVolumen ortoedro (2)\nSalir (3)\n"))
        match option:
            case 1:
                return 1
            case 2:
                return 2
            case 3:
                return 3
            case _:
                print("Opción inválida, vuelva a intentarlo\n")

def volumen_cono(radius, height):
    return ((1 / 3) * math.pi * (radius * radius) * height)

def volumen_ortoedro(side1, side2, height):
    return (side1 * side2 * height)
    

result = 0
option = menu()
match option:
    case 1:
        radius = float(input("Introduce el valor del radio del cono: "))
        height = float(input("Introduce el valor de la altura del cono: "))

        result = volumen_cono(radius, height)
    case 2:
        side1 = float(input("Introduce el valor del lado 1 del ortoedro: "))
        side2 = float(input("Introduce el valor del lado 2 del ortoedro: "))
        height = float(input("Introduce el valor de la altura del ortoedro: "))

        result = volumen_ortoedro(side1, side2, height)

if (option != 3):
    print("Resultado: " + str(round(result, 2)))
