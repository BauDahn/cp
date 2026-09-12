#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        ll m, p, n;
        cin >> m >> p;

        cin >> n;
        vector<ll> pesos(n);
        for (int i = 0; i < n; i++) {
            cin >> pesos[i];
        }

        if (n > m) {
            cout << "No cabemos" << '\n';
            continue;
        }

        ll maximo_permitido = m * p;
        ll suma = 0;

        bool atrapados = false;

        for (int i = 0; i < n; i++) {
            suma += pesos[i];
            if (atrapados) {
                break;
            }
            if (suma > maximo_permitido) {
                cout << "Nos quedamos atrapados" << '\n';
                atrapados = true;
            }
        }
        if (!atrapados) {
            cout << "Todo bien" << '\n';
        }
    }

    return 0;
}