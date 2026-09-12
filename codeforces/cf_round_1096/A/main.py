import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    a, b = int(next(it)), int(next(it))
    if a & 1 and b & 1:
        print("NO")
    else:
        print("YES")
    
    t -= 1