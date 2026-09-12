#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

// Se hace con dp
// Cuáles son los estados del dp?
// dp[n][v] = número de arrays posibles con n elementos y valor v del último elemento
// dp[n][v] = (dp[i - 1][v - 1] + dp[i - 1][v], dp[i][v + 1])

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];


    vector<vector<int>> dp(n, vector<int> (m + 1, 0));

    // Caso base del dp
    if (nums[0] != 0) {
        dp[0][nums[0]] = 1; // Si ya tiene un valor solo ese estado es válido
    } else { // Si no tiene un valor
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1; // Si es 0, puede ser cualquier número
        }
    }
    

    for (int i = 1; i < n; i++) {
        if (nums[i] != 0) {
            int v = nums[i];

            ll sum = dp[i - 1][v];
            if (v - 1 >= 1) sum = (sum + dp[i - 1][v - 1]) % MOD;
            if (v + 1 <= m) sum = (sum + dp[i - 1][v + 1]) % MOD;

            dp[i][v] = sum;
        } else {
            for (int v = 1; v <= m; v++) {
                ll sum = dp[i - 1][v];

                if (v - 1 >= 1) sum = (sum + dp[i - 1][v - 1]) % MOD;
                if (v + 1 <= m) sum = (sum + dp[i - 1][v + 1]) % MOD;
                
                dp[i][v] = sum;
            }
        }
    }
    ll res = 0;
    for (int j = 1; j <= m; j++) {
        res = (res + dp[n - 1][j]) % MOD;
    }

    cout << res << '\n';

    return 0;
}