#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = INT_MIN;
    int maximo = INT_MIN;
    for (int i = 1; i < n; i++) {
        maximo = max(maximo, a[i - 1]);
        ans = max(ans, maximo - a[i]);
    }

    cout << ans << '\n';

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