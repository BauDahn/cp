#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n) || !(cin >> m)) return;

    // Para solucionar el problema hay que hacer un bfs

    // Creación de la lista de adyacencia
    vector<vector<int>> nodos(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        nodos[u].push_back(v);
        in_degree[v]++;
    }
    // Ahora hay que recorrer el mapa
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    // dp[u] = longitud del camino mas largo que termina en u.
    vector<int> dp(n + 1, 0);
    int res = 0;

    while (!(q.empty())) { // Mientras la cola no esta vacía
        int u = q.front();
        q.pop();

        res = max(res, dp[u]);

        for (int v : nodos[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }

    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}