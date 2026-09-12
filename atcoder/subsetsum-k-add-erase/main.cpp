#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void sumar(int actual, int objetivo, vector<int>& dp) {
    for (int i = objetivo; i >= actual; i--) {
        dp[i] = (dp[i] + dp[i - actual]) % MOD;
    }
}

void restar(int actual, int objetivo, vector<int>& dp) {
    for (int i = actual; i <= objetivo; i++) {
        dp[i] = (dp[i] - dp[i - actual] + MOD) % MOD; 
    }
}

void solve() {
    int q, k;
    if (!(cin >> q) || !(cin >> k)) return;

    vector<int> dp(k + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < q; i++) {
        char c;
        cin >> c;

        int actual;
        cin >> actual;

        if (c == '+') sumar(actual, k, dp);
        else restar(actual, k, dp);

        cout << dp[k] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}