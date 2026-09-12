#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    if (n == 0) return;

    vector<string> grid(n + 1);
    for (int i = 0; i < n; i++) cin >> grid[i];

    // Salimos de la casilla de abajo a la izquierda (n - 1, 0)
    // Vamos a la casilla (0, n - 1)

    // dp[i][j] = número de formas de llegar a la casilla (i, j)
    if (grid[n - 1][0] == 'X') {
        cout << 0 << '\n';
        return;
    }

    // Ahora creamos la tabla dp
    vector<vector<long long>> dp(n + 1, vector<long long> (n + 1, 0));

    // Cual es la transición del estado dp?
    // dp[i][j] = dp[i][j - 1] + dp[i + 1][j]
    dp[n - 1][0] = 1; // Ponemos la primer casilla a 1

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            // Esa es la forma de recorrer el bucle
            if (grid[i][j] != 'X') {
                // Si no estamos en un obstáculo
                if (i == n - 1 && j == 0) continue;
                dp[i][j] = (j > 0 ? dp[i][j - 1] : 0) + (i < n - 1 ? dp[i + 1][j] : 0);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    cout << dp[0][n - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while (cin >> n && n != 0) {
        solve(n);
    }

    return 0;
}