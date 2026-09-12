import sys

data = sys.stdin.read().split()
it = iter(data)

a = [int(next(it)) for _ in range(4)]

a_set = list(set(a))

print(len(a) - len(a_set))