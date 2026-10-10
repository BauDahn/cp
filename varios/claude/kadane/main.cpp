#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> best_ending(n, INT_MIN); // Almacena la mejor suma para el índice i
    int cur = 0; // Almacena el mejor local dentro del bucle (se va a ir actualizando)
    for (int i = 0; i < n; i++) {
        cur = max(a[i], cur + a[i]);
        best_ending[i] = max((i > 0 ? best_ending[i - 1] : cur), cur);
    }

    cout << best_ending[n - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}