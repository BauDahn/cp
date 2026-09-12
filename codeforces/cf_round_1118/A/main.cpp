#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << gcd(nums[0], nums[n - 1]) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}