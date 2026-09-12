import sys

data = sys.stdin.read().split()
it = iter(data)

# El problema se resume a ver si hay lugares que sean 1001 o 10001 o así
# Se puede resolver en O(N) seguramente

t = int(next(it))
while t:
    n = int(next(it))
    s = list(next(it))

    for i in range(1,n-1):
        if (s[i-1] == '1' and s[i+1] == '1'):
            s[i] = '1'
    ans1 = 0
    for i in range(n):
        if s[i] == '1':
            ans1 += 1
    
    for i in range(1,n-1):
        if (s[i-1] == '1' and s[i+1] == '1'):
            s[i] = '0'
    ans = 0
    for i in range(n):
        if s[i] == '1':
            ans += 1
    print(ans, ans1)

    t -= 1