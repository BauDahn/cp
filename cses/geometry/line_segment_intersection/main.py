import sys

def getOrientation(objetivo, p1, p2):
    u = (p2[0] - p1[0], p2[1] - p1[1])
    v = (objetivo[0] - p1[0], objetivo[1] - p1[1])

    cross_prod = u[0]*v[1] - u[1]*v[0]

    return cross_prod

def onSegment(objetivo, p1, p2):
    return min(p1[0], p2[0]) <= objetivo[0] <= max(p1[0], p2[0]) and \
           min(p1[1], p2[1]) <= objetivo[1] <= max(p1[1], p2[1])

def solve():
    p1 = (int(next(it)), int(next(it)))
    p2 = (int(next(it)), int(next(it)))
    p3 = (int(next(it)), int(next(it)))
    p4 = (int(next(it)), int(next(it)))

    p1_cross = getOrientation(p1, p3, p4)
    p2_cross = getOrientation(p2, p3, p4)
    p3_cross = getOrientation(p3, p1, p2)
    p4_cross = getOrientation(p4, p1, p2)

    # Hay dos posibles escenarios: Colinealidad o Cruce limpio

    if ((p1_cross > 0 and p2_cross < 0) or (p1_cross < 0 and p2_cross > 0)) and ((p3_cross > 0 and p4_cross < 0) or (p3_cross < 0 and p4_cross > 0)):
        print("YES")
        return
    if (p1_cross == 0 and onSegment(p1, p3, p4)) or (p2_cross == 0 and onSegment(p2, p3, p4)) or (p3_cross == 0 and onSegment(p3, p1, p2)) or (p4_cross == 0 and onSegment(p4, p1, p2)):
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
            solve()
            t -= 1