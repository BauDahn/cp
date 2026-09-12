#include <bits/stdc++.h>
using namespace std;

const double INF = 1e18;

struct Vecino {
    int destino;
    double peso;
};

struct Estado {
    double distancia;
    int nodo;
    bool operator>(const Estado& o) const {
        return distancia > o.distancia;
    }
};

vector<double> dijkstra(int origen, int n, const vector<vector<Vecino>>& adj) {
    vector<double> dist(n, INF);
    priority_queue<Estado, vector<Estado>, greater<Estado>> pq;

    dist[origen] = 0;
    pq.push({0.0, origen});

    while (!pq.empty()) {
        Estado actual = pq.top();
        pq.pop();

        int u = actual.nodo;
        double d = actual.distancia;

        if (d > dist[u]) continue;

        for (const Vecino& arista : adj[u]) {
            int v = arista.destino;
            double w = arista.peso;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    double d;
    string casaTomas, casaDanimania;

    cin >> n >> m >> d;
    cin >> casaTomas >> casaDanimania;
    
    map<string, int> nombre_a_id;
    vector<string> id_a_nombre(n);

    for (int i = 0; i < n; i++) {
        string lugar;
        cin >> lugar;

        nombre_a_id[lugar] = i;
        id_a_nombre[i] = lugar;
    }

    vector<vector<Vecino>> adj(n);
    for (int i = 0; i < m; i++) {
        string u_name, v_name;
        double peso;
        cin >> u_name >> v_name >> peso;
        int u = nombre_a_id[u_name];
        int v = nombre_a_id[v_name];
        adj[u].push_back({v, peso});
        adj[v].push_back({u, peso});
    }

    vector<double> distTomas = dijkstra(nombre_a_id[casaTomas], n, adj);
    vector<double> distDanimania = dijkstra(nombre_a_id[casaDanimania], n, adj);

    vector<string> resultados;

    for (int i = 0; i < n; i++) {
        if (distTomas[i] != INF && distDanimania[i] != INF) {

            if (abs(distTomas[i] - distDanimania[i]) <= d + 1e-7) {
                resultados.push_back(id_a_nombre[i]);
            }
        }
    }

    sort(resultados.begin(), resultados.end());

    cout << resultados.size() << '\n';
    for (const string& nombre : resultados) {
        cout << nombre << '\n';
    }

    return 0;
}