import sys

def solve(it):
    n = int(next(it))
    tareas = [(int(next(it)), int(next(it))) for _ in range(n)] # Lista de tareas (hechas tuplas con valor y gasto)

    suma = [0 for i in range(n + 1)]
    for i in range(n - 1, -1, -1):
        valor, coste = tareas[i]
        suma[i] = max(suma[i + 1], suma[i + 1] * (1 - coste/100) + valor)
    

    print(suma[0])
    return

if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)
        t = int(next(it))

        while t:
            solve(it)
            t -= 1