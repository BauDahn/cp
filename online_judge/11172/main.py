import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    a, b = int(next(it)), int(next(it))
    if a > b:
        print('>')
    elif b > a:
        print('<')
    else:
        print('=')


    t -= 1