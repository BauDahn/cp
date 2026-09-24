#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll distance(int u, int v, vector<ll>& pref_sum) {
    return max(pref_sum[v], pref_sum[u]) - min(pref_sum[v], pref_sum[u]);
}

// This is a prefix sum + two pointer problem i believe

void solve() {
    int n, s;
    ll l;
    cin >> n >> s >> l;

    vector<int> lengths(n + 1);
    for (int i = 1; i < n; i++) cin >> lengths[i];

    vector<ll> prefix_sum(n + 1);
    prefix_sum[1] = 0;

    for (int i = 2; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + lengths[i - 1];
    }

    // for (int i : prefix_sum) {
    //     cout << i << ' ';
    // }
    // cout << '\n';

    // Base case: L == 0
    if (l == 0) {
        cout << 1 << '\n';
        return;
    }

    // If l was bigger than 0

    // First i will build the left two pointers logic
    ll ans = 1;
    int r = s;

    // First we expand as much as possible in the right direction
    while (r + 1 <= n && distance(s, r + 1, prefix_sum) <= l) {
        r++;
    }
    ans = max(ans, (ll)(r - s + 1));
    ll dr = distance(s, r, prefix_sum);

    // Then we try to expand in the left direction
    for (int left_town = s; left_town >= 1; left_town--) {
        ll dl = distance(left_town, s, prefix_sum);
        
        while (2 * dl + dr > l) {
            r--;
            if (r < s) {
                break;
            }
            dr = distance(s, r, prefix_sum);
        }

        if (r >= s) ans = max(ans, (ll)(r - left_town + 1));

    }

    // Now we have to do it the other way
    ll left = s;

    while (left - 1 >= 1 && distance(left - 1, s, prefix_sum) <= l) {
        left--;
    }
    ans = max(ans, (ll)(s - left + 1));
    ll dl = distance(s, left, prefix_sum);

    for (int right_town = s; right_town <= n; right_town++) {
        ll dr = distance(right_town, s, prefix_sum);

        while (2 * dr + dl > l) {
            left++;
            if (left > s) break;
            dl = distance(left, s, prefix_sum);
        }

        if (left <= s) ans = max(ans, (ll)(right_town - left + 1));
    }


    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}