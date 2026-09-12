#include <bits/stdc++.h>
using namespace std;

// dp[k][i][j] = De cuántas formas llego a la celda (i, j) en k movimientos.
// Transición del dp:2
// dp[k][i][j] = dp[k - 1][i - 1][j] + dp[k - 1][i][j - 1] + dp[k - 1][i + 1][j] + dp[k - 1][i][j + 1]
// Habría que comprobar límites en todo momento
// Luego la solución es dp[k][i][j] / dp[k][todas_las_i][todas_las_j]

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;




    return 0;
}