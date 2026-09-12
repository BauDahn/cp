import sys
from collections import deque

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))

while t:
    n = int(next(it))
    a = [int(next(it)) for _ in range(n)]

    a.sort()

    for i in range(n - 1):
        if (a[i] * a[i + 1]) % 6 == 0:
            
    
    print(' '.join(map(str, a)))

    t -= 1