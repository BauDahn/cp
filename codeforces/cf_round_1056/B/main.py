import sys

def solve():
    n = int(next(it))
    k = int(next(it))

    if k == n**2 - 1:
        print("NO")
        return
    
    print("YES")
    for i in range(n):

        s = ""
        for j in range(n):
            if k > 0:
                s += 'U'
                k -= 1
            elif i == n - 1 and j == n - 1:
                s += "L"
            elif i == n - 1:
                s += "R"
            else:
                s += "D"
    

        print(s)
    


if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)
        t = int(next(it))

        while t:
            solve()
            t -= 1