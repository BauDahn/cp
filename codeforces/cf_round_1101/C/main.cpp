#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, x, s;
        cin >> n >> x >> s;

        string u;
        cin >> u;

        vector<int> dp(x + 1, -1);
        dp[x] = 0;
        
        for (int persona = 0; persona < n; persona++) {
            char tipo_social = u[persona];

            vector<int> nueva_lista = dp;
            
            for (int vacias = 0; vacias < x + 1; vacias++) {
                int actual_sentadas = dp[vacias];
                
                if (actual_sentadas == -1) {
                    continue;
                }

                int mesas_disponibles = x - vacias;
                int asientos_libres = (mesas_disponibles * s) - actual_sentadas;

                if (tipo_social != 'I') {
                    if (asientos_libres > 0) {
                        nueva_lista[vacias] = max(nueva_lista[vacias], actual_sentadas + 1);
                    }
                }
                if (tipo_social != 'E') {
                    if (vacias > 0) {
                        nueva_lista[vacias - 1] = max(nueva_lista[vacias - 1], actual_sentadas + 1);
                    }
                }
            }
            dp = nueva_lista;

        }
        int max_personas = -1;
        for (int vacias = 0; vacias < x + 1; vacias++) {
            max_personas = max(max_personas, dp[vacias]);
        }

        cout << max_personas << '\n';
    }

    return 0;
}