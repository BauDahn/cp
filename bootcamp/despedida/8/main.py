import sys
from collections import deque

def solve():
    # 1. LECTURA SÚPER RÁPIDA (Fast I/O)
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    N = int(input_data[0])
    M = int(input_data[1])
    K = int(input_data[2])
    
    T = [0] * (N + 1)
    for i in range(1, N + 1):
        T[i] = int(input_data[2 + i])
        
    is_gold = [False] * (N + 1)
    idx = 3 + N
    for _ in range(K):
        is_gold[int(input_data[idx])] = True
        idx += 1
        
    adj = [[] for _ in range(N + 1)]
    rev_adj = [[] for _ in range(N + 1)]
    
    for _ in range(M):
        u = int(input_data[idx])
        v = int(input_data[idx+1])
        adj[u].append(v)
        rev_adj[v].append(u)
        idx += 2
        
    # 2. ALGORITMO DE KOSARAJU (Versión Iterativa)
    
    # --- Pase 1: Obtener el orden de finalización ---
    order = []
    visited = [False] * (N + 1)
    head = [0] * (N + 1) # Puntero para saber qué aristas hemos visitado
    
    for i in range(1, N + 1):
        if not visited[i]:
            stack = [i]
            visited[i] = True
            while stack:
                u = stack[-1]
                if head[u] < len(adj[u]):
                    v = adj[u][head[u]]
                    head[u] += 1
                    if not visited[v]:
                        visited[v] = True
                        stack.append(v)
                else:
                    order.append(stack.pop())
                    
    # --- Pase 2: Identificar las Componentes Fuertemente Conexas (SCC) ---
    scc_id = [0] * (N + 1)
    current_scc = 0
    head_rev = [0] * (N + 1)
    
    for i in reversed(order):
        if scc_id[i] == 0:
            current_scc += 1
            stack = [i]
            scc_id[i] = current_scc
            while stack:
                u = stack[-1]
                if head_rev[u] < len(rev_adj[u]):
                    v = rev_adj[u][head_rev[u]]
                    head_rev[u] += 1
                    if scc_id[v] == 0:
                        scc_id[v] = current_scc
                        stack.append(v)
                else:
                    stack.pop()
                    
    num_sccs = current_scc
    
    # 3. CONSTRUCCIÓN DEL DAG DE SUPER-NODOS
    scc_time = [0] * (num_sccs + 1)
    scc_is_gold = [0] * (num_sccs + 1)
    dag_adj = [set() for _ in range(num_sccs + 1)]
    
    for u in range(1, N + 1):
        su = scc_id[u]
        scc_time[su] += T[u]
        if is_gold[u]:
            scc_is_gold[su] = 1 # Si un nodo dentro de la SCC es dorado, toda la SCC lo es
            
        for v in adj[u]:
            sv = scc_id[v]
            if su != sv:
                dag_adj[su].add(sv)
                
    total_gold_sccs = sum(scc_is_gold)
    
    # 4. ORDENAMIENTO TOPOLÓGICO DEL DAG (Algoritmo de Kahn)
    in_degree = [0] * (num_sccs + 1)
    for u in range(1, num_sccs + 1):
        for v in dag_adj[u]:
            in_degree[v] += 1
            
    queue = deque()
    for i in range(1, num_sccs + 1):
        if in_degree[i] == 0:
            queue.append(i)
            
    topo_order = []
    while queue:
        u = queue.popleft()
        topo_order.append(u)
        for v in dag_adj[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                queue.append(v)
                
    # 5. PROGRAMACIÓN DINÁMICA SOBRE EL DAG
    dp_g = [0] * (num_sccs + 1) # dp_g[u] = Máxima cantidad de SCCs dorados que se pueden alcanzar desde u
    dp_t = [0] * (num_sccs + 1) # dp_t[u] = Tiempo máximo para esa ruta óptima
    
    # Recorremos el DAG desde los sumideros hasta las fuentes
    for u in reversed(topo_order):
        best_g, best_t = 0, 0
        for v in dag_adj[u]:
            # Priorizamos rutas que visiten la MAYOR cantidad de nodos dorados.
            if dp_g[v] > best_g:
                best_g = dp_g[v]
                best_t = dp_t[v]
            # Si dos rutas tienen la misma cantidad de nodos dorados, priorizamos la más larga en tiempo.
            elif dp_g[v] == best_g:
                if dp_t[v] > best_t:
                    best_t = dp_t[v]
                    
        dp_g[u] = best_g + scc_is_gold[u]
        dp_t[u] = best_t + scc_time[u]
        
    # 6. VERIFICACIÓN Y SALIDA
    start_scc = scc_id[1]
    
    # Si el camino óptimo desde el inicio logra agrupar TODOS los super-nodos dorados, es válido
    if dp_g[start_scc] == total_gold_sccs:
        print(dp_t[start_scc])
    else:
        print("¿Dónde está Rubén?")

if __name__ == '__main__':
    solve()