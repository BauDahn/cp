#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, v;
    cin >> n >> v;

    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    vector<vector<ll>> dp(v + 1, vector<ll> (4, -1));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        ll cost = i;
        ll happy = w[i];

        for (int c = v; c >= cost; c--) {
            for (int k = 3; k >= 1; k--) {
                if (dp[c - cost][k - 1] != -1) {
                    dp[c][k] = max(dp[c][k], dp[c - cost][k - 1] + happy);
                }
            }
        }
    }

    ll ans = -1;
    for (ll c = 0; c <= v; c++) {
        ans = max(ans, dp[c][3]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}