#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, x;
    if (!(cin >> n) || !(cin >> x)) return;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    // dp[x] = formas de llegar a la cantidad de dinero x
    // dp[x] = dp[x - coin]
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= x; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }

    cout << dp[x] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}