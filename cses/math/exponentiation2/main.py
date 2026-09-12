import sys
import math

MOD = 10**9 + 7

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))

while t:    
    a, b, c = int(next(it)), int(next(it)), int(next(it))

    exponente = pow(b, c, MOD - 1)

    print(pow(a, exponente, MOD))

    t -= 1