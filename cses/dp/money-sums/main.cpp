#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int suma_max = 0;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        suma_max += coins[i];
    }

    int k = 0; // Las distintas sumas posibles que hay
    vector<int> ans; // Son todas las posibles sumas que se pueden hacer

    vector<bool> dp(suma_max + 1, false); // El vector dp tiene que tener tamaño suma max
    // Si recorro de derecha a izquierda el vector ans me va a quedar ordenado al revés
    // Me aseguro que uso cada moneda solo una vez y luego solo doy vuelta el vector.
    dp[0] = true;
    for (int coin : coins) {
        for (int i = suma_max; i >= coin; i--) {
            if (dp[i - coin]) {
                dp[i] = true;
            }
        }
    }

    for (int i = 1; i <= suma_max; i++) {
        if (dp[i]) {
            k++;
            ans.push_back(i);
        }
    }
    
    cout << k << '\n';
    for (int suma : ans) cout << suma << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}