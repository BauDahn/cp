#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int h, w;
    if (!(cin >> h) || !(cin >> w)) return;

    vector<string> grid(h);
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }

    // dp[i][j] = número de formas de llegar a la casilla (i, j)
    vector<vector<int>> dp(h + 1, vector<int> (w + 1, 0));

    // Como transicionamos el dp:
    // Miramos la casilla actual (i, j), si no es un obstaculo miramos la de abajo y la de la derecha
    if (grid[0][0] == '#') {
        cout << 0 << '\n';
        return;
    }

    for (int i = 1; i < h; i++) {
        if (grid[i][0] != '#') {
            dp[i][0] = 1;
        } else {
            break;
        }
    }

    for (int j = 1 ; j < w; j++) {
        if (grid[0][j] != '#') {
            dp[0][j] = 1;
        } else {
            break;
        }
    }

    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (grid[i][j] != '#') { // Si es un obstáculo
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // queue<pair<int, int>> q; // Creamos una cola
    // vector<vector<bool>> visited(h, vector<bool> (w, false)); // Creamos un vector de visitados

    // q.push({0, 0}); // i = 0, j = 0, posición de inicio
    // while (!(q.empty())) {
    //     int i = q.front().first;
    //     int j = q.front().second;

    //     q.pop();

    //     if (grid[i][j] != '#') { // Si no es un obstáculo
    //         dp[i][j] = (dp[i][j] + 1) % MOD;
    //         // Lógica para saber que adyacentes meterse en la cola.
    //         if (i == h - 1) {
    //             if (j != w - 1) {
    //                 q.push({i, j + 1});
    //             }
    //         } else if (j == w - 1) {
    //             q.push({i + 1, j});
    //         } else {
    //             q.push({i + 1, j});
    //             q.push({i, j + 1});
    //         }
    //     } 
    // }

    cout << dp[h - 1][w - 1] << '\n';
}   

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}