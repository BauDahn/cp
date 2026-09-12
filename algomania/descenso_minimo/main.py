import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
        
    n = int(next(it))

    operaciones = 0
    operaciones += n % 3
    n -= (n % 3)
    while n != 0:
        n //= 3
        operaciones += n % 3
        n -= (n % 3)
        operaciones += 1

    print(operaciones - 1)

    t -= 1