#include <bits/stdc++.h>
using namespace std;

// Tengo que procesar una consulta del tipo [L, R] y decir si entre [s[L], s[R]] está t.
// La idea es hacer un segTree para las consultas? Tiene sentido? Ocuparía mucho. Tiene que haber otra forma
// Se pueden marcar las zonas donde hay substring t en s en un vector de pares.
// Luego tengo que hacer una busqueda binaria con L y R

void solve() {
    int q;
    cin >> q;
    string s, t;
    cin >> s >> t;

    vector<int> inicios;
    int n = s.size(), m = t.size();
    for (int i = 0; i <= n - m; i++) {
        if (s.compare(i, m, t) == 0) {
            inicios.push_back(i + 1);
        }
    }

    while (q--) {
        int left, right;
        cin >> left >> right;

        if (right - left + 1 < m || inicios.empty()) {
            cout << "No\n"; // Es imposible en este caso
            continue;
        }

        auto it = lower_bound(inicios.begin(), inicios.end(), left);

        if (it != inicios.end() && (*it) + m - 1 <= right) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}