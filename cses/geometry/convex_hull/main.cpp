#include <bits/stdc++.h>
using namespace std;

struct Punto {

    int x, y;
    void read() {
        cin >> x >> y;
    }
    Punto operator -(const Punto& other) const {
        return Punto{x - other.x, y - other.y};
    }

    void operator -=(const Punto& other) {
        x -= other.x;
        y -= other.y;
    }

    long long operator *(const Punto& other) const {
        return (long long)x * other.y - (long long) y * other.x;
    }

    bool operator <(const Punto& b) const {
        return make_pair(x, y) < make_pair(b.x, b.y);
    }
};

void solve() {
    int n;
    cin >> n;
    // Creamos un array de puntos
    vector<Punto> puntos(n);

    // Metemos los datos
    for (Punto& p : puntos) {
        p.read();        
    }

    // Hacemos el sorteo de puntos
    sort(puntos.begin(), puntos.end()); 
    vector<Punto> hull;
    for (int i = 0 ; i < 2 ; i++) {
        const int S = hull.size();
        for (Punto C : puntos) {
            while ((int) hull.size() >= S + 2) {
                Punto A = hull.end()[-2];
                Punto B = hull.end()[-1];

                Punto u = B - A;
                Punto v = C - A;
                if (u * v >= 0) {
                    break;
                }
                hull.pop_back(); // Sacamos B

            }
            hull.push_back(C);

        }
        hull.pop_back(); // Saca el que se repite si lo hacemos así (el que está más a la derecha)
        reverse(puntos.begin(), puntos.end());
    }
    cout << hull.size() << endl;
    for (Punto p : hull) {
        cout << p.x << ' ' << p.y << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}