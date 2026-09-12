import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    n = int((next(it)))
    s = next(it)

    abiertos = 0
    cerrados = 0
    for i in range(n):
        if s[i] == '(':
            abiertos += 1
        else:
            cerrados += 1
    
    if cerrados == abiertos:
        print("YES")
    else:
        print("NO")
    

    t -= 1