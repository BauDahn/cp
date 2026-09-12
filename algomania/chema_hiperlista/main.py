import sys

# def generador(n):
#     for i in range(10, n):
#         num = str(i)
#         if 2* (int(num[0]) + int(num[1])) == i:
#             print(i)


data = sys.stdin.read().split()
it = iter(data)

a, b = int(next(it)), int(next(it))
a, b = min(a,b), max(a, b)

inestables = 0
if a <= 18 and 18 <= b:
    inestables += 1

if a <= 0:
    inestables += 1

print(inestables)