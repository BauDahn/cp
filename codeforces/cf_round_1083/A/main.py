import sys

def isUgly(i, n):
    return i == n

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    n = int(next(it))
    nums = [int(next(it)) for i in range(n)]

    frec = [False] * n

    max_i = 0

    for i in range(n):
        max_i = max(max_i, nums[i])
        if max_i == i + 1:
            frec[i] = True

    for i in range(n):
        if frec[i]:
            for j in range(n - 1, i, -1):
                if frec[j]:
                    nums[i], nums[j] = nums[j], nums[i]
                    break
            break
    
    print(' '.join(map(str, nums)))

    t -= 1
