#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
dp[mask] = {número de viajes, peso en el último viaje}
*/

void solve() {
    int n;
    ll x;
    if (!(cin >> n) || !(cin >> x)) return;

    vector<ll> weights(n);
    for (int i = 0; i < n; i++) cin >> weights[i];

    vector<pair<int, ll>> dp(1 << n, {n + 1, 0});
    dp[0] = {1, 0};

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << n))) {
                auto [rides, weight] = dp[mask];

                if (weight + weights[i] <= x) {
                    // Lo puedo incluir
                    weight += weights[i];
                } else {
                    rides++;
                    weight = weights[i];
                }

                // Guardo la mejor opción
                dp[mask | (1 << i)] = min(dp[mask | (1 << i)], {rides, weight});
            }
        }
    }
    cout << dp[(1 << n) - 1].first << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}