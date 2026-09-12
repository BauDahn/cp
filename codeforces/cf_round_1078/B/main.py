import sys

def solve(it):
    n, x, y = int(next(it)), int(next(it)), int(next(it))
    a = [int(next(it)) for _ in range(n)]
    suma = 0
    maximo = -1
    for valor in a:
        aporte = y * (valor // x)
        suma += aporte

        posible_valor = valor - aporte

        if posible_valor > maximo:
            maximo = posible_valor
    
    print(suma + maximo)
    return


if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)
        t = int(next(it))

        while t:
            solve(it)
            t -= 1