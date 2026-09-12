import sys
import math


def generador(n):
    if n == 3:
        print(1, 1, 1)
        return

    if n % 2 == 0:
        print(1, (n // 2) - 1, n // 2)
        return 

    else:
        print(1, n - 2, 1)
        return

                    

data = sys.stdin.read().split()
it = iter(data)

n = int(next(it))

generador(n)

