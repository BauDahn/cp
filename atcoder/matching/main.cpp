#include <bits/stdc++.h>
using namespace std;

/*
Solución del problema:
dp[mask] = Cantidad de formas válidas de emparejar las mujeres marcadas con 1 en mask con los primeros hombres del grupo
No hace falta índice, porque el número de hombres es igual al de mujeres.

*/ 

const int MOD = 1e9 + 7;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    vector<int> dp(1 << n, 0);
    dp[0] = 1;

    for (int mask = 0; mask < (1 << n); mask++) {
        if (dp[mask] == 0) continue;

        int i = __builtin_popcount(mask);
        if (i >= n) continue;

        for (int j = 0; j < n; j++) {
            if (a[i][j] && !(mask & (1 << j))) {
                int next_mask = mask | (1 << j);
                dp[next_mask] = (dp[mask] + dp[next_mask]) % MOD;
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