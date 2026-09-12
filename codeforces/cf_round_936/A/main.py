import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))

while t:
    n = int(next(it))
    a = [int(next(it)) for _ in range(n)]


    a = sorted(a)

    if n % 2 == 0:
        mediana = a[(n // 2) - 1]
        if mediana == a[-1]:
            print((len(a) // 2) + 1)
        else:
            siguiente = a[(len(a)//2)]
            cantidad = 1
            i = 1
            while siguiente == mediana:
                if siguiente != mediana:
                    break
                else:
                    siguiente = a[len(a)//2 + i]
                    i += 1
                    cantidad += 1
        
            print(cantidad)

    else:
        mediana = a[(len(a) // 2)]
        if mediana == a[-1]:
            print((len(a) // 2) + 1)

        else:
            siguiente = a[(len(a)//2) + 1]
            cantidad = 1
            i = 2
            while siguiente == mediana:
                if siguiente != mediana:
                    break
                else:
                    siguiente = a[len(a)//2 + i]
                    i += 1
                    cantidad += 1
        
            print(cantidad)


    t -= 1