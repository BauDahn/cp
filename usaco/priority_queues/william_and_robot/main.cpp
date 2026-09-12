#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> nums(n);
    for (auto &num : nums) cin >> num;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (int i = 0 ; i < n ; i += 2) {
        ll num1 = nums[i];
        ll num2 = nums[i + 1];

        pq.push(num1);
        pq.push(num2);

        pq.pop();

    }
    ll suma = 0;
    while(!pq.empty()) {
        suma += pq.top();
        pq.pop();
    }

    cout << suma << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}