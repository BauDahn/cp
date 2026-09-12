#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int idx, vector<int>& nums, vector<int>& actuales, vector<vector<int>>& ans) {
        // El caso base es que idx = nums.size()
        if (idx == nums.size()) {
            ans.push_back(actuales);
            return;
        }

        // La opción es agarrar el actual
        actuales.push_back(nums[idx]);
        backtrack(idx + 1, nums, actuales, ans);
        actuales.pop_back();

        // La opción es no agarrar el actual
        backtrack(idx + 1, nums, actuales, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> actuales;

        backtrack(0, nums, actuales, ans);
        return ans;
    }
};