import sys
import math

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    n = int(next(it))
    p = [int(next(it)) for _ in range(n)]

    '''
    Solo me importan los subarrays de dos números.
    '''
    cont = 0
    for i in range(n - 1):
        if abs(p[i] - p[i + 1]) == math.gcd(p[i], p[i + 1]):
            cont += 1

    print(cont)

    t -= 1



