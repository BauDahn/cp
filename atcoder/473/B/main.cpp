#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    unordered_map<int, int> a;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        a[c]++;
    }
    int suma = 0;
    for (const pair<int, int> &f: a) {
        if (f.second & 1) suma += f.first;
    }

    cout << suma << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}