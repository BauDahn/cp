import sys

def solve():
    n = int(next(it))
    total = int(next(it))
    a = [int(next(it)) for _ in range(n)]

    a.sort()
    contador = 0
    for i in range(n):
        if total - a[i] >= 0:
            total -= a[i]
            contador += 1
    
    print(contador)


if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)
        solve()
    