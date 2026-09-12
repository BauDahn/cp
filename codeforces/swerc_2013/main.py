import sys
import heapq

def dijkstra(grafo, inicio, fin):
    # En lugar de iterar por "elementos", iteramos por el RANGO de la lista
    n = len(grafo)
    distancias = {i: float('inf') for i in range(n)}
    predecesores = {i: None for i in range(n)}
    distancias[inicio] = 0
    
    pq = [(0, inicio)]
    
    while pq:
        dist_actual, nodo_actual = heapq.heappop(pq)
        
        # Si ya llegamos al destino, podríamos parar, 
        # pero para ser robustos terminamos si la dist_actual es mayor a la guardada
        if dist_actual > distancias[nodo_actual]:
            continue
            
        if nodo_actual == fin:
            break

        # Explorar vecinos
        for vecino, peso in grafo[nodo_actual]:
            distancia = dist_actual + peso
            
            # Condición de relajación
            if distancia < distancias[vecino]:
                distancias[vecino] = distancia
                predecesores[vecino] = nodo_actual
                heapq.heappush(pq, (distancia, vecino))
    
    # Reconstrucción del camino
    camino = []
    actual = fin
    
    if distancias[fin] == float('inf'):
        return [] # No hay camino posible
        
    while actual is not None:
        camino.append(actual)
        actual = predecesores[actual]
        
    return camino # Invertimos la lista para ir de inicio a fin

def distancia_euclidiana_3d(x1, y1, z1, x2, y2, z2):
    return ((abs(x1 - x2))**2 + (abs(y1 - y2))**2 + (abs(z1 - z2) * 5)**2)**0.5

def distancia_euclidiana(x1, y1, x2, y2):
    return ((abs(x1 - x2))**2 + (abs(y1 - y2))**2)**0.5

def lista_adyacencia(lugares, conexiones):
    adyacencia = [[] for _ in range(len(lugares))]
    for conexion in conexiones: # Para cada una de las conexiones
        origen, destino, metodo = conexion
        piso1, x1, y1 = lugares[origen]
        piso2, x2, y2 = lugares[destino]

        if metodo == 'walking':
            distancia = distancia_euclidiana(x1, y1, x2, y2)
            adyacencia[origen].append((destino, distancia))
            adyacencia[destino].append((origen, distancia))
        
        elif metodo == 'stairs':
            distancia = distancia_euclidiana_3d(x1, y1, piso1, x2, y2, piso2)
            adyacencia[origen].append((destino, distancia))
            adyacencia[destino].append((origen, distancia))

        elif metodo == 'lift':
            adyacencia[origen].append((destino, 1))
            adyacencia[destino].append((origen, 1))
        
        else:
            adyacencia[origen].append((destino, 1))
            adyacencia[destino].append((origen, distancia_euclidiana_3d(x1, y1, piso1, x2, y2, piso2) * 3))

    return adyacencia

data = sys.stdin.read().split()
it = iter(data)

n, m = int(next(it)), int(next(it))
lugares = [(int(next(it)), int(next(it)), int(next(it))) for i in range(n)]
conexiones = [(int(next(it)),int(next(it)), next(it)) for _ in range(m)]

q = int(next(it))
queries = [(int(next(it)), int(next(it))) for _ in range(q)]

adyacencias = lista_adyacencia(lugares, conexiones)

for query in queries:
    piso1, piso2 = query
    camino = dijkstra(adyacencias, piso1, piso2)
    print(' '.join(map(str, camino[::-1])))
