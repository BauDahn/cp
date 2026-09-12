import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))

while t:
    a = [int(next(it)) for i in range(7)]
    a.sort(reverse=False)

    print(a[-1] - sum(a[:-1]))

    t -= 1