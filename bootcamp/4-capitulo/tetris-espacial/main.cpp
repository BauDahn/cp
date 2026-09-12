#include <bits/stdc++.h>
using namespace std;

void torres(int n, int origen, int destino, int auxiliar) {
    if (n == 0) return;  // Es el caso base necesario en la recursión!!

    torres(n - 1, origen, auxiliar, destino); // Movemos las n - 1 naves al hangar auxiliar

    cout << origen << " " << destino << "\n";

    torres(n - 1, auxiliar, destino, origen); // Movemos las n - 1 naves del auxiliar al destino final
}

int main() {
    // Primero tenemos las líneas de optimización para la programación competitiva
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int k = (1 << n) - 1; // El total de movimientos es 2^n - 1
    cout << k << '\n';

    // Ahora mostramos el recorrido con la función recursiva
    torres(n, 1, 3, 2);


    return 0;
}