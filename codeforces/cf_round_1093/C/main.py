import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))

while t:
    p, q = int(next(it)), int(next(it))

    s = p + 2 * q
    k = (2 * s) + 1
    
    n = -1

    for i in range(3, int(k ** 0.5) + 1, 2):
        if k % i == 0:
            n = (i - 1) // 2
            m = ((k // i) - 1) // 2
            if n > 0 and m > 0:
                if q <= n * (m + 1) and q <= m * (n + 1):
                    break
            n = -1
            m = -1
    
    if n != -1:
        print(n, m)
    else:
        print(n)

    t -= 1