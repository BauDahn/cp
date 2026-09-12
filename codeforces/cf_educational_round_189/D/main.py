import sys

MOD = 998244353


def aproximacion(n, x):

    subsets = ((x // 2) + 1) * ((n - x) // 4)
    if n == x:
        if n % 2 == 0:
            return 0
        else:
            return n // 4
    elif (n - x) % 4 == 0:
        return subsets
    else:
        return subsets + (x//2)

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))


while t:
    n, x = int(next(it)), int(next(it))

    print(aproximacion(n, x) % MOD)

    t -= 1