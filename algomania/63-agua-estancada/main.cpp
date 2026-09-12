#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> alturas(n);
    for (int i = 0; i < n; i++) cin >> alturas[i];

    // La idea según el gordo de danimania es hacer dos arrays con mayores de la derecha y de la izquierda.
    vector<int> mayores_derecha(n, 0);
    vector<int> mayores_izquierda(n, 0);

    mayores_izquierda[0] = alturas[0];
    for (int i = 1; i < n; i++) {
        mayores_izquierda[i] = max(mayores_izquierda[i - 1], alturas[i]);
    }
    mayores_derecha[n - 1] = alturas[n - 1]; // Por propósitos de aura
    for (int i = n - 2; i >= 0; i--) {
        mayores_derecha[i] = max(mayores_derecha[i + 1], alturas[i]);
    }

    // Ahora si que está todo MUY rico para hacer un bucle O(N)
    long long agua_estancada = 0; // Es la suma total

    for (int i = 0; i < n; i++) {
        agua_estancada += min(mayores_izquierda[i], mayores_derecha[i]) - alturas[i];
    }
    
    cout << agua_estancada << '\n';

    return 0;
}