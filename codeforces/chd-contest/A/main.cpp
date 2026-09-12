#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> subtree_size;
vector<int> depth;
vector<int> raiz_hijo_ancestro;

void dfs(int u, int p, int d, int actual) {
    depth[u] = d;
    subtree_size[u] = 1;
    raiz_hijo_ancestro[u] = actual;

    for (int v : adj[u]) {
        if (v != p) {
            int siguiente = (u == 1) ? v : actual;
            dfs(v, u, d + 1, siguiente);
            subtree_size[u] += subtree_size[v];
        }
    }
}

void solve() {
    int n;
    cin >> n;

    adj.assign(n + 1, vector<int>());
    subtree_size.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    raiz_hijo_ancestro.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (p != -1) {
            adj[p].push_back(i);
            adj[i].push_back(p);
        }
    }

    dfs(1, -1, 0, -1);
    for (int s = 2; s <= n; s++) {
        int r = raiz_hijo_ancestro[s];
        int ans = 2 * subtree_size[r] - depth[s];
        cout << ans << (s == n ? "" : " ");
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}