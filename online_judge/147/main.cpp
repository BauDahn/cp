#include <bits/stdc++.h>
#include <iomanip>
#include <cmath>
using namespace std;

const vector<float> coins = {
    10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5
}; // Vector con las monedas que se pueden usar

const int MAX = 30005; // Cantidad máxima que me pueden pedir formar

// dp[i] = De cuantas formas puedo formar la cantidad i
// dp[i] += dp[i - coin_actual] + 1
long long dp[MAX];

void precalculate() {
    dp[0] = 1;
    for (int coin : coins) {
        for (int i = coin; i < MAX; i++) {
            if (i - coin >= 0) {
                dp[i] += dp[i - coin];
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precalculate();

    float target;
    while (cin >> target && target != 0.00) {
        int converted_target = round(target * 100);
        cout << right << fixed << setprecision(2) << setw(6) << target
         << right << setw(17) << dp[converted_target] << '\n';
    }
    
    

    return 0;
}