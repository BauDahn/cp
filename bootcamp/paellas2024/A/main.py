import sys

def solve(data):
    data.sort()

    print(" ".join(data))


if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:

        solve(data)