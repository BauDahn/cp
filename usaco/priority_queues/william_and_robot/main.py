import sys
import heapq

def solve():
    n = int(next(it))
    nums = [int(next(it)) for _ in range(n)]

    priority_queue = []
    for i in range(0, n, 2):
        num1 = nums[i]
        num2 = nums[i + 1]
        heapq.heappush(priority_queue, num1)
        heapq.heappush(priority_queue, num2)
        heapq.heappop(priority_queue)
    
    print(sum(priority_queue))


if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)

        solve()
        