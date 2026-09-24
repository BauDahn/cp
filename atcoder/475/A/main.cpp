#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    string t = "";
    for (int i = 0; i < n; i++) {
        t.push_back(s[i]);
        
        (i == n - 1) ? t.push_back('\n') : t.push_back('o');
    }
    
    cout << t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}