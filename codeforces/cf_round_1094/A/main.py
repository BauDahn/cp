import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    n = int(next(it))
    a = [int(next(it)) for _ in range(n)]

    # Si en a hay un 100 puedo formar cualquier número posible
    if 100 in a:
        print("Yes")
    else:
        print("No")
        

    t -= 1