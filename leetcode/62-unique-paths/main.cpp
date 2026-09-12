#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    if (!(cin >> m) || !(cin >> n)) return;

    vector<vector<ll>> dp(m + 1, vector<ll> (n + 1, 0));
    dp[0][1] = 1;
    dp[1][0] = 1;
    // dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    cout << dp[m][n] / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}