#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    int n, x;
    if (!(cin >> n) || !(cin >> x)) return;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp(x + 1, INF);
    dp[0] = 0;

    for (int coin : coins) {
        for (int i = coin; i < x + 1; i++) {
            if (dp[i - coin] + 1 < dp[i]) {
                dp[i] = dp[i - coin] + 1;
            }
        }
    }
    if (dp[x] == INF) cout << -1 << '\n';
    else cout << dp[x] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();


    return 0;
}