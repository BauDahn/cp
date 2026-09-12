import heapq
 
n = int(input())
l = list(map(int, input().split()))
heapq.heapify(l)
ans = 0
 
while len(l)>1:
    a = heapq.heappop(l)
    b = heapq.heappop(l)
    ans+=a+b
    heapq.heappush(l, a+b)
print(ans)

