import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))

while t:
    s = list(next(it))

    contador = 0
    for i in range(len(s) - 1):
        if s[i] == s[i + 1]:
            contador += 1
    
    if contador <= 2:
        print("YES")
    else:
        print("NO")

    t -= 1