#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Solución que veo para el problema:
/*
dp[i][j] = Número de formas de llegar a la casilla (i, j)
dp[i][j] = (grid[i][j] == '*' ? 0 : dp[i - 1][j] + dp[i][j - 1]);
*/

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<vector<char>> grid(n, vector<char> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> grid[i][j];
    }

    vector<vector<int>> dp(n, vector<int> (n, 0));
    if (grid[0][0] == '*') {
        cout << 0 << '\n';
        return;
    }

    dp[0][0] = 1;

    for (int i = 1; i < n; i++) {
        if (grid[i][0] != '*') {
            dp[i][0] = dp[i - 1][0];
        }
    }

    for (int j = 1; j < n; j++) {
        if (grid[0][j] != '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] != '*') {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD; // Todavía tengo que arreglar index error
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <n; j++) {
    //         cout << dp[i][j];
    //     }
    // }
    
    cout << dp[n - 1][n - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}