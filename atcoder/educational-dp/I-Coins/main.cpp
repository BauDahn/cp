#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> coins(n + 1);
    for (int i = 1; i < n; i++) cin >> coins[i];

    // dp[indice][número de caras] = probabilidad de esa cantidad de caras
    // dp[i][j] = dp[i - 1][j] + (dp[i - 1][j - 1] * coins[i]);
    vector<vector<float>> dp(n + 1, vector<float> (n + 1, 0.0));

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j != 0) {
                dp[i][j] = dp[i - 1][j] + (dp[i - 1][j - 1] * coins[i]);
            } else {
                dp[i][j] = dp[i - 1][j] * (1 - coins[i]);
            }
            cout << dp[i][j] << '\n';
        }
    }


    int suficientes = n / 2;
    cout << dp[n][suficientes] << '\n';    

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}