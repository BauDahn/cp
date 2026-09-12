#include <bits/stdc++.h>
using namespace std;

int lis(vector<int>& nums) {
    vector<int> tails;
    int n = nums.size();

    for (int x : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) {
            tails.push_back(x);
        } else {
            *it = x;
        }
    }

    return tails.size();
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    int k = lis(nums);

    cout << k << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}