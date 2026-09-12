#include <bits/stdc++.h>
using namespace std;

/* 
La solución óptima obliga a actualizar un índice i
actualizaremos a[i] = (a[i - 1] + 1) siempre que i > 1, 0 si i == 1.
Si tenemos una subsecuencia creciente que contiene a[i - 1] y queremos agregar
un nuevo elemento, es óptimo elegir a[i - 1] + 1.
Si actualizamos a[i] a a[i - 1] + 1, luego no podemos agarrar a[i] para una nueva subsecuencia

Podemos usar 2 segtrees. Uno before y otro after. 
before[i] = LIS que termina en i sin operaciones hechas
after[i] = LIS termiando en i con operación hecha
best[i] = Mejor reemplazamiento de a[i]

Las transiciones son las siguientes
after[a[i]] = max(after[a[i]], 1 + after[j] (j < a[i]))
after[best[i]] = max(after[best[i]], 1 + max(before[j]) (j < best[i]))
before[a[i]] = max(before[a[i]], 1 + max(before[j]) (j < a[i]))

Ahora hay que hacer un segtree de LIS
Hay que hacer coordinate compression
*/

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int n) : n(n), tree(4 * n, 0) {}

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];

        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return max(p1, p2);
    }

    void update(int idx, int val) { update(1, 0, n - 1, idx, val); }
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    map<int, int> compressed;
    vector<int> best(n, 0);
    
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> val = a;
    val.push_back(0);

    for (int i = 0; i < n - 1; i++) val.push_back(val[i] + 1);
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    for (int i = 0; i < val.size(); i++) compressed[val[i]] = i;

    for (int i = 1; i < n; i++) best[i] = a[i - 1] + 1;

    int m = val.size();

    SegmentTree before(m);
    SegmentTree after (m);

    for (int i = 0; i < n; i++) {
        int comp_a = compressed[a[i]];
        int comp_best = compressed[best[i]];

        // Primera transición
        int q1 = (comp_a > 0) ? after.query(0, comp_a - 1) : 0;
        int new_after_a = 1 + q1;

        // Segunda transición
        int q2 = (comp_best > 0) ? before.query(0, comp_best - 1) : 0;
        int new_after_best = 1 + q2;

        // Tercera transición
        int q3 = (comp_a > 0) ? before.query(0, comp_a - 1) : 0;
        int new_before_a = 1 + q3;

        after.update(comp_a, new_after_a);
        after.update(comp_best, new_after_best);
        before.update(comp_a, new_before_a);
    }

    int ans = max(after.query(0, m - 1), before.query(0, m - 1));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}