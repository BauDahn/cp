import heapq
from collections import defaultdict

n = int(input().strip())
graph = defaultdict(list)

for _ in range(n):
    tokens = input().split()
    cycle_length = sum(int(tokens[j]) for j in range(1, len(tokens), 2))
    
    curr_time = 0
    for j in range(0, len(tokens) - 1, 2):
        u = tokens[j]
        delta = int(tokens[j+1])
        v = tokens[j+2]
        graph[u].append((v, cycle_length, curr_time, delta))
        curr_time += delta

start_stop = input().strip()
q = int(input().strip())
queries = input().split()

dist = {start_stop: 0}
pq = [(0, start_stop)]

while pq:
    d, u = heapq.heappop(pq)
    
    if d > dist.get(u, float('inf')):
        continue
        
    for v, cycle_length, offset, delta in graph[u]:
        wait_time = (offset - d) % cycle_length
        next_d = d + wait_time + delta
        
        if next_d < dist.get(v, float('inf')):
            dist[v] = next_d
            heapq.heappush(pq, (next_d, v))

ans = [str(dist.get(query, -1)) for query in queries]
print(" ".join(ans))