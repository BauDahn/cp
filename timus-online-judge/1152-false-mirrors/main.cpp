#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

/* Hay que tener en cuenta que para cada posibilidad hay que
sumar el resto de monstruos que harían daño, quizá es buena idea optimizar esa suma
La transición del dp puede ser:
dp[i] = min(dp[i - 1], dp[i] + suma resto), pero la suma del resto tiene que sacar a los dos adyacentes
Encima tengo que ir actualizando el array con los valores que saco
Alguna otra técnica además de bitmask hace falta si o si.
*/

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> monsters(n);
    for (int i = 0; i < n; i++) cin >> monsters[i];

    // Es un dp bitmasks de mínimos
    // Puedo tener una mascara que sea de longitud n
    vector<int> dp(1 << n, INT_MAX);
    dp[0] = 0;

    vector<int> precalc(1 << n);

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                precalc[mask] += monsters[i];
            }
        }
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        if (dp[mask] == INT_MAX) continue; // Estado inalcanzable
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                int i2 = (i + 1) % n;
                int i3 = (i - 1 + n) % n;

                int aux = (1 << i) | (1 << i2) | (1 << i3); // Ponemos todos los 1 que elegimos

                int newMask = mask | aux;

                dp[newMask] = min(dp[newMask], dp[mask] + precalc[newMask]);
            }
        }
    }

    cout << dp[(1 << n) - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}