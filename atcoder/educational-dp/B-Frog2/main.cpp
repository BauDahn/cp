#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n) || !(cin >> k)) return;

    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    vector<int> dp(n, INT_MAX);

    // dp[0] = h[0] porque es el caso base, para llegar al primero necesito subir hasta ahí
    dp[0] = 0;

    if (k > n) k = n;

    // La primera pasada es hasta k
    for (int i = 1; i < k; i++) {
        dp[i] = abs(h[i] - h[0]);
    }

    // Ahora como puedo ir saltando de a k tengo que hcer el for desde k moviéndome en las k posibles
    for (int i = k; i < n; i++) {
        int minimo = INT_MAX;
        int idx = 0;
        for (int j = 1; j < k + 1; j++) {
            //cout << "Índice: " << i - j << " corresponde a: " << dp[i - j] << " con valor abs = " << abs(h[i - j] - h[i]) << " y una suma de: " << dp[i - j] + abs(h[i - j] - h[i]) << '\n';
            if (minimo > dp[i - j] + abs(h[i - j] - h[i])) {
                idx = i - j;
                minimo = dp[i - j] + abs(h[i - j] - h[i]);
            }
            //cout << "El minimo es " << minimo << " corresponiente al indice " << idx << '\n';
        }
        //cout << "El mejor índice para saltar es el " << idx << '\n';
        dp[i] = minimo;
        //cout << "Conseguimos un valor de dp de " << dp[i] << " para el índice " << i << '\n';
    }
    //for (int i = 0; i < n; i++) cout << dp[i] << ' ';

    //cout << '\n';
    cout << dp[n - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}