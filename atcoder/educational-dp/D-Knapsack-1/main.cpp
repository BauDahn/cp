#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Item {
    ll w, v;
};

void solve() {
    ll n, w;
    if (!(cin >> n) || !(cin >> w)) return;

    vector<Item> a(n + 1);
    for (ll i = 1; i <= n; i++) cin >> a[i].w >> a[i].v; 

    /*
    Es un dp de mochila 0/1
    dp[i][w] = máximo valor para ese peso.
    dp[i][w] = max(dp[i][w], dp[i - 1][w - a[i].w] + a.v);
    */

    vector<vector<ll>> dp(n + 1, vector<ll> (w + 1));
    
    for (int i = 1; i <= n; i++) {
        for (int j = w; j >= 0; j--) {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i].w >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].w] + a[i].v);
            } 
        }
    }
    
    ll maximo = 0;
    for (int i = 0; i <= w; i++) {
        maximo = max(maximo, dp[n][i]);
    }

    cout << maximo << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}