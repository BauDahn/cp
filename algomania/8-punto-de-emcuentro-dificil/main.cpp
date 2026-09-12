#include <bits/stdc++.h>
using namespace std;

// Tiene mucho olor a Floyd-Warshall
// Aplicarlo en c++ me va a dejar sin pelos (en los huevos)
// Floyd-Warshall es dp xd

const double INF = 1e18;
const double epsilon = 1e-9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    double d;
    cin >> n >> m >> d;

    unordered_map<string, int> nombres_a_id;
    vector<string> id_a_nombre(n);

    for (int i = 0; i < n; i++) {
        string nombre;
        cin >> nombre;
        id_a_nombre[i] = nombre;
        nombres_a_id[nombre] = i;
    }

    vector<vector<double>> dist(n, vector<double> (n, INF));

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0.0;
    }

    for (int i = 0; i < m; i++) {
        string u_str, v_str;
        double coste;
        cin >> u_str >> v_str >> coste;
        int u = nombres_a_id[u_str];
        int v = nombres_a_id[v_str];

        if (coste < dist[u][v]) {
            dist[u][v] = coste;
            dist[v][u] = coste;
        }
    }

    // Fraude - Warshall
    for(int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        string dani_str, tomas_str;
        cin >> dani_str >> tomas_str;

        int dani = nombres_a_id[dani_str];
        int tomas = nombres_a_id[tomas_str];

        vector<string> puntos_encuentro;

        for (int i = 0; i < n; i++) {
            if (dist[dani][i] < INF && dist[tomas][i] < INF) {
                double diferencia = abs(dist[dani][i] - dist[tomas][i]);
                
                if (diferencia <= d + epsilon) {
                    puntos_encuentro.push_back(id_a_nombre[i]);
                }
            }
        }

        sort(puntos_encuentro.begin(), puntos_encuentro.end());

        cout << puntos_encuentro.size() << '\n';
        for (string nombre : puntos_encuentro) {
            cout << nombre << '\n';
        }
    }

    return 0;
}