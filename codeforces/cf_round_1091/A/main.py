import sys

def solve(data):
    n = int(next(it))
    k = int(next(it))
    nums = [int(next(it)) for _ in range(n)]

    suma = sum(nums)
    if suma % 2 != 0: # Siempre que la suma de por si sea impar va a ganar el wachin
        print("YES")
        return
    # En el caso de que la suma sea par, depende de k y de la longitud del array
    if k % 2 == 0 or len(nums) % 2 == 0:
        print("YES")
        return
    
    print("NO")
    return


if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)

        t = int(next(it))
        while t:
            solve(data)
            t -= 1