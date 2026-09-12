#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    unordered_map<int, int> dp;
    int max_len = 0;
    int last_val = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int x = a[i];

        dp[x] = dp[x - 1] + 1;
        if (dp[x] > max_len) {
            max_len = dp[x];
            last_val = x;
        }
    }

    int curr_val = last_val - max_len + 1;
    vector<int> indices;
    
    for (int i = 0; i < n; i++) {
        if (a[i] == curr_val) {
            indices.push_back(i + 1);
            curr_val++;
        }
    }

    cout << max_len << '\n';
    for (int i = 0; i < max_len; i++) {
        cout << indices[i] << (i + 1 == max_len ? "" : " ");
    }
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}