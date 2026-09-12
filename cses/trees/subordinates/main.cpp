#include <bits/stdc++.h>
using namespace std;

void dfs(int u, const vector<vector<int>>& adj, vector<int>& sub) {
    sub[u] = 0;

    for (int v : adj[u]) {
        dfs(v, adj, sub);

        sub[u] += sub[v] + 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> sub(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i); // El empleado i es subordinado de p.
    }

    dfs(1, adj, sub);

    for (int i = 1; i <= n; i++) {
        cout << sub[i] << (i == n ? "" : " ");
    }
    cout << '\n';

    return 0;
}