import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))

while t:
    a, b, c = int(next(it)), int(next(it)), int(next(it))
    print(a ^ b ^ c)

    t -= 1
