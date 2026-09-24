#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Array de minimos a la izquierda
    // Array de mayores a la derecha
    // Array de mayores a la izquierda
    vector<int> left_minimum(n), right_maximum(n);

    left_minimum[0] = a[0];
    for (int i = 1; i < n; i++) {
        left_minimum[i] = min(left_minimum[i - 1], a[i]);
    }

    right_maximum[n - 1] = a[n - 1]; 
    for (int i = n - 1; i > 0; i--) {
        right_maximum[i - 1] = max(right_maximum[i], a[i - 1]);
    }

    // Una vez hechos estos arrays hay que recorrer en un bucle for y terminar el problema
    for (int i = 0; i < n - 2; i++) {
        if (left_minimum[i] < a[i] && right_maximum[i] == a[i]) {
            cout << "ELEGIR OTRA\n";
            return;
        }
    }
    cout << "SIEMPRE PREMIO\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while (cin >> n) solve(n);    

    return 0;
}