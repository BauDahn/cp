import sys

def solve():
    n = int(next(it))
    terreno = [int(next(it)) for i in range(n)]

    total = 0
    suma_actual = 0
    l = 0
    r = 0
    for i in range(n - 1):
        actual = terreno[i]
        if actual < terreno[i + 1]:
            suma_actual += actual
        else:
            total += suma_actual
            suma_actual = 0


if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)

        solve()