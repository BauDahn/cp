import sys
import math

# El aproach de bfs es imposible con los constraints que hay
# Sin embargo, en verdad se puede usar teoría de números. Cómo solo cambian las filas o las columnas. Se puede ver del siguiente modo:

def solve(data):
    n = int(next(it))
    m = int(next(it))
    a = int(next(it))
    b = int(next(it))

    saltos_filas = math.gcd(a, n) # Tiene que ser 1 si o si, si no me salto filas
    saltos_columnas = math.gcd(b, m) # Tiene que ser 1 si o si también

    # Por último, además de poder visitar cada casilla, como debe ir alternando entre cada paso, es necesario que por cada repetición se visiten entre 1 y 2 casillas (2 * lcm(n,m) >= n*m)
    dimension = math.gcd(n, m)

    if saltos_filas == 1 and saltos_columnas == 1 and dimension <= 2:
        print("YES")
    else:
        print("NO")
    
    return


if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)

        t = int(next(it))
        while t:
            solve(data)
            t -= 1