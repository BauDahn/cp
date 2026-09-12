#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n) || !(cin >> m)) return;

    vector<vector<int>> graph(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Para este problema me piden que haga un bfs 0/1.
    // Para hacer un bfs necesito una cola que almacene el nodo y el peso hasta el nodo
    queue<int> q;
    q.push(1); // Arranco desde el primer elemento

    // Para poder reconstruir la ruta vamos a hacer un vector de padres
    vector<int> parent(n + 1, -1);

    // Para ahorrar iteraciones también me haré un vector de visited
    vector<bool> visited(n + 1, false);
    visited[1] = true;

    while (!(q.empty())) { // Mientras que la cola no este vacía
        int actual = q.front();
        q.pop();
        if (actual == n) { // Significa que llegué a donde debo estar
            break;
        }
        // En el caso de no estar donde quiero estar
        for (int destino : graph[actual]) {
            if (!(visited[destino])) { // Si no ha sido visitado ya
                visited[destino] = true;
                q.push(destino);
                parent[destino] = actual;
            } // Si ha sido visitado ni lo añado, porque no sirve.
        }
    }

    if (visited[n]) {
        // Reconstrucción del camino
        // Me voy a hacer un vector que guarde el camino
        vector<int> path;
        int actual = n;
        path.push_back(actual);
    
        while (true) {
            int padre = parent[actual]; // Agarro el padre del elemento actual
            path.push_back(padre); // Lo meto en el camino
            if (padre == 1) { // Si el padre del elemento actual era el primero, termino el bucle
                break;
            }
            // Si no era el caso y hay mas padres
            actual = padre;
        }
        // Ahora voy a dar vuelta el vector
        reverse(path.begin(), path.end());

        cout << path.size() << '\n';
        for (int nodo : path) {
            cout << nodo << ' ';
        }
    } else {
        cout << "IMPOSSIBLE" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}