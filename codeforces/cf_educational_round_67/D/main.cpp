#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int n) : n(n), tree(2*n, INF) {};

    void update(int p, int x) {
        for (tree[p += n] = x; p > 1; p >>= 1) {
            tree[p >> 1] = min(tree[p], tree[p ^ 1]);
        }
    }

    int query(int l, int r) {
        int res = INF;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res, tree[l++]);
            if (r & 1) res = min(res, tree[--r]);
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    vector<queue<int>> pos(n + 1);
    SegmentTree st(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push(i);
        st.update(i, a[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    bool posible = true;
    for (int i = 0; i < n; i++) {
        int val = b[i];

        if (pos[val].empty()) {
            // No existe el valor
            posible = false;
            break;
        }


        // Obtengo el índice
        int idx = pos[val].front();
        pos[val].pop();

        // Consulto si hay algún número menor que val en el rango (0, idx)
        if (st.query(0, idx) < val) {
            posible = false;
            break;
        }

        // Desactivo el elemento usado para futuras queries
        st.update(idx, INF);

    }
    if (posible) cout << "YES\n";
    else cout << "NO\n";
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