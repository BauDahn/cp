import sys
import heapq

def solve():
    n = int(next(it))
    a = [(int(next(it)), int(next(it)), i) for i in range(n)]
    a.sort()

    priority_queue = []
    habitaciones = [-1] * (n)

    for llegada, salida, cliente in a:
        if priority_queue and llegada > priority_queue[0][0]: # Miramos si se vació la habitación más próxima
            habitaciones[cliente] = habitaciones[priority_queue[0][1]]
            heapq.heapreplace(priority_queue, (salida, cliente))
        else:
            heapq.heappush(priority_queue, (salida, cliente))
            habitaciones[cliente] = len(priority_queue)
    
    print(len(priority_queue))
    print(' '.join(map(str, habitaciones)))


if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)
        solve()