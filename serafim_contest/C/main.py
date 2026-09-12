import sys

data = sys.stdin.read().splitlines()

q = int(data[0])

for indice_linea in range(1, q + 1):
    linea = data[indice_linea]
    partes = linea.split(" ", 1)

    k = int(partes[0]) % 26
    s = partes[1]

    lista = []
    for letra in s:
        if 65 <= ord(letra) <= 90: # Es una letra mayúscula
            representacion = (ord(letra) + k)
            if representacion > 90:
                representacion -= 26

        elif 97 <= ord(letra) <= 122:
            representacion = (ord(letra) + k) 
            if representacion > 122:
                representacion -= 26
        else:
            representacion = ord(letra)

        nueva_letra = chr(representacion)
        lista.append(nueva_letra)
    
    print(''.join(map(str, lista)))