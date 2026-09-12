import sys

def mex(lista):
    lista = sorted(set(lista)) # La hago un set
    i = 0
    while True:
        try:
            if lista[i] == i:
                i += 1
            else:
                break
        except:
            break
    
    return i

def manacher(s):
    t = "#" + "#".join(s) + "#"
    n = len(t)
    p = [0] * n

    center = 0
    right = 0

    for i in range(n):
        if i < right:
            mirror = 2 * center - i
            p[i] = min(right - i, p[mirror])
        
        while (i + p[i] + 1 < n and i - p[i] - 1 >= 0 and
               t[i + p[i] + 1] == t[i - p[i] - 1]):
            p[i] += 1
        
        if i + p[i] > right:
            center = i 
            right = i + p[i]
    
    return p

def get_palindromes(s):
    p = manacher(s)
    t = "#" + "#".join(s) + "#"
    palindromes = set()

    for i, radius in enumerate(p):
        if radius == 0:
            continue
        # Convertir índices del string transformado al original
        start = (i - radius) // 2
        end = (i + radius) // 2
        palindromes.add(s[start:end])

    return sorted(palindromes, key=len)

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    n = int(next(it))
    s = [next(it) for i in range(2*n)]
    s = ''.join(map(str,s))

    palindromos = get_palindromes(s)
    maximo = 0
    for palindromo in palindromos:
        lista = list(map(int, palindromo))
        maximo = max(maximo, mex(lista))
    
    print(int(maximo))

    t -= 1