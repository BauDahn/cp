import sys
import math

MOD = 10**9 + 7

if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)
        t = int(next(it))

        while t:
            a, b = int(next(it)), int(next(it))

            print(pow(a, b, MOD))
            t -= 1