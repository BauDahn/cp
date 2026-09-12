import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    n = int(next(it))
    grid = [list(next(it)) for i in range(2)]

    dp = [0] * (len(grid[0]) + 1)
    
    dp[1] = 1 if grid[0][0] != grid[1][0] else 0

    for i in range(2, len(grid[0]) + 1):
        verticales = dp[i - 1] + (1 if grid[0][i - 1] != grid[1][i - 1] else 0)
        horizontales = dp[i - 2] + (1 if grid[0][i - 2] != grid[0][i - 1] else 0) + (1 if grid[1][i - 2] != grid[1][i - 1] else 0)
        dp[i] = min(verticales, horizontales)

    print(dp[n])


    '''
    fijas = [[False for i in range(len(grid[0]))] for i in range(2)]

    for i in range(len(grid[0]) - 1):
        if grid[0][i] == grid[0][i + 1] and not fijas[0][i] and not fijas[0][i + 1]:
            if grid[0][i] == grid[1][i] and not fijas[0][i] and not fijas[1][i]:
                # Este hay que cambiarlo si o si
                continue
            else:
                fijas[0][i] = True
                fijas[1][i] = True
        else:
            fijas[0][i] = True
            fijas[0][i + 1] = True
    

    print(fijas)
    contador = 0
    for i in range(len(fijas) - 1):
        if fijas[0][i]:
            contador += 1
        if fijas[1][i]:
            contador += 1
    print(contador)
    '''


    t -= 1