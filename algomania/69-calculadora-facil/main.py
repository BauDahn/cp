import sys

data = sys.stdin.read().split()

it = iter(data)
print(eval(next(it)))