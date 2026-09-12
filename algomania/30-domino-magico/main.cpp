#include <bits/stdc++.h>

// Easter egg en este submit !!
// #include <nigga> xd

using namespace std;

struct Pieza {
    int u, v;
};

vector<Pieza> fichas(8);
vector<bool> usado(8, false);
vector<vector<int>> tablero(4, vector<int>(4, -1));
int cte_magica = -1;

bool esValido() {
    for (int c = 0; c < 4; c++) {
        int suma_col = 0;
        for (int r = 0; r < 4; r++) suma_col += tablero[r][c];
        if (suma_col != cte_magica) return false;
    }

    int diag1 = tablero[0][0] + tablero[1][1] + tablero[2][2] + tablero[3][3];
    if (diag1 != cte_magica) return false;

    int diag2 = tablero[3][0] + tablero[0][3] + tablero[1][2] + tablero[2][1];
    if (diag2 != cte_magica) return false;

    return true;
}

bool filaValida(int r) {
    for (int c = 0; c < 4; c++) {
        if (tablero[r][c] == -1) return true; // Dejamos pasar la recursión
    }
    int suma_fila = tablero[r][0] + tablero[r][1] + tablero[r][2] + tablero[r][3];
    return suma_fila == cte_magica;
}

bool backtrack(int colocadas) {
    if (colocadas == 8) {
        return esValido();
    }

    // Si todavía no hay 8 piezas:
    int r = -1, c = -1;
    for (int i = 0; i < 4 && r == -1; i++) {
        for (int j = 0; j < 4; j++) {
            if (tablero[i][j] == -1) {
                r = i; c = j;
                break;
                // Es una forma de buscar la próxima casilla vacía
            }
        }
    }

    // Probar colocar cada ficha no usada
    for (int i = 0; i < 8; i++) {
        if (usado[i]) continue;

        usado[i] = true;

        vector<pair<int, int>> orientaciones = {{fichas[i].u, fichas[i].v}};
        if (fichas[i].u != fichas[i].v) {
            orientaciones.push_back({fichas[i].v, fichas[i].u});
        }

        if (c + 1 < 4 && tablero[r][c + 1] == -1) {
            // Probamos las rotaciones y podamos
            for (auto [val1, val2] : orientaciones) {
                tablero[r][c] = val1;
                tablero[r][c + 1] = val2;

                // Poda : Si rellenamos la celda (r, 3), la fila r está completa

                if (filaValida(r) && backtrack(colocadas + 1)) return true;

                tablero[r][c] = -1;
                tablero[r][c + 1] = -1;
            }
        }

        if (r + 1 < 4 && tablero[r + 1][c] == -1) {
            // Lo mismo que en horizontal
            for (auto [val1, val2] : orientaciones) {
                tablero[r][c] = val1;
                tablero[r + 1][c] = val2;

                // Poda : Si c == 3, rellenamos (r, 3) con la parte superior de la ficha vertical

                if ((filaValida(r) && filaValida(r + 1)) && backtrack(colocadas + 1)) return true;

                tablero[r][c] = -1;
                tablero[r + 1][c] = -1;
            }
        }

        usado[i] = false;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int suma_total = 0;
    for (int i = 0; i < 8; i++) {
        cin >> fichas[i].u >> fichas[i].v;
        suma_total += (fichas[i].u + fichas[i].v);
    }

    if (suma_total % 4 != 0) {
        cout << "IMPOSIBLE\n";
        return 0;
    }

    cte_magica = suma_total / 4;

    if (backtrack(0)) {
        cout << "POSIBLE\n";
    } else {
        cout << "IMPOSIBLE\n";
    }

    return 0;
}