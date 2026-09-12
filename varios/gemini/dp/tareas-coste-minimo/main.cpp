#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    if (!(cin >> n)) return;

    // Meto los datos de la matriz
    vector<vector<int>> costes(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> costes[i][j];
    }

    // Creo el vector dp (inicializo en coste infinito, salvo 0 tareas que tiene coste 0)
    vector<int> dp(1 << n, INF);
    dp[0] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {

        if (dp[mask] == INF) continue; // Ahorro procesar estados inalcanzables
        int i = __builtin_popcount(mask); // Trabajador actual
        if (i >= n) continue;

        for (int j = 0; j < n; j++) {
            if (!(mask & (1 << j))) {
                // La tarea esta libre
                dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + costes[i][j]);
            }
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}