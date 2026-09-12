#include <bits/stdc++.h>
using namespace std;

vector<string> dp(41);

string siguiente_paso(const string& s) {
    string resultado = "";
    int i = 0;
    int n = s.size();

    while (i < n) {
        int count = 1;
        while (i + 1 < n && s[i] == s[i + 1]) {
            count++;
            i++;
        }

        resultado += to_string(count) + s[i];
        i++;
    }

    return resultado;
}

void precalculo() {
    int max = 40;

    dp[1] = "1";

    for (int i = 2; i <= max; i++) {
        dp[i] = siguiente_paso(dp[i - 1]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precalculo();

    int n;
    while (cin >> n) {
        cout << dp[n] << '\n';
    }

    return 0;
}