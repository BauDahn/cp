import sys

data = sys.stdin.read()

contador = 0

for linea in data:
    for c in linea:
        if c == '"':
            if contador % 2 == 0: # Es de apertura
                print('``', end='')

            else:
                print("''", end='')

            contador += 1
        else:
            print(c, end='')


# import sys

# inside = False

# for line in sys.stdin:
#     for ch in line:
#         if ch == '"':
#             if inside:
#                 print("''", end='')
#             else:
#                 print("``", end='')
#             inside = not inside
#         else:
#             print(ch, end='')

