#include <bits/stdc++.h>
using namespace std;

int soluciones = 0;

vector<bool> col_ocupada;
vector<bool> diag1_ocupada;
vector<bool> diag2_ocupada;

void backtrack(int r, int n) {
    // Caso base, ponemos N reinas con éxito
    if (r == n) {
        soluciones++;
        return;
    }
    
    for (int c = 0; c < n; c++) {
        // Acá viene la parte de poda: si la columna o las diagonales están bajo ataque, saltamos esta rama
        if (col_ocupada[c] || diag1_ocupada[r + c] || diag2_ocupada[r - c + n]) {
            continue;
        }

        // Lógica de toma de decisión
        col_ocupada[c] = diag1_ocupada[r + c] = diag2_ocupada[r - c + n] = true;

        // Avance al siguiente nivel
        backtrack(r + 1, n);

        // Desmarcar
        col_ocupada[c] = diag1_ocupada[c + r] = diag2_ocupada[r - c + n] = false;
    }
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    col_ocupada.resize(n, false);
    diag1_ocupada.resize(2 * n, false);
    diag2_ocupada.resize(2 * n, false);

    backtrack(0, n);

    cout << soluciones << '\n';

    return 0;
}