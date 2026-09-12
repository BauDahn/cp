#include <bits/stdc++.h>
using namespace std;

int expandir(const string& s, int izq, int der) {
    while (izq >= 0 && der <= s.length() && s[izq] == s[der]) {
        izq--;
        der++;
    }

    return der - izq - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string nombre;
    while (cin >> nombre) {
        // Una vez tenemos la palabra a analizar
        int longitud_maxima = 1; // Creamos una posible longitud máxima
        int n = nombre.length();

        for (int i = 0; i < n; i++) {
            int len_impar = expandir(nombre, i , i);

            int len_par = expandir(nombre, i, i+1);

            int len_actual = max(len_par, len_impar);

            longitud_maxima = max(longitud_maxima, len_actual);
        }

        cout << longitud_maxima << '\n';
    }

    return 0;
}