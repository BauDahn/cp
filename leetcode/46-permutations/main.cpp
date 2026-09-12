#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& actual, vector<bool>& usado, vector<vector<int>>& ans) {
        // Caso base: Hay una permutación válida
        if (actual.size() == nums.size()) {
            ans.push_back(actual);
            return;
        }

        // Ahora hacemos la llamada recursiva
        for (int i = 0; i < nums.size(); i++) {
            if (!usado[i]) {
                actual.push_back(nums[i]);
                usado[i] = true;
                backtrack(nums, actual, usado, ans);
                usado[i] = false;
                actual.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> actual;
        vector<bool> usado(nums.size(), false);
        vector<vector<int>> ans;

        backtrack(nums, actual, usado, ans);

        return ans;
    }
};