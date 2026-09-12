#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
/*const int caras[6] = {
    1, 2, 3, 4, 5, 6
};*/

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
    int n;
    cin >> n;

    // La idea es que dp[i] = dp[i - moneda]

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    
    for (int i = 0; i <= n; i++) {
        for (int cara : caras) {
            if (i - cara >= 0) {
                dp[i] = (dp[i - cara] + dp[i]) % MOD;
            }
        }
    }

    cout << dp[n] << '\n';
    */

    solve();

    return 0;
}