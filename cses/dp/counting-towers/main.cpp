#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const int maxn = 1e6;

/*
Está claro que hay una transición entre los dp, la torre de 6 se construye a partir de la de 5 y así
dp[0] = 0;
dp[1] = 2; -> Una con uno de dos, y otra con dos de uno
dp[2] = 8; -> Tengo la opción de que sean de uno o de dos
*/

ll A[maxn + 1];
ll B[maxn + 1];

void precalculate() {
    A[1] = 1;
    B[1] = 1;
    
    for (int i = 2; i <= maxn; i++) {
        A[i] = (4 * A[i - 1] + B[i - 1]) % MOD;
        B[i] = (A[i - 1] + 2 * B[i - 1]) % MOD;
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    cout << (A[n] + B[n]) % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precalculate();
    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        solve();
    }

    return 0;
}