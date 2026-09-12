#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;

    int suma = 0;
    for (char c : s) {
        suma += (c - '0');
    }

    cout << suma << '\n';

    return 0;
}