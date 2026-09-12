#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int p, const vector<vector<int>>& adj, vector<vector<int>>& dp) {
    dp[u][0] = 0;
    dp[u][1] = 0;

    for (int v : adj[u]) {
        if (v == p) continue;

        dfs(v, u, adj, dp);

        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
    
    for (int v : adj[u]) {
        if (v == p) continue;

        int candidato = dp[u][0] - max(dp[v][0], dp[v][1]) + dp[v][0] + 1;
        dp[u][1] = max(dp[u][1], candidato);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> dp(n + 1, vector<int> (2, 0));

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, adj, dp);

    cout << max(dp[1][1], dp[1][0]) << '\n';

    return 0;
}