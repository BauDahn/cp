#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    vector<int> dp(n); // dp[i] = coste mínimo para llegar a i
    /*
    Necesitamos un dp minimal
    La transición va a ser:
    dp[0] = h[0] La rana esta parada en el 0 desde el principio
    dp[1] = abs(h[1] - h[0]);
    dp[2] = min(abs(dp[1] - h[2]), abs(dp[0] - h[2]))
    */
   dp[0] = h[0];
   dp[1] = abs(h[1] - h[0]);
   for (int i = 2; i < n; i++) {
    dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), abs(h[i] - h[i - 2]) + ((i == 2) ? 0 : dp[i - 2]));

   }
   cout << dp[n - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}