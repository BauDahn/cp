#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    ll k;
    cin >> n >> k;

    vector<long> energias(n);
    for (int i = 0; i < n; i++) {
        cin >> energias[i];
    }

    int maximo = 0;
    int i = 0;
    ll suma = 0;

    for (int j = 0; j < n; j++) {
        suma += energias[j];

        while (suma > k) {
            suma -= energias[i];
            i++;
        }

        maximo = max(maximo, j - i + 1);
    }
    cout << maximo << '\n';
    
    return 0;
}