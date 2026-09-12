#include <bits/stdc++.h>
using namespace std;

vector<int> criba(int n) {
    vector<bool> vistos(n, false);
    for (int i = 2; i * i < n; i++) {
        if (!vistos[i]) {
            // Este es un primo
            int j = i*i;
            while (j < n) {
                vistos[j] = true;
                j += i;
            }
        }
    }
    vector<int> primos;
    for (int i = 2; i < n; i++) {
        if (!vistos[i]) {
            primos.push_back(i);
        }
    }

    return primos;
}

vector<vector<int>> formas(int n_max, int k_max, vector<int> primos) {
    vector<vector<int>> dp(k_max + 1, vector<int>(n_max + 1, 0));
    dp[0][0] = 1;
    for (int primo : primos) {
        if (primo > 1120) break;

        for (int i = 14; i >= 1; i--) {

            for (int j = 1120; j >= primo; j--) {
                dp[i][j] = dp[i][j] + dp[i - 1][j - primo];
            }
        }
    }

    return dp;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> primos = criba(1121);

    int n_max = 1120;
    int k_max = 14;

    vector<vector<int>> dp = formas(n_max, k_max, primos);

    int n, k;
    while (cin >> n >> k && (n || k)) {
        cout << dp[k][n] << endl;
    }

    return 0;
}