import sys
import math

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    borde, area = int(next(it)), float(next(it))

    radio = borde/ (2*math.pi)

    if radio == 0:
        print("0.00")
    else:
        ans = (area * 2) / radio
        print(f'{ans:.2f}')

    t -= 1