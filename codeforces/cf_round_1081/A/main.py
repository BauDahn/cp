import sys

def contar_islas(s):
    islas = 1
    for i in range(len(s) - 1):
        if s[i] == s[i + 1]:
            continue
        islas += 1
    
    return islas

def solve(data):
    n = int(next(it))
    s = next(it)
    s2 = s + s
    islas = 0

    for i in range(n):
        rotacion = s2[i : i + n]
        islas = max(islas, contar_islas(rotacion))

    print(islas)

if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)

        t = int(next(it))

        while t:
            solve(data)
            t -= 1