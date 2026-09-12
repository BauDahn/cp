import sys

class Punto:
    
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __sub__(self, other):
        return Punto(self.x - other.x, self.y - other.y)

    def __mul__(self, other):
        return self.x * other.y - self.y * other.x
    
    def triangle(self, p1, p2): # La función sirve para comprobar la posición relativa de un punto respecto a un vector
        u = p1 - self
        v = p2 - self
        return u * v
    
    def is_on_segment(self, a, b): # La función sirve para los casos de colinealidad (u x v == 0)
        # El punto es colineal?
        if a.triangle(b, self) != 0: # No es colineal --> No está en el segmento
            return False
        # En el caso de que esté, hay que comprobar bordes
        if a.x <= self.x <= b.x or a.x >= self.x >= b.x:
            if a.y <= self.y <= b.y or a.y >= self.y >= b.y:
                return True
        return False


    def intersect(self, p_inf, a, b): 
        # La idea es usar la función triangle para ver las posiciones relativas de los puntos
        cross_1 = self.triangle(p_inf, a)
        cross_2 = self.triangle(p_inf, b)

        cross_3 = a.triangle(b, self)
        cross_4 = a.triangle(b, p_inf)
        
        # Ahora comprobamos que tengan signos distintos
        if cross_1 * cross_2 < 0 and cross_3 * cross_4 < 0:
            return True # Se intersectan
        
        return False
        


def solve():
    n = int(next(it)) # Vértices
    m = int(next(it)) # Puntos
    # Para cada punto hay que determinar si está adentro, afuera o sobre el polígono
    vertices = [Punto(int(next(it)), int(next(it))) for _ in range(n)]
    puntos = [Punto(int(next(it)), int(next(it))) for _ in range(m)]

    for punto in puntos:
        intersecciones = 0
        es_borde = False

        for i in range(n): # Vamos a comprobar cada arista ahora
            a = vertices[i]
            b = vertices[(i + 1) % n]

            cross_prod = a.triangle(b, punto)

            if cross_prod == 0: # Es colineal a con el punto, por lo que comprobamos bordes
                if min(a.x, b.x) <= punto.x <= max(a.x, b.x) and min(a.y, b.y) <= punto.y <= max(a.y, b.y):
                    es_borde = True
                    break # No nos hace falta comprobar nada más
            
            if (a.y <= punto.y < b.y) or (b.y <= punto.y < a.y): # El rayo corta verticalmente la arista
                if a.y < b.y:
                    if cross_prod > 0:
                        intersecciones += 1
                elif a.y > b.y:
                    if cross_prod < 0:
                        intersecciones += 1
    
        if es_borde:
            print("BOUNDARY")
        elif intersecciones % 2 == 0: # No está dentro
            print("OUTSIDE")
        else:
            print("INSIDE")


if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)

        solve()