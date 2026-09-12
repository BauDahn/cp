#include <bits/stdc++.h>
using namespace std;

const vector<vector<int>> movimientos_validos = {
    {},
    {2, 3, 4, 7},
    {1, 3, 5, 8},
    {1, 2, 6, 9},
    {1, 5, 6, 7},
    {4, 6, 2, 8},
    {4, 5, 3, 9},
    {1, 4, 8, 9},
    {7, 9, 5, 2},
    {7, 8, 3, 6}
};

bool dfs(int suma, int ultimo_elegido, vector<vector<int>> &memo) {
    if (suma >= 31) return true;

    if (memo[suma][ultimo_elegido] != -1) return memo[suma][ultimo_elegido]; 

    for (int digito : movimientos_validos[ultimo_elegido]) {
        if (!dfs(suma + digito, digito, memo)) {
            memo[suma][ultimo_elegido] = 1;
            return true;
        }
    }
    memo[suma][ultimo_elegido] = 0;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        vector<vector<int>> memo(35, vector<int> (10, -1));
        int suma, digito;
        cin >> suma >> digito;
        if (dfs(suma, digito, memo)) cout << "GANA" << '\n';
        else cout << "PIERDE" << '\n';
    }

    return 0;
}