import sys

data = sys.stdin.read().split()
it = iter(data)

s = next(it)

if s[1] == '+':
    print(f'{int(s[0]) + int(s[2]):.4f}')

elif s[1] == '-':
    print(f'{int(s[0]) - int(s[2]):.4f}')

elif s[1] == '*':
    print(f'{int(s[0]) * int(s[2]):.4f}')
else:
    print(f'{int(s[0]) / int(s[2]):.4f}')

