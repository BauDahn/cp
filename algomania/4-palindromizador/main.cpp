#include <bits/stdc++.h>
using namespace std;

// Hay que manejar el input de mierda primero
// Despues para hacer la subsecuencia palindromica mas larga hay que hacer DP. QUE VIVA EL DP
// DPDPDPDPDPDPDPDPD   Es un palindromo xd (creo)
// MODO OSCURO

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    string penemania;
    getline(cin, penemania);
    while (t--) {
        string s;
        getline(cin, s);

        string clean_s = "";
        vector<int> indice_original;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                clean_s += tolower(s[i]);
                indice_original.push_back(i);
            }
        }

        int n = clean_s.length();
        if (n == 0) {
            cout << "" << "\n";
            continue;
        }

        // DP IUPIIIIIII
        vector<vector<bool>> dp(n, vector<bool> (n, false));

        int max_len = 0;
        string mejor = "";

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (len == 1) {
                    dp[i][j] = true;
                } else if (len == 2) {
                    dp[i][j] = (clean_s[i] == clean_s[j]);
                } else {
                    dp[i][j] = (clean_s[i] == clean_s[j] && dp[i + 1][j - 1]);
                }

                // En caso de tener un palindromo valido
                if (dp[i][j]) {
                    int inicio = indice_original[i];
                    int final = indice_original[j];
                    string candidato = s.substr(inicio, final - inicio + 1);

                    if (len > max_len) {
                        max_len = len;
                        mejor = candidato;
                    }
                    // Ojo, en el caso de haber empate me tengo que quedar con el menor lexicograficamente
                    else if (len == max_len) {
                        if (candidato < mejor) {
                            mejor = candidato;
                        }
                    }
                }
            }
        }

        cout << mejor << '\n';
    }




    return 0;
}