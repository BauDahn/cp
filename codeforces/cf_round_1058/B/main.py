import sys

def solve(it):
    n = int(next(it))
    b = [0] + [int(next(it)) for _ in range(n)]

    a = []
    for i in range(1, n + 1):
        if b[i] == b[i - 1] + i:
            a.append(i)
            continue
        # Si está repetido tenemos que ver cual es el que está repetido
        # Eso es calculable, con:
        repetido = b[i] - b[i - 1]
        a.append(a[-repetido])

    print(' '.join(map(str, a)))
    return


if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)
        t = int(next(it))

        while t:
            solve(it)
            t -= 1