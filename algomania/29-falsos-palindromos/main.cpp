#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    string r = s;
    reverse(r.begin(), r.end());

    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == r[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][n] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}