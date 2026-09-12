#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tiempo = 0;
    while (cin >> tiempo) {

        int n;
        cin >> n;

        vector<pair<int, int>> cofres(n);
        for (int i = 0; i < n; i++) {
            cin >> cofres[i].first >> cofres[i].second;
            cofres[i].first *= 3;
        }

        vector<vector<int>> dp(n, vector<int> (tiempo + 1));
        for (int c = 0; c < n; c++) { // Para cada cofre
            for (int t = 0; t <= tiempo; t++) {
                dp[c][t] = (c - 1 >= 0 ? dp[c - 1][t] : 0);
                
                if (t - cofres[c].first >= 0) {
                    dp[c][t] = max(dp[c][t], (c - 1 >= 0 ? dp[c - 1][t - cofres[c].first] : 0) + cofres[c].second);
                }
            }
        }
        cout << dp[n - 1][tiempo] << endl;
    }


    return 0;
}