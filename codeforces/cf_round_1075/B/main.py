import sys

def generador():
    pass

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    n, x = int(next(it)), int(next(it))

    a, b, c = [], [], []

    for i in range(n):
        a.append(int(next(it)))
        b.append(int(next(it)))
        c.append(int(next(it)))


    t -= 1