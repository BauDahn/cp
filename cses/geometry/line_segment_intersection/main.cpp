#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Punto {
    ll x, y;

    Punto operator-(const Punto& other) const {
        return {x - other.x, y - other.y};
    }

    ll cross_product(const Punto& other) const {
        return x * other.y - y * other.x;
    }

};

bool onSegment(Punto objetivo, Punto p1, Punto p2) {
    return (min(p1.x, p2.x) <= objetivo.x && objetivo.x <= max(p1.x, p2.x) && (min(p1.y, p2.y) <= objetivo.y && objetivo.y <= max(p1.y, p2.y)));
}

int getOrientation(Punto objetivo, Punto p1, Punto p2) {
    Punto u = p2 - p1;
    Punto v = objetivo - p1;

    ll cross_prod = u.cross_product(v);

    if (cross_prod == 0) return 0;
    return (cross_prod > 0) ? 1 : 2; // 1 es izquierda y 2 es derecha
}

void solve() {
    Punto p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
    
    int p1o = getOrientation(p1, p3, p4);
    int p2o = getOrientation(p2, p3, p4);
    int p3o = getOrientation(p3, p1, p2);
    int p4o = getOrientation(p4, p1, p2);

    // Ahora solo quedan los if
    if (p1o != p2o && p3o != p4o && p1o != 0 && p2o != 0 && p3o != 0 && p4o != 0) {
        cout << "YES" << endl;
        return;
    }
    if ((p1o == 0 && onSegment(p1, p3, p4)) || (p2o == 0 && onSegment(p2, p3, p4)) || (p3o == 0 && onSegment(p3, p1, p2)) || (p4o == 0 && onSegment(p4, p1, p2))) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    return;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}