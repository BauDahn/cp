#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    vector<ull> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<ull> ans(n);
    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            encontrado = true;
            ans[i] = 1000000000000000LL;    
        } else {
            ans[i] = 1;
        }
    }
    if (encontrado) {
        cout << "Yes" << '\n';
        for (ull i : ans) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    } else {
        cout << "No" << '\n';
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}