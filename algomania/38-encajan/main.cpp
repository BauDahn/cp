#include <bits/stdc++.h>
using namespace std;

int contar_primos(int n) {
    int contador = 0;

    if (n % 2 == 0) {
        contador++;
        while (n % 2 == 0) n /= 2;
    }

    for (int d = 3; d * d <= n; d+= 2) {
        if (n % d == 0) {
            contador++;
            while (n % d == 0) n /= d;
        }
    }

    if (n > 1) contador++;

    return contador;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s, d;
    cin >> s >> d;
    int g = gcd(s, d);
    int comunes = contar_primos(g);

    cout << (comunes % 2 == 0 ? "ENCAJAN\n" : "NO ENCAJAN\n");

    return 0;
}