import sys
data = sys.stdin.read().split()
it = iter(data)
n = int(next(it))

s = "I hate"
if n == 1:
    print(s + " it")
else:
    for i in range(n - 1):
        s += " that "
        if i % 2 == 0:      # i par → siguiente capa es "love"
            s += "I love"
        else:                # i impar → siguiente capa es "hate"
            s += "I hate"
    print(s + " it")