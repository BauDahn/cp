#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    if (!(cin >> s)) return;

    string s1 = "";
    for (char c : s) {
        if (c == 'A') {
            s1.push_back(c);
        } else {
            s1.push_back('.');
        }
    }
    cout << s1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}