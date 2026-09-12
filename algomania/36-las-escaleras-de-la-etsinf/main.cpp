#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 10022026;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n = 2e5;
    // DPPPPP!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! DP EN UN FÁCIL !!!!!!
    vector<ll> dp(n, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}