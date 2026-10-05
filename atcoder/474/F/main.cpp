#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// división con techo para enteros de cualquier signo
ll ceil_div (ll a, ll b) {
    if (b < 0) { a = -a; b = -b; }
    if (a >= 0) return (a + b - 1) / b;
    return a / b;
}

// division con suelo para enteros de cualquier signo
ll floor_div (ll a, ll b) {
    if (b < 0) { a = -a; b = -b; }
    if (a >= 0) return a / b;
    return (a - b + 1) / b;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // Criba
    vector<int> mu(n + 1, 0);
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);

    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            mu[i] = -1;
        }
        for (int p : primes) {
            if (i * p > n) break;
            is_prime[i * p] = false;
            if (i % p == 0) {
                mu[i * p] = 0;
                break;
            } else {
                mu[i * p] = -mu[i];
            }
        }
    }

    vector<ll> alpha(n + 1, 0);
    vector<ll> beta(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int m = 1; i * m <= n; m++) {
            if (mu[m] == 0) continue;
            alpha[i] += mu[m];
            beta[i] += (ll)mu[m] * a[i * m];
        }
    }

    ll L = -4e18;
    ll R = 4e18;

    for (int i = 1; i <= n; i++) {
        if (alpha[i] == 0) {
            if (beta[i] > 0) {
                cout << -1 << '\n';
                return;
            }
        } else if (alpha[i] > 0) {
            ll req = ceil_div(beta[i], alpha[i]);
            L = max(L, req);
        } else {
            ll req = floor_div(beta[i], alpha[i]);
            R = min(R, req);
        }
    }

    L = max(L, a[1]);

    if (L > R) {
        cout << -1 << '\n';
    } else {
        cout << L - a[1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
