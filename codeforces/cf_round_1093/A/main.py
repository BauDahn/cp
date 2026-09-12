import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    n = int(next(it))
    a = [int(next(it)) for _ in range(n)]

    if len(set(a)) == len(a): # No hay repetidos
        # Hacer trabajo
        a.sort(reverse=True)
        print(' '.join(map(str, a)))
    
    else:
        print(-1)


    t -= 1