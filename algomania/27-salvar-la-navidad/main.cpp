#include <bits/stdc++.h>
using namespace std;

vector<int> frecuencia(const string& str) {
    vector<int> freq(26, 0);
    for (char c : str) freq[c - 'a']++;
    return freq;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string p;
    cin >> p;

    vector<int> frecuencia_buscada = frecuencia(p);
    vector<string> resultado;
    
    string s;
    while (cin >> s) {
        if (s.length() == p.length() && frecuencia(s) == frecuencia_buscada) {
            resultado.push_back(s);
        }
    }

    for (int i = 0; i < resultado.size(); i++) {
        cout << resultado[i] << (i + 1 == resultado.size() ? "" : " ");
    }
    cout << '\n';

    return 0;
}