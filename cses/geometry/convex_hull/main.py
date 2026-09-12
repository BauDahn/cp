import sys

# Paso 1. Creo la clase punto: En cp no hace falta, pero es más fácil de ver primero para entender el código

class Punto:

    def __init__(self, x=None, y=None):
        self.x = x
        self.y = y

    def read(self, it):
        self.x = int(next(it))
        self.y = int(next(it))

    def __sub__(self, other): # Es derecho el vector que se forma al restar dos puntos
        return Punto(self.x - other.x, self.y - other.y)

    
    def __mul__(self, other): # Es derecho el producto vectorial
        return self.x * other.y - self.y * other.x
    
    def __str__(self): # Es para poder ver un punto en específico
        return f'{self.x} {self.y}'
    
    def __lt__(self, other): # Definimos lower than para poder hacer el sort
        if self.x != other.x:
            return self.x < other.x
        return self.y < other.y
    

def solve(it):
    # Cargamos los datos
    n = int(next(it))
    puntos = [Punto(int(next(it)), int(next(it))) for _ in range(n)]

    # Vamos a sortear los puntos por x para ir más organizados
    puntos.sort()
    
    hull = []
    for fase in range(2):
        S = len(hull)
        for punto in puntos:
            while len(hull) >= S + 2: # Mientras haya al menos dos puntos
                A = hull[-2]
                B = hull[-1]

                u = B - A
                v = punto - A
                if u * v >= 0: # B está a la izquierda del punto que evaluamos
                    # Es lo que queremos
                    break
                hull.pop() # Sacamos al punto B de la lista porque no sirve

            hull.append(punto)
        
        hull.pop()
        puntos.reverse()
    
    print(len(hull))
    for punto in hull:
        print(punto)


if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)
        solve(it)