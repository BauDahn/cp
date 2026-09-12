#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int abiertos, int cerrados, int n, string& actual, vector<string>& ans) {
        // El caso base es que llegamos a 2*n válidos
        if (actual.size() == 2*n) {
            ans.push_back(actual);
            return;
        }

        // Opción 1: Poner un '('
        if (abiertos < n) {
            actual.push_back('(');
            backtrack(abiertos + 1, cerrados, n, actual, ans);
            actual.pop_back();
        }

        // Opción 2: Poner un ')'
        if (abiertos > cerrados) {
            actual.push_back(')');
            backtrack(abiertos, cerrados + 1, n, actual, ans);
            actual.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        int abiertos = 0, cerrados = 0;
        string actual = "";
        vector<string> ans;

        backtrack(0, 0, n, actual, ans);

        return ans;
    }
};