#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> aplicar_permutacion(vector<int>& secuencia, vector<int>& permutacion) {
    vector<int> secuencia_nueva(secuencia.size());
    for (int i = 0; i < secuencia.size(); i++) {
        secuencia_nueva[i] = secuencia[permutacion[i] - 1];
    }
    return secuencia_nueva;
}

vector<int> permutar(vector<int>& secuencia, vector<int>& permutacion, ll k) {
    while (k > 0) {
        if (k & 1) { // Si k es un número impar
            secuencia = aplicar_permutacion(secuencia, permutacion);
        }
        permutacion = aplicar_permutacion(permutacion, permutacion); // Permuto la permutación
        k >>= 1; // Shifting de k
    }
    return secuencia;
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vector<int> x(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans;
    ans = permutar(a, x, k);

    for (int i : ans) {
        cout << i << " ";
    }
    cout << '\n';
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}