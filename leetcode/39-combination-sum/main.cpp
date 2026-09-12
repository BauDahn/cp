#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int idx, int suma_acumulada, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& actuales) {
        // El caso base es que la suma_acumulada = target
        if (suma_acumulada == target) {
            ans.push_back(actuales);
            return;
        }

        // Si nos pasamos del target o nos quedamos sin candidatos, podamos.
        if (suma_acumulada > target || idx == candidates.size()) {
            return;
        } 

        // Opción 1: incluimos el actual, (o lo reutilizamos)
        actuales.push_back(candidates[idx]);
        backtrack(idx, suma_acumulada + candidates[idx], candidates, target, ans, actuales);
        actuales.pop_back();

        // Opción 2: No incluyo el actual y paso al siguiente
        backtrack(idx + 1, suma_acumulada, candidates, target, ans, actuales);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> actuales;

        backtrack(0, 0, candidates, target, ans, actuales);
        return ans;
    }
};