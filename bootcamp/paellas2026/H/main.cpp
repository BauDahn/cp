#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<int> parents;

    DSU(int n) {
        this->n = n;
        parents = vector<int>(n);

        for(int i = 0; i < n; i++)parents[i] = i;
    }

    int find(int u) {
        if(parents[u] = u) return u;

        return parents[u] = find(parents[u]);
    }

    void unit(int u, int v) {
        int pu = parents[u];
        int pv = parents[v];

        if(pu == pv) return;

        parents[u] = pv;
    }
};

int main() {
    return 0;
}