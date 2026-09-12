#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
typedef long long ll;

struct SegmentTree {
    int n;
    vector<ll> tree;

    SegmentTree(int n) : n(n), tree(2*n, INF) {}

    // Actualización puntual: O(log N)
    void update(int p, ll value) {
        for (tree[p += n] = value; p > 1; p >>= 1) {
            tree[p >> 1] = min(tree[p], tree[p ^ 1]);
        } 
    }

    ll query(int l, int r) {
        ll res = INF;
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

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<int> p(n);
    SegmentTree st_left(n);
    SegmentTree st_right(n);

    for (int k = 0; k < n; k++) {
        cin >> p[k];
        st_left.update(k, p[k] - k);
        st_right.update(k, p[k] + k);
    }

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            ll k, x;
            cin >> k >> x;
            k--;

            p[k] = x;
            st_left.update(k, p[k] - k);
            st_right.update(k, p[k] + k);

        } else {
            int i;
            cin >> i;
            i--;

            ll min_left = st_left.query(0, i + 1) + i;
            ll min_right = st_right.query(i, n) - i;

            cout << min(min_left, min_right) << '\n';
        }
    }

    return 0;
}