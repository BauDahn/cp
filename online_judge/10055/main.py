import sys

data = sys.stdin.read().split()
it = iter(data)

while True:
    try:
        a, b = int(next(it)), int(next(it))
        print(abs(a - b))

    except StopIteration:
        break