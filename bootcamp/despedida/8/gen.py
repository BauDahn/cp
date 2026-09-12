import sys
import random
import argparse

def main():
    parser = argparse.ArgumentParser(description="Generador de casos para El Discurso de Rubén")
    parser.add_argument('seed', type=int, help="Semilla aleatoria")
    parser.add_argument('N', type=int, help="Número de nodos")
    parser.add_argument('M', type=int, help="Número de aristas")
    parser.add_argument('K', type=int, help="Número de recuerdos dorados")
    parser.add_argument('mode', type=str, choices=['solvable', 'random'])
    
    args = parser.parse_args()
    random.seed(args.seed)
    
    N, M, K = args.N, args.M, args.K
    M = min(M, N * (N - 1))
    
    T = [random.randint(1, 10000) for _ in range(N)]
    
    all_nodes = list(range(1, N + 1))
    golden_nodes = random.sample(all_nodes, K)
    
    edges = set()
    
    if args.mode == 'solvable':
        path_nodes = [1]
        g_nodes_to_visit = [g for g in golden_nodes if g != 1]
        random.shuffle(g_nodes_to_visit)
        
        current = 1
        for g in g_nodes_to_visit:
            jumps = random.randint(0, 3)
            for _ in range(jumps):
                # FIX: Si ya casi llegamos a M, dejamos de añadir ruido extra
                if len(edges) >= M - 1:
                    break
                nxt = random.randint(2, N)
                if current != nxt:
                    edges.add((current, nxt))
                    current = nxt
            if current != g:
                edges.add((current, g))
                current = g
    
    nodes_list = list(range(1, N + 1))
    while len(edges) < M:
        u = random.choice(nodes_list)
        v = random.choice(nodes_list)
        if u != v:
            edges.add((u, v))
            
    edges = list(edges)
    random.shuffle(edges)
    
    # FIX VITAL: Actualizar M para que coincida EXACTAMENTE con las aristas generadas
    # (por si el esqueleto principal generó unas cuantas más de las esperadas)
    M = len(edges)
    
    print(f"{N} {M} {K}")
    print(" ".join(map(str, T)))
    print(" ".join(map(str, golden_nodes)))
    for u, v in edges:
        print(f"{u} {v}")

if __name__ == '__main__':
    main()