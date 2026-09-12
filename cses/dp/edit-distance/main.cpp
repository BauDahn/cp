#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s1, s2;
    if (!(cin >> s1) || !(cin >> s2)) return;

    int n, m;
    n = s1.size();
    m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int> (m + 1));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int i = 0; i <= m; i++) dp[0][i] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min({
                dp[i - 1][j],
                dp[i][j - 1],
                dp[i - 1][j - 1]
            });
        }
    }
    cout << dp[n][m] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}