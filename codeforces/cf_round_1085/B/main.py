import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    n, m, l = int(next(it)), int(next(it)), int(next(it))
    reinicios = [int(next(it)) for _ in range(n)]
    daños = [0] * m
    actual = n
    for i in range(l):
        daños[min(m, actual + 1) - 1] += 1
        daños.sort()
        daños = daños[::-1]

        if actual > 0 and reinicios[n - actual] - 1 == i:
            daños[0] = 0
            daños.sort()
            daños = daños[::-1]
            actual -= 1
    
    print(daños[0])
    t -= 1