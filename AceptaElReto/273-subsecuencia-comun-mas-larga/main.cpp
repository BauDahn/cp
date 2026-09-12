#include <bits/stdc++.h>
using namespace std;

void solve(string& s1, string& s2) {
    
    // Voy a crearme n y m por comodidad
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

    // Una vez creado el dp para hacer el lcs
    // Planteamos las transición
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) { 
                // Si son iguales entonces hay que sumar uno en este lugar
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            } else {
                // En el caso de que ahora no sean iguales
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s1, s2;
    while (cin >> s1 >> s2) {
        solve(s1, s2);
    }
    
    return 0;
}