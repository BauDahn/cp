#include <bits/stdc++.h>
using namespace std;

// Hay dos casos posibles:
// A partir del máximo encontrado:
// O la respuesta es el máximo, o la respuesta es maximo + uno.
// Si el máximo aparece dos veces en el array, la respuesta es uno + máximo

bool posible(int num, vector<int>& distancias, int n) {
    int ans = num;
    for (int i = 0; i < n; i++) {
        if (distancias[i] > ans) return false;
        if (distancias[i] == ans) ans--;
        if (ans < 0) return false; 
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    
    vector<int> nums(n + 1);
    vector<int> distancias(n);
    int maximo = 0;

    nums[0] = 0;
    for (int i = 1; i <= n; i++) cin >> nums[i];
    
    for (int i = 0; i < n; i++) {
        distancias[i] = nums[i + 1] - nums[i];
        maximo = max(maximo, distancias[i]);
    }

    if (posible(maximo, distancias, n)) {
        // Es posible con el máximo
        cout << maximo << '\n';
    } else {
        cout << maximo + 1 << '\n';
    }
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