import sys

def solve(data):
    restaurantes = [[] for _ in range(len(data) // 3)]
    for i in range((len(data) // 3)):
        restaurantes[i] = data[3*i : 3*i + 3]
    
    orden = []
    i = 0
    for restaurante in restaurantes:
        utiles, total = restaurante[1], restaurante[2]
        efectividad = int(utiles) / int(total)
        orden.append((efectividad, i, restaurante[0]))
        i += 1

    orden.sort()
    for efectividad, i, id in orden:
        print(id)

if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        
        solve(data)
