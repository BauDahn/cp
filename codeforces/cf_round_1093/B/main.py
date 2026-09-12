import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))

while t:
    n, m = int(next(it)), int(next(it))
    a = [int(next(it)) for _ in range(n)]

    # Hay tres opciones posibles siempre
    encontrado = False
    contador = 1
    for i in range(n - 1):
        actual = a[i]
        if actual == a[i + 1]:
            contador += 1
            if contador >= m:
                print("NO")
                encontrado = True
                break
        else:
            contador = 1

    if not encontrado:
        print("YES")
    
    t -= 1