#include <bits/stdc++.h>
using namespace std;

// Hecho el generador, es fácil darse cuenta de que el número aumenta de a 8
// Se puede hacer n / 3 y devolver si no estoy loco

void precalc() {
    for (int i = 8; i <= pow(2, 18); i = i*2) {
        if ((i - 1) % 7 == 0) {
            cout << i << '\n';
        }
    }
}

void solve() {
    int n;
    cin >> n;

    cout << n / 3 << '\n';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}