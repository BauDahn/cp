#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int maximo_actual = 10;
    for (int i = 0; i < n; i++) {
        maximo_actual = max(maximo_actual, (i*2 / 10) * 10);
        if (nums[i] > maximo_actual) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}