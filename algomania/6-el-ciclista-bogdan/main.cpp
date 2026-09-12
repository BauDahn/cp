#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Vecino {
    int destino;
    ll peso;
};

struct Estado {
    ll distancia;
    int nodo;
    
    bool operator>(const Estado& o) const {
        return distancia > o.distancia;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<Vecino>> adj(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v;
            ll c;
            cin >> u >> v >> c;
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }
        
        vector<ll> distancia(n + 1, INF);
        vector<ll> formas(n + 1, 0);
        // Una vez creada la lista de adyacencia hay que hacer dijkstra sobre el grafo. Para ello necesitamos un heap
        priority_queue<Estado, vector<Estado>, greater<Estado>> pq;

        distancia[1] = 0;
        formas[1] = 1;
        pq.push({0, 1});

        while (!pq.empty()) {
            Estado actual = pq.top();
            pq.pop();

            int u = actual.nodo;
            ll d = actual.distancia;

            if (d > distancia[u]) continue; // Ya hay un camino mejor

            for (const Vecino& arista : adj[u]) {
                int v = arista.destino;
                ll w = arista.peso;

                if (distancia[u] + w < distancia[v]) {
                    distancia[v] = distancia[u] + w;
                    formas[v] = formas[u];
                    pq.push({distancia[v], v});
                }

                else if (distancia[u] + w == distancia[v]) {
                    formas[v] += formas[u];
                }
            }
        }

        cout << formas[n] << '\n';

    }

    return 0;
}