#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n1, n2;
        long long m;
        cin >> n1 >> n2 >> m;

        int caras = 0;
        int n = n1 + n2;
        
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            if (c == 'C') caras++;
        }

        int paridad_esperada = (n1 + m) % 2;

        if (caras % 2 == paridad_esperada) {
            cout << "X\n";
        } else {
            cout << "C\n";
        }
    }

    return 0;
}