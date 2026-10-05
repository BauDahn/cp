#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;

    unordered_map<int, int> idx;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        idx[a] = i;
        nums.push_back(a);
    }

    sort(nums.begin(), nums.end());

    vector<int> diff;
    for (int i = 1; i < n; i++) {
        diff.push_back(nums[i] - nums[i - 1]);
    }

    // for (int i : diff) {
    //     cout << i << ' ';
    // }
    // cout << '\n';

    vector<int> ans;
    int total = 0;
    if (diff[0] >= d) {
        ans.push_back(idx[nums[0]] + 1);
    }
    if (diff[diff.size() - 1] >= d) {
        ans.push_back(idx[nums[nums.size() - 1]] + 1);
    }

    for (int i = 1; i < n - 1; i++) {
        if (diff[i] >= d && diff[i - 1] >= d) {
            ans.push_back(idx[nums[i]] + 1);
        }
    }

    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}