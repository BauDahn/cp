#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m, n;
    if (!(cin >> m) || !(cin >> n)) return;

    // Meto los datos adentro del grid
    vector<vector<int>> grid(m + 1, vector<int> (n + 1));
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) cin >> grid[i][j];
    }

    // Creo un vector dp
    vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
    dp[0][1] = 1;
    dp[1][0] = 1;

    if (grid[0][0] == 1) {
        cout << 0 << '\n';
        return;
    }

    // La transicion es dp[i][j] = (grid[i][j] == 0) ? dp[i - 1][j] + dp[i][j - 1] : 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (grid[i][j] == 0) ? dp[i - 1][j] + dp[i][j - 1] : 0;
        }
    }

    cout << dp[m][n] / 2<< '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}