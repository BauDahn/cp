#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<string> palabras;
    string palabra;
    while (cin >> palabra) {
        palabras.push_back(palabra);
    }

    sort(palabras.begin(), palabras.end());

    for (string palabra : palabras) {
        cout << palabra << (palabra == palabras[palabras.size() - 1] ? "" : " ");
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}