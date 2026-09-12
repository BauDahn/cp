#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
int dp[1005][1005];


void precalculo() {
    for (int i = 0; i <= 1000; i++) {
        dp[i][0] = 1; // Este es el caso de todos los bits a 0
    }

    for (int n = 1; n <= 1000; n++) {
        for (int k = 1; k <= n; k++) {
            dp[n][k] = (dp[n-1][k-1] + dp[n-1][k]) % MOD;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precalculo();
    
    int n, k;
    while (cin >> n >> k && (n || k)) {
        // El problema en verdad es de combinatoria
        if (k > n) {
            cout << 0 << '\n';
        }
        else {
            cout << dp[n][k] << '\n';
        }

    }

    return 0;
}