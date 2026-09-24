#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<unordered_map<int, int>> freq(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            int num;
            cin >> num;
            freq[i][num]++;
        }
    }

    /*
    Vamos a organizarnos bien:
    freq = [{4: algo}, {4: algo}, {4: algo}] Esta es la estructura de datos que tengo
    Lo que quiero que haga es lo siguiente:
    
    
    */
    double suma = 0;
    suma += freq[0][4] * freq[1][5] * freq[2][6] +
            freq[0][4] * freq[1][6] * freq[2][5] +
            freq[0][5] * freq[1][6] * freq[2][4] +
            freq[0][5] * freq[1][4] * freq[2][6] +
            freq[0][6] * freq[1][4] * freq[2][5] +
            freq[0][6] * freq[1][5] * freq[2][4]; 
    cout << suma / (36 * 6) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}