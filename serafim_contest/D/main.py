import sys

def sliding_window(array, target):
    n = len(array)
    left = 0
    current_state = 0
    ans = 0

    for right in range(n):
        current_state += array[right]

        while left <= right and current_state > target:
            current_state -= array[left]
            left += 1
        
        if current_state <= target:
            ans = max(ans, right - left + 1)
    
    return ans

def knapsack(pesos, valores, capacidad):
    n = len(pesos)
    dp = [0] * (capacidad + 1)

    for i in range(n):
        for w in range(capacidad, pesos[i] - 1, -1):
            dp[w] = max(dp[w], dp[w - pesos[i]] + valores[i])

    return dp[capacidad]

data = sys.stdin.read().split()
it = iter(data)

n, h = int(next(it)), int(next(it))
a = [int(next(it)) for _ in range(n)]
valores = [1] * (n)

# Deben de ser consecutivos


print(sliding_window(a, h))