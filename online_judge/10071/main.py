import sys

data = sys.stdin.read().split()
it = iter(data)

while True:
    try:
        v, t = int(next(it)), int(next(it))
        print(v * t * 2)
    except StopIteration:
        break



    # En 12 segundos gana 5 de velocidad, en 24 segundos, cuanto se mueve?
    # d = v * t (cuando la velocidad es constante)
    # 12 5, 24 * 10 // 2 == 120