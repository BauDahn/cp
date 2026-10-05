#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    if (1 != n) {
        cout << 1 << '\n';
    } else if (2 != n) {
        cout << 2 << '\n';
    } else {
        cout << 3 << '\n';
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
