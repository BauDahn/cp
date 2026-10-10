#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct segTree {
    int n;
    vector<ll> t;

    segTree(const vector<ll>& a) : n(a.size()), t(4 * a.size()) {
        build(1, 0, n - 1, a);
    }

    void build(int nodo, int l, int r, const vector<ll>& a) {
        if (l == r) {
            t[nodo] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * nodo + 1, l, m, a);
        build(2 * nodo + 2, m + 1, r, a);
        t[nodo] = t[2 * nodo] + t[2 * nodo + 1];
    }
    
    void update(int i, ll v, int l, int r, const vector<ll>& a) {
        
    }

    int query(int nodo, int l, int r, int ql, int qr) {

    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1 ); for (int i = 1; i < n + 1; i++) cin >> a[i];


    while (q--) {
        int tipo, i, v;
        cin >> tipo >> i >> v;
        if (tipo == 1) {

        } else {

        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}