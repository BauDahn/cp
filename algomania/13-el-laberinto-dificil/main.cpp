#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> laberinto;

    string linea;
    while (getline(cin, linea)) {
        laberinto.push_back(linea);
    }

    int n = laberinto.size();
    int m = (n > 0) ? laberinto[0].size() : 0;

    vector<pair<int, int>> puertas;
    for (int j = 0; j < m; j++) {
        if (laberinto[0][j] == ' ') puertas.push_back({0, j});
        if (n > 1 && laberinto[n - 1][j] == ' ') puertas.push_back({n - 1, j});
    }

    for (int i = 0; i < n; i++) {
        if (laberinto[i][0] == ' ') puertas.push_back({i, 0});
        if (m > 1 && laberinto[i][m - 1] == ' ') puertas.push_back({i, m - 1});
    }

    pair<int, int> inicio = puertas[0];
    pair<int, int> fin = puertas[1];

    queue<pair<int, int>> cola;
    cola.push(inicio);

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[inicio.first][inicio.second] = true;

    vector<vector<pair<int, int>>> padres(n, vector<pair<int, int>>(m, {-1, -1}));

    const int df[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, 1, -1};

    while (!cola.empty()) {
        auto [f, c] = cola.front(); cola.pop();
        
        if (f == fin.first && c == fin.second) break;

        for (int i = 0; i < 4; i++) {
            int vf = f + df[i];
            int vc = c + dc[i];

            if (vf >= 0 && vf < n && vc >= 0 && vc < m) {
                if (laberinto[vf][vc] == ' ' && !visited[vf][vc]) {

                    visited[vf][vc] = true;
                    padres[vf][vc] = {f, c};
                    cola.push({vf, vc});
                }
            }
        }
    }

    pair<int, int> actual = padres[fin.first][fin.second];
    while (actual != inicio) {
        laberinto[actual.first][actual.second] = '.';
        actual = padres[actual.first][actual.second];
    }

    laberinto[inicio.first][inicio.second] = '.';
    laberinto[fin.first][fin.second] = '.';

    for (int i = 0; i < n; i++) {
        cout << laberinto[i] << '\n';
    }

    return 0;
}