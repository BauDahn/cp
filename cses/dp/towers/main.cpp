#include <bits/stdc++.h>
using namespace std;

int lnds(vector<int>& arr) {
    vector<int> tails;

    for (int x : arr) {
        auto it = upper_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) {
            tails.push_back(x);
        } else {
            *it = x;
        }
    }

    return tails.size();
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> sizes(n);
    for (int i = 0; i < n; i++) cin >> sizes[i];

    int k = lnds(sizes);

    cout << k << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}