#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll binarySearch(ll low, ll high, ll c, const vector<ll>& cuadros) {
    ll mid = low + (high - low) / 2;

    ll total_area = 0;
    bool overflow = false;

    for (ll s: cuadros) {
        ll side = s + 2 * mid;
        ll area = side * side;


        total_area += area;

        if (total_area > c) {
            overflow = true;
            break;
        }
    }

    if (total_area == c) {
        return mid;
    }
    if (overflow) {
        return binarySearch(low, mid - 1, c, cuadros);
    } else {
        return binarySearch(mid + 1, high, c, cuadros);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll c;
        cin >> n >> c;
        vector<ll> cuadros(n);
        for (int i = 0; i < n; i++) {
            cin >> cuadros[i];
        }

        ll low = 1;
        ll high = 1e9;

        ll ans = binarySearch(low, high, c, cuadros);

        cout << ans << '\n';
    }

    return 0;
}