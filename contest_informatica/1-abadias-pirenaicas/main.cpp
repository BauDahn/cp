#include <bits/stdc++.h>
using namespace std;

// dp[i] = maximo de abadias hasta el pico i
// dp[i] = max()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while (cin >> n && n) {
        vector<int> alturas(n);
        for (int i = 0; i < n; i++) cin >> alturas[i];
        // Una vez metidos los datos, vamos a recorrerlos al reves
        int maximo = 1;
        int altura_maxima = alturas[n - 1];
        if (n < 2) {
            cout << 1 << '\n';
            continue;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (alturas[i] > altura_maxima) {
                altura_maxima = alturas[i];
                maximo++;
            }
        }

        cout << maximo << '\n';
    }

    return 0;
}