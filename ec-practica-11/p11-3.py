class Alumno:
    def __init__(self, nombre, nota):
        self.nombre = nombre
        self.nota = nota
    
    def mostrarNombre(self):
        print(self.nombre) 
    
    def mostrarNota(self):
        print(self.nota) 
    
    def calculaNotaLiteral(self):
        match self.nota:
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

alumno1 = Alumno("Juan", 4)
alumno1.mostrarNombre()
alumno1.mostrarNota()
alumno1.calculaNotaLiteral()

print();

alumno2 = Alumno("Eduardo", 7)
alumno2.mostrarNombre()
alumno2.mostrarNota()
alumno2.calculaNotaLiteral()