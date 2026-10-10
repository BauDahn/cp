#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // La idea es encontrar la longitud de la ventana de A desarreglada más larga y ver si es menor que k
    int inicio = -1;
    int fin = -1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            inicio = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < a[i - 1]) {
            fin = i;
            break;
        }
    }

    if (inicio == fin) {
        if (k >= 2) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        return;
    }

    if (fin - inicio + 1 <= k) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}