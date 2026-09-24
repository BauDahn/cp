#include <bits/stdc++.h>
using namespace std;

struct Antena {
    int distancia;
    int radio;
    int inicio;
    int salida;
};

void solve() {
    int l, n;
    cin >> l >> n; // l = longitud tunel -> n = número de antenas

    vector<Antena> antenas(n);
    for (int i = 0; i < n; i++) {
        cin >> antenas[i].distancia >> antenas[i].radio;
        antenas[i].inicio = antenas[i].distancia - antenas[i].radio;
        antenas[i].salida = antenas[i].distancia + antenas[i].radio;
    }

    sort(antenas.begin(), antenas.end(), [] (const Antena& a, const Antena& b) {
        return a.inicio < b.inicio;
    });

    // Caso imposible (Ninguna antena cubria el inicio)
    if (antenas[0].inicio > 0) {
            cout << "NO\n";
            return; 
    }
    
    int maxima_salida = antenas[0].salida;
    for (int i = 1; i < n; i++) {
        if (maxima_salida >= l) {
            cout << "SI\n";
            return;
        }
        if (antenas[i].inicio > maxima_salida) {
            cout << "NO\n";
            return;
        }
        maxima_salida = max(maxima_salida, antenas[i].salida);
    }
    if (maxima_salida < l) {
        cout << "NO\n";
    } else {
        cout << "SI\n";
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;

}