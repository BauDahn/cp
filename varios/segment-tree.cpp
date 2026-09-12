#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int n) : n(n), tree(2*n, INF) {} // Esta línea no sé para qué es.

    void update(int p, int x) { // Esta es la función que actualiza el valor de tree[p] por x
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);



    return 0;
}