#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    const long long INF = 1e18;
    vector<vector<long long>> dist(n, vector<long long>(n, INF));
    
    for(int i = 0; i < n; i++) dist[i][i] = 0;

    for(int i = 0; i < m; i++){
        int a, b; long long c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    // Floyd-Warshall
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        long long d = dist[a][b];
        cout << (d == INF ? -1 : d) << '\n';
    }

    return 0;
}