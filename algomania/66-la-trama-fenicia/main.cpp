#include <bits/stdc++.h>
using namespace std;

// Problema feucho si no lo ves.
typedef long long ll;

// Primero un toque de exponenciación rápida
ll potencia(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res *= base;
        base *= base;
        exp /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k, p, c, a, u;
        cin >> n >> k >> p >> c >> a >> u;

        ll rondas_disponibles = n - 1;

        ll victorias_necesarias = (u + a - 1) / a;

        if (victorias_necesarias > rondas_disponibles) {
            cout << -1 << '\n';
            
        } else {
            ll gente_necesaria = (p + c - 1) / c;
    
            ll estudiantes = gente_necesaria * potencia(k, victorias_necesarias);
    
            cout << estudiantes << '\n';
        }
    }

    return 0;
}