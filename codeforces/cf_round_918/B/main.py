import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))

while t:
    grid = [next(it) for _ in range(3)]

    res = 0
    for i in range(3):
        for letra in grid[i]:
            if letra != '?':
                res ^= ord(letra)

    if res == 1:
        print('A')
    elif res == 2:
        print('B')
    else:
        print('C')

    t -= 1