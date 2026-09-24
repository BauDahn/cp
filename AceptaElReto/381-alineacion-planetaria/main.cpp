#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b) {
    return (a*b) / __gcd(a, b);
}

void solve(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = lcm(ans, a[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while (cin >> n) {
        if (n == 0) break;
        solve(n);
    }

    return 0;
}