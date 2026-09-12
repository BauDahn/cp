#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    if (!(cin >> s) || !(cin >> t)) return;

    vector<vector<int>> dp(s.size(), vector<int> (t.size(), 0));
    // Primero voy a implementar el código para que me diga la longitud de la subsecuencia más larga
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[0]) {
            dp[i][0] = 1;
            int j = i;
            while (j < s.size()) {
                dp[j][0] = 1;
                j++;
            }
            break;
        }
    }
    for (int i = 0; i < t.size(); i++) {
        if (s[0] == t[i]) {
            dp[0][i] = 1;
            int j = i;
            while (j < t.size()) {
                dp[0][j] = 1;
                j++;
            }
            break;
        }
    }
    
    for (int i = 1; i < s.size(); i++) {
        for (int j = 1; j < t.size(); j++) {
            if (s[i] == t[j]) { // En el caso de encontrar dos que sean iguales
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1); // sumo uno
            } else {
                // En el caso de encontrar dos distintas
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }


    // Una vez tenemos la tabla dp para calcular el lcs podemos reconstruir del siguiente modo
    // Salto inverso, empiezo desde s.size() y t.size() y voy para atrás, restando de a uno.
    string res = ""; // Acá voy a almacenar el resultado

    int i = s.size() - 1;
    int j = t.size() - 1;

    while (i >= 0 && j >= 0) { // Voy a ir restando uno
        if (s[i] == t[j]) {
            res.push_back(s[i]);
            i--;
            j--;
        } else {
            int arriba = (i > 0) ? dp[i - 1][j] : 0;
            int izquierda = (j > 0) ? dp[i][j - 1] : 0;

            if (arriba > izquierda) {
                i--;
            } else {
                j--;
            }
        }
    }

    reverse(res.begin(), res.end());
    
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}