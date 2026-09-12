#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    if (!(cin >> n) || !(cin >> x)) return;

    vector<int> precios(n), paginas(n);
    for (int i = 0; i < n; i++) cin >> precios[i];
    for (int i = 0; i < n; i++) cin >> paginas[i];

    // dp[presupuesto] = máxima cantidad de hojas con ese presupuesto
    // dp[x] = max(dp[x], dp[x - precio] + páginas) || Esa es la transición de estado
    // Además, el dp debe ser de derecha a izquierda (empiezo por el maximo presupuesto)

    vector<int> dp(x + 1, 0);
    
    for (int i = 0; i < n; i++) {
        int precio = precios[i];
        int pagina = paginas[i];
        for (int j = x; j >= precio; j--) {
            dp[j] = max(dp[j], dp[j - precio] + pagina);
        }
    }

    cout << dp[x] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}