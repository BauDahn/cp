#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Es un problema de subsets en verdad, pero necesito un mapa.
    // Hay que hacer un for para cada clave del mapa.
    vector<string> mapeo = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    void backtrack(int idx, string& digits, string& actual, vector<string>& ans) {
        // El caso base es que la combinación tiene la longitud de digits
        if (idx == digits.size()) {
            ans.push_back(actual);
            return;
        }

        // Ahora hay que convertir el char a int
        int digito = digits[idx] - '0';
        string opciones = mapeo[digito];

        // Probamos cada letra del dígito actual
        for (char c : opciones) {
            actual.push_back(c); // Marcamos la actual
            backtrack(idx + 1, digits, actual, ans); // Hacemos la recursión
            actual.pop_back(); // Deshacemos el cambio
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;

        string actual = "";
        backtrack(0, digits, actual, ans);
        return ans;
    }
};