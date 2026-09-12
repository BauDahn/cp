import sys

def suma_digitos(n):
    num = str(n)
    suma_digitos = 0
    for digito in num:
        suma_digitos += int(digito)
    
    return suma_digitos

# def generador(n):
#     for i in range(n):
#         print(i - suma_digitos(i))

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    n = int(next(it))

    if n % 9 == 0:
        # Vale la pena mirarlo
        contador = 0
        for i in range(n, n + 170):
            if i - suma_digitos(i) == n:
                contador += 1

        print(contador)    

    else:
        print(0)

    t -= 1 


    