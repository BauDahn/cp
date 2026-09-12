#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> w(n);
    int peso_total = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        peso_total += w[i];
    }

    int k = n / 2;
    int limite_objetivo = peso_total / 2;

    vector<vector<bool>> dp(k + 1, vector<bool>(limite_objetivo + 1, false));
    dp[0][0] = true;

    for (int weight : w) {
        // Recorrido de mayor a menor para reutilizar dp
        for (int c = k; c >= 1; --c) {
            for (int j = limite_objetivo; j >= weight; --j) {
                if (dp[c - 1][j - weight]) {
                    dp[c][j] = true;
                }
            }
        }
    }

    int mejor_subgrupo = 0;
    for (int j = limite_objetivo; j >= 0; --j) {
        if (dp[k][j]) {
            mejor_subgrupo = j;
            break;
        }
    }

    int w1 = mejor_subgrupo;
    int w2 = peso_total - w1;

    cout << min(w1, w2) << " " << max(w1, w2) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    if (cin >> t) {
        bool primero = true;
        while (t--) {
            if (!primero) cout << "\n";
            solve();
            primero = false;
        }
    }

    return 0;
}