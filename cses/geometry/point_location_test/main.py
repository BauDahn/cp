import sys

class Punto:

    def __init__(self, x=None, y=None):
        self.x = x
        self.y = y

    def read(self, it):
        self.x = int(next(it))
        self.y = int(next(it))

    def __sub__(self, other):
        return Punto(self.x - other.x, self.y - other.y)

    
    def __mul__(self, other):
        return self.x * other.y - self.y * other.x
    

def solve(it):
    '''
    Explicación del problema
    Hay una línea que pasa por los puntos p1 y p2.
    Luego hay un punto p3.
    La tarea es saber la posición relativa de p3 a la línea (sobre, a la izquierda, a la derecha)

    Cómo resolver?
    Creamos el vector u a partir de los puntos, luego v a partir de p1 y p3.
    Una vez hecho eso, hacemos el producto vectorial entre ambos puntos, que se puede hacer con el determinante de una matriz 2x2 donde las filas son los componentes x e y de u y v.
    Luego miramos el valor del determinante
    '''
    # Creo los puntos
    p1 = Punto(); p1.read(it)
    p2 = Punto(); p2.read(it)
    p3 = Punto(); p3.read(it)

    # Creación de los vectores
    u = p2 - p1
    v = p3 - p1
    
    # Producto vectorial
    cross_prod = u * v

    if cross_prod == 0:
        print("TOUCH")
    elif cross_prod > 0:
        print("LEFT")
    else:
        print("RIGHT")
    
    return
    


if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)
        t = int(next(it))
        for _ in range(t):
            solve(it)