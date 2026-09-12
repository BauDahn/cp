import sys

data = sys.stdin.read().split()
it = iter(data)
n = int(next(it))
s = next(it)
print(s.count('S'))