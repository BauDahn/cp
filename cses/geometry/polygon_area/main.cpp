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
};

void solve() {
    int n;
    cin >> n;
    vector<Punto> puntos(n);
    for (Punto& p : puntos) {
        p.read();        
    }
    long long res = 0;
    for (int i = 0 ; i < n - 1 ; i++) {
        res += puntos[i] * puntos[i + 1];
    }
    res += puntos[n - 1] * puntos[0];

    cout << abs(res) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}