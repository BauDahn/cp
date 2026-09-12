#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // distancia en x e y
    int dx, dy;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    // Vemos la distancia total
    int dist = dx + dy;
    if (dist % 2 == 0) {
        cout << "SI" << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}