import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    n, h = int(next(it)), int(next(it))
    elevaciones = [int(next(it)) for _ in range(n)]

    max_prefix = [0] * n
    max_sufix = [0] * n

    # Llenado de las matrices
    for col in range(n):
        agua_en_col = 0
        maximo_actual = elevaciones[col]

        # Agua acumulada hasta esta columna
        for j in range(col, -1, -1):
            maximo_actual = max(maximo_actual, elevaciones[j])
            agua_en_col += (h - maximo_actual)
        
        # Ahora extendemos a la derecha
        s = agua_en_col
        max_prefix[col] = max(max_prefix[col], s)

        maximo_actual = elevaciones[col]
        for k in range(col + 1, n):
            maximo_actual = max(maximo_actual, elevaciones[k])
            s += (h - maximo_actual)
            max_prefix[k] = max(max_prefix[k], s)
    
    # Ahora lleno el max_sufix
    for col in range(n - 1, -1, -1):
        agua_en_col = 0
        maximo_actual = elevaciones[col]

        for j in range(col, n):
            maximo_actual = max(maximo_actual, elevaciones[j])
            agua_en_col += (h - maximo_actual)

        s = agua_en_col
        max_sufix[col] = max(max_sufix[col], s)

        maximo_actual = elevaciones[col]
        for k in range(col - 1, -1, -1):
            maximo_actual =  max(maximo_actual, elevaciones[k])
            s += (h - maximo_actual)
            max_sufix[k] = max(max_sufix[k], s)

    # Encuentro de la mejor partición posible
    res = max_prefix[n - 1]

    for i in range(n - 1):
        res = max(res, max_prefix[i] + max_sufix[i + 1])
    
    print(res)

    t -= 1