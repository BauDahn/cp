#include <bits/stdc++.h>
using namespace std;

// La idea es hacer dp[estudio][dia][estudio_serio] = procrastinación acumulada
// dp[estudio][dia][estudio_serio] = max(dp[estudio][dia][estudio_serio], )

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<int> e(n);
    for (int i = 0; i < n; i++) cin >> e[i];

    vector<vector<vector<int>>> dp(2, vector<vector<int>> (x + 1, vector<int> (n + 1, -1)));
    dp[0][0][0] = 0;

    for (int dias = 0; dias < n; dias++) {
        for (int cantidad_estudio = 0; cantidad_estudio <= x; cantidad_estudio++) {
            for (int dia_focus = 0; dia_focus < 2; dia_focus++) {
                // Tengo tres opciones
                // No estudio, Estudio un poco, Estudio a full
                // No estudio

                // Caso base: No se puede llegar al estado dp actual
                if (dp[dia_focus][cantidad_estudio][dias] == -1) continue;

                int actual = dp[dia_focus][cantidad_estudio][dias];

                // No estudio
                dp[dia_focus][cantidad_estudio][dias + 1] = max(actual + p[dias], dp[dia_focus][cantidad_estudio][dias + 1]);

                // Estudio un poco
                int estudio = e[dias] / 2;
                int procrastinacion = (p[dias] + 1) / 2;
                int un_poco = min(x, cantidad_estudio + estudio);
                dp[dia_focus][un_poco][dias + 1] = max(actual + procrastinacion, dp[dia_focus][un_poco][dias + 1]);

                // Estudio a full
                if (!dia_focus) {
                    int focus = min(x, cantidad_estudio + e[dias]);
                    dp[dia_focus + 1][focus][dias + 1] = max(dp[dia_focus + 1][focus][dias + 1], actual);
                }

            }
        }
    }

    int res = max(dp[0][x][n], dp[1][x][n]);

    if (res == -1) {
        cout << "SUSPENSO" << '\n';
    }
    else {
        cout << res << '\n';
    }

    return 0;
}