#include <bits/stdc++.h>
using namespace std;

struct Item {
    int w, v;
};

void solve() {
    int n, w;
    if (!(cin >> n) || !(cin >> w)) return;

    vector<Item> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i].w >> a[i].v;

    /*
    Idea para resolver el problema:
    dp[i][j] = Peso mínimo para los primeros i elementos si la mochila tiene un valor j
    Transición de la tabla dp:
    */
    vector<vector<int>> dp(n + 1, vector<int> (10001, 0));

    /*
    Importante definir bien cual va a ser el sentido de los bucles for
    Por cada peso posible quiero ver cómo voy a modificar cada día posible
    */
    for (int j = w; j >= 0; j--) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i].w >= 0) {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j - a[i].w] + a[i].v);
            }
        }
    }

   cout << dp[n][w] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}