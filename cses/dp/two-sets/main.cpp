#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int suma = n * (1 + n) / 2;

    if (suma & 1) {
        cout << 0 << '\n';
        return;
    }        

    int objetivo = suma / 2;

    vector<int> dp(objetivo + 1, 0);
    dp[0] = 1; // Hay 1 forma de sumar 0

    for (int i = 1; i < n; i++) {
        for (int j = objetivo; j >= i; --j) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }
    cout << dp[objetivo] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}