# import math

# informables =  set()
# for i in range(0, 200, 5):
#     n = str(math.factorial(i))
#     ceros = 0
#     j = len(n) - 1
#     while j > 0 and n[j] == '0':
#         ceros += 1
#         j-= 1
    
#     informables.add(ceros)
#     print(f'n = {i}, ceros = {ceros}, cantidad de 5: {ceros - (ceros // 5) * 2}, cantidad de 25: {ceros // 5}, cantidad de 50: {ceros // 10}')
#     print(f'n = {i}, predicted = {((ceros - ((ceros // 5) * 2) - (ceros // 10) * 3) * 5) + ((ceros // 5) * 5) + (((ceros // 10) * 5) * 3)}')
#     print()
# posibles = [i for i in range(len(informables))]
# lista = []
# for num in posibles:
#     if num not in informables:
#         lista.append(num)

# print(f'Los informables son: {lista}')

def predictor_O1(ceros):
    if ceros == 0:
        return 0

    # 1. Creamos los coeficientes del patrón de ceros (secuencia: 1, 6, 31, 156...)
    # Para números pequeños con los primeros 5 valores basta (sirve hasta miles de ceros)
    valores_ceros = [1, 6, 31, 156, 781, 3906] 
    potencias_5 = [5, 25, 125, 625, 3125, 15625]
    
    n_predicho = 0
    restante = ceros
    
    # 2. Descomponemos los ceros de mayor a menor en O(1) pasos
    for i in range(len(valores_ceros) - 1, -1, -1):
        if restante >= valores_ceros[i]:
            cociente = restante // valores_ceros[i]
            # Si el dígito en base 5 excede 4, significa que esa cantidad de ceros es imposible
            if cociente >= 5: 
                return f"No informable ({ceros} ceros es imposible)"
            
            n_predicho += cociente * potencias_5[i]
            restante %= valores_ceros[i]
            
    # 3. Verificación final de "No informables"
    # Si después de descomponer quedó algún residuo, es un número fantasma (salto de ceros)
    if restante != 0:
        return f"No informable ({ceros} ceros es imposible)"
        
    return n_predicho

# --- COMPROBACIÓN DEL PATRÓN ---
for c in range(0, 100):
    print(f"Ceros: {c} -> n predicho: {predictor_O1(c)}")
