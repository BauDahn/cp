import sys

def solve(data):
    n = int(next(it))
    k = int(next(it))
    array = [int(next(it)) for _ in range(n)]
    i = int(next(it)) - 1

    x = array[i]
    l = array[:i]
    r = array[i + 1:]
    cont_izquierda = 0
    cont_derecha = 0

    en_sector = False

    for valor in l:
        if valor != x:
            if not en_sector:
                cont_izquierda += 1
                en_sector = True
        else:
            en_sector = False
    
    en_sector = False
    for valor in r:
        if valor != x:
            if not en_sector:
                cont_derecha += 1
                en_sector = True
        else:
            en_sector = False

    print(2 * max(cont_derecha, cont_izquierda))
    return


if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)

        t = int(next(it))
        while t:
            solve(data)
            t -= 1