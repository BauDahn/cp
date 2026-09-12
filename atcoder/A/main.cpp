#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    int suma = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (i >= (n / 2)) {
            suma += a;
        }
    }
    cout << suma << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}