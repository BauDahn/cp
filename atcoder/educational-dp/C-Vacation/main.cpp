#include <bits/stdc++.h>
using namespace std;

struct Dia {
    int a, b, c;
};

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<Dia> d(n);
    for (int i = 0; i < n; i++) cin >> d[i].a >> d[i].b >> d[i].c;

    /*
    Podemos hacer un dp[i][j], con i siendo el día, y j la actividad elegida el i-ésimo día
    dp[i][j] = max(dp[i - 1][abs(j - 1)], dp[i - 1][abs(j - 2)]);
    */

    vector<vector<int>> dp(n, vector<int> (3, INT_MIN));

    dp[0][0] = d[0].a;
    dp[0][1] = d[0].b;
    dp[0][2] = d[0].c;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                dp[i][j] = max(dp[i - 1][2], dp[i - 1][1]) + d[i].a;
            } else if (j == 1) {
                dp[i][j] = max(dp[i - 1][2], dp[i - 1][0]) + d[i].b;
            } else {
                dp[i][j] = max(dp[i - 1][0], dp[i - 1][1]) + d[i].c;
            }
        }
    }
    int maximo = max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    cout << maximo << '\n';
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}