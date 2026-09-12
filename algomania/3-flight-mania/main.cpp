#include <bits/stdc++.h>
using namespace std;

// Primero voy a mapear los nombres a ints para usarlos como índices de una lista de adyacencia
// Danimania racista, el problema es ver cuantas aristas fatan para que el grafo sea conexo

// Mierda de k o s a j a r u (Es mi primera vez haciéndolo)
void dfs1(int u, const vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (int v: adj[u]) {
        if (!visited[v]) {
            dfs1(v, adj, visited, st);
        }
    }
    st.push(u);
}

void dfs2(int u, const vector<vector<int>>& adjT, vector<bool>& visited, int component_id, vector<int>& scc_map) {
    visited[u] = true;
    scc_map[u] = component_id;
    for (int v : adjT[u]) {
        if (!visited[v]) {
            dfs2(v, adjT, visited, component_id, scc_map);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m && (n || m)) {
        unordered_map<string, int> nombres;
        for (int i = 0; i < n; i++) {
            string a;
            cin >> a;
            nombres[a] = i;
        } // Así metería los nombres mapeados

        // Ahora hay que crear las rutas
        vector<vector<int>> adj(n);
        vector<vector<int>> adjT(n);

        for (int i = 0; i < m; i++) {
            string u_str, arrow, v_str;
            cin >> u_str >> arrow >> v_str;
            int u = nombres[u_str];
            int v = nombres[v_str];
            adj[u].push_back(v);
            adjT[v].push_back(u);
        }

        // Ahora hago el kosajaru
        vector<bool> visited(n, false);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs1(i, adj, visited, st);
            }
        }
        
        // Kosajaru en el traspuesto
        fill(visited.begin(), visited.end(), false);
        vector<int> scc_map(n, -1);
        int num_scc = 0;

        while (!st.empty()) {
            int u = st.top();
            st.pop();
            if (!visited[u]) {
                dfs2(u, adjT, visited, num_scc, scc_map);
                num_scc++;
            }
        }

        if (num_scc == 1) {
            cout << 0 << '\n';
            continue;
        }

        // Construcción del grafo condensado y medida de los grados
        vector<int> in_degree(num_scc, 0);
        vector<int> out_degree(num_scc, 0);

        for (int u = 0; u < n; u++) {
            for (int v: adj[u]) {
                int scc_u = scc_map[u];
                int scc_v = scc_map[v];
                // Ahora voy a ver si pertenencen a componentes distintas, que significa que hay una arista entre supernodos
                if (scc_u != scc_v) {
                    out_degree[scc_u]++;
                    in_degree[scc_v]++;
                }
            }
        }

        // Ahora tengo que contar fuentes y sumideros del grafo
        int sources = 0;
        int sinks = 0;

        for (int i = 0; i < num_scc; i++) {
            if (in_degree[i] == 0) sources++;
            if (out_degree[i] == 0) sinks++;
        }

        cout << max(sources, sinks) << '\n';

    }
    
    return 0;
}