from collections import deque

def shortest_path(graph:dict, start, end, ):
    if start == end:
        return [start], 0
    
    visited = {start}
    queue = deque([(start, [start], 0)])

    while queue:
        node, path, cost = queue.popleft()

        for neighbor in graph[node]:
            if neighbor == end:
                return path + [neighbor], cost + 1

            if neighbor not in visited:
                visited.add(neighbor)
                queue.append((neighbor, path + [neighbor], cost + 1))
    
    return None # Si no existe el camino

graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D'],
    'C': ['A', 'D'],
    'D': ['B', 'C', 'E', 'F'],
    'E': ['D', 'G'],
    'F': ['D', 'G'],
    'G': ['E', 'F', 'H', 'I'],
    'H': ['G'],
    'I': ['G'],
}

path, cost = shortest_path(graph, 'A', 'I')
print(f"Camino: {path}")   # ['A', 'B', 'D', 'E', 'G', 'I']
print(f"Coste: {cost}")    # 5