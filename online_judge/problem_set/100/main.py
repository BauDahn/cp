import sys
sys.setrecursionlimit(1000000)

# Tabla dp de precálculo para cada número
# dp[i] = Recorrido necesario desde i hasta 1
dp = {}

def recorrido(i, dp):
    if i in dp:
        return dp[i]

    if i <= 1:
        return 1
    
    if i & 1:
        y = 3*i + 1
    else:
        y = i // 2

    dp[i] = recorrido(y, dp) + 1
    
    return dp[i]



data = sys.stdin.read().split()
it = iter(data)

while True:
    try:
        a, b = int(next(it)), int(next(it))
        maximo = 0
        for i in range(min(a, b), max(a, b) + 1):
            n = recorrido(i, dp)
        
            if n > maximo:
                maximo = n
        
        print(a, b, maximo)
        

    except StopIteration:
        break
