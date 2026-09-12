import sys

# DIEGO PROVENCIO !!!!
# Iterativo porque la recursion en python es inviable

# def buscar_mejor(n, x, s, u):
#     memoria = {}

#     def solucionar(persona, vacias, asientos_libres):
#         if persona == n:
#             return 0
        
#         actual = (persona, vacias, asientos_libres)
#         if actual in memoria: # Ya fue visto este perro
#             return memoria[actual]
        
#         # No lo siento
#         mejor_opcion = solucionar(persona + 1, vacias, asientos_libres) # Cambio de persona

#         tipo_social = u[persona]

#         if tipo_social != 'I': # Si no son introvertidos
#             if asientos_libres > 0:
#                 nueva_opcion_libre = 1 + solucionar(persona + 1, vacias, asientos_libres - 1)
#                 mejor_opcion = max(mejor_opcion, nueva_opcion_libre)
        
#         if tipo_social != 'E': # Todo lo que no es extrovertido
#             if vacias > 0: # Si me quedo algún hueco
#                 sillas_nuevas = (s - 1) if s > 1 else 0
#                 nueva_opcion_libre = 1 + solucionar(persona + 1, vacias - 1, asientos_libres + sillas_nuevas)
#                 mejor_opcion = max(nueva_opcion_libre, mejor_opcion)
                
#         memoria[actual] = mejor_opcion # Sin esto da tle sí o sí
#         return mejor_opcion

#     return solucionar(0, x, 0)


data = sys.stdin.read().split()
it = iter(data)

# Este código funciona, pero no sé como optimizarlo
# Podría ser una idea hacer algo con bitmasks para ir más rápido quizá


t = int(next(it))
while t:
    n, x, s = int(next(it)), int(next(it)), int(next(it))
    u = next(it)

    # resultado = buscar_mejor(n, x, s, u)
    dp = [-1] * (x + 1)
    dp[x] = 0

    for persona in range(n):
        tipo_social = u[persona]

        nueva_lista = list(dp)

        for vacias in range(x + 1):
            actual_sentadas = dp[vacias]

            if actual_sentadas == -1:
                continue

            mesas_disponibles = x - vacias
            asientos_libres = (mesas_disponibles * s) - actual_sentadas

            if tipo_social != 'I': # Lo mismo, si no son introvertidas
                if asientos_libres > 0: # Si tengo donde sentarlas
                    nueva_lista[vacias] = max(nueva_lista[vacias], actual_sentadas + 1)

            if tipo_social != 'E': # Ahora el otro caso
                if vacias > 0: # Si tengo mesas para gastar
                    nueva_lista[vacias - 1] = max(nueva_lista[vacias - 1], actual_sentadas + 1)
        
        dp = nueva_lista

    print(max(dp))

    t -= 1