#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    int num;
    int suma = 0;

    for(int i = 0; i <n; i++) {
        cin >> num;
        suma += num;
    }

    cout << suma << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        } 
        solve(n);
    }

    return 0;
}