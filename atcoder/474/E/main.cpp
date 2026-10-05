#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    ll minimo = INT_MAX;

    vector<ll> diff(n);
    ll base = 0;

    for (int i = 0; i < n; i++) {
        ll primero, segundo;
        cin >> primero >> segundo;

        base += primero;

        minimo = min(minimo, primero);
        diff[i] = segundo - primero;
    }

    sort(diff.begin(), diff.end());

    ll coste = base;
    ll actual = base;

    for (int i = 1; i < n + 1; i++) {
        actual += diff[i - 1];
        coste = min(coste, actual + max(0, 2 * i - n) * minimo);
    }
    cout << coste << '\n';
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