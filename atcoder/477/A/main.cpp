#include <bits/stdc++.h>
using namespace std;

unordered_map<char, char> m = {{'B', 'Y'}, {'Y', 'R'}, {'R', 'B'}};

void solve() {
    char c;
    if (!(cin >> c)) return;

    cout << m[c] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}