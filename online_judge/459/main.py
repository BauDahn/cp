import sys
sys.setrecursionlimit(100000)

data = sys.stdin.read().split('\n')
it = iter(data)

t = int(next(it))
espacio = next(it)
while t:
    maximo = next(it)
    conexiones = []
    while True:
        try:
            conexion = next(it)
            if conexion != '':
                conexiones.append(conexion)
            else:
                break
        except StopIteration:
            break
    
    # Una vez hecha la entrada de mierda esta
    # En vez de hacer una lista de adyacentes, hare un diccionario, más fácil
    dic_adyacencia = dict()
    for i in range(ord('A'), ord(maximo) + 1):
        dic_adyacencia[(chr(i))] = set()
    for conexion in conexiones:
        origen, destino = conexion
        dic_adyacencia[origen].add(destino)
        dic_adyacencia[destino].add(origen)

    
    # Ahora hay que buscar el número de subgrafos conexos que hay dentro del grafo original
    # Para encontrar componentes conexas se puede hacer un dfs marcando como visitados los nodos ya vistos
    visited = {}
    for nodo in dic_adyacencia:
        visited[nodo] = False
    
    def dfs(origen, visited):
        for nodo in dic_adyacencia[origen]:
            if nodo not in dic_adyacencia:
                continue
            if not visited[nodo]:
                # Si no ha sido visitado me sirve
                visited[nodo] = True
                dfs(nodo, visited)
        
    islas = 0
    for nodo in dic_adyacencia:
        if not visited[nodo]:
            dfs(nodo, visited)
            islas += 1

    print(islas)
    if t > 1:
        print()
    t -= 1