#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int n, int k, int idx, int suma_actual, vector<int>& actual, vector<vector<int>>& ans) {
        // El caso base es que este todo perfecto
        if (suma_actual == n && actual.size() == k) {
            ans.push_back(actual);
            return;
        }

        // Condición de poda:
        if (suma_actual > n || actual.size() > k) {
            return;
        }

        // El bucle en este caso es el siguiente:
        for (int i = idx; i <= 9; i++) {
            if (actual.size() < k && idx <= 9) {
                actual.push_back(i);
                backtrack(n, k, i + 1, suma_actual + i, actual, ans);
                actual.pop_back();
            } 
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> actual;
        int suma_actual = 0;

        backtrack(n, k, 1, suma_actual, actual, ans);

        return ans;
    }
};