#include <bits/stdc++.h>
using namespace std;

// Subcadena común más larga entre s y su reverso
// No es lo mismo que subsecuencia común máxima

// Muy interesante el problema :)
// Binary search y hashing de strings ! brillant move

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    string r = s;
    reverse(s.begin(), s.end());

    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == r[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][n] << '\n';


    return 0;
}