#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n) || !(cin >> m)) return;

    int porcion = m / n; // Esto es lo que les toca de base a cada uno
    int resto = m % n;
    vector<int> p(n, 0);
    for (int i = 0; i < resto; i++) {
        p[i]++;
    }
    for (int i = 0; i < n; i++) {
        p[i] += porcion;
    }

    for (int i : p) {
        cout << i << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}