#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int n) {
    unordered_map<int, int> freq;
    freq[1] = 0;
    freq[10] = 0;
    freq[100] = 0;

    vector<int> monedas = {1, 10, 100};

    for (int j = 0; j < n ; j++) {
        int q;
        cin >> q;

        if (q % 1000 == 0) continue;

        ll resto = 1000 - (q % 1000);

        int i = 2;
        while (resto != 0) {
            freq[monedas[i]] += (resto / monedas[i]);
            resto %= monedas[i];
            i--;
        }
    }
    
    cout << freq[1] << ' ' << freq[10] << ' ' << freq[100] << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    solve(n);

    return 0;
}