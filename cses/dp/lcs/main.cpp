#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a1(n);
    vector<int> a2(m);

    for(int i = 0; i < n; i++) cin >> a1[i];
    for(int i = 0; i < m; i++) cin >> a2[i];

    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= m; j++) {
            if (a1[i - 1] == a2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    vector<int> res;
    // Cómo hacer backtracking del dp?
    // Empiezo desde el final y retrocedo
    // Si dos elementos coinciden los guardo
    int i = n;
    int j = m;
    while (i  > 0 && j > 0) {
        if (a1[i - 1] == a2[j - 1]) {
            res.push_back(a1[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) { // Camino óptimo desde arriba
            i--;
        } else {
            j--;
        }
    }
    reverse(res.begin(), res.end());

    cout << dp[n][m] << '\n';
    for (int num : res) cout << num << ' ';
    
    return 0;
}