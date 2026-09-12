#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n) || !(cin >> k)) return;

    unordered_map<int, int> freq;
    freq[1] = 0;
    int mas_frecuente = 1;
    for (int i = c; i < n; i++) {
        int a;
        cin >> a;
        freq[a]++;
        if (freq[mas_frecuente] < freq[a]) {
            mas_frecuente = a;
        }
    }

    // Una vez tenemos el más frecuente, solo hay que recorrer el mapa
    int cont = 0;
    for (const pair<int, int> &f: freq) {
        if (f.second >= freq[mas_frecuente] - 1) cont++;
    }
    cout << cont << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}