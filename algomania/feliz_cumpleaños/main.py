import sys

data = sys.stdin.read().split()
it = iter(data)

n = int(next(it))

print(bin(n).count('1'))