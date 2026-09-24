#include <bits/stdc++.h>
using namespace st_d;

/* Me suena a que hay que usar una EDA que simule lo que está pasando
A primeras no veo clara una solucion greedy facil
Creo que un sort serviría y luego recorrer a partir del sort
El problema con el codigo implementado hasta ahora es que asume que todo el mundo esta aplaudiendo desde el principio
En otras palabras
Supongamos este caso de muestra que ejemplificará por que no funcionaría este código:
10 1
20 2
120 3
Primero procesamos el 10 1, y decimos que maximo = 10. Ahora hay una persona menos aplaudiendo
Ahora procesamos el 20 2, hay 2 personas aplaudiendo -> Mentira !!! Solo hay 1 aplaudiendo, el del 20, porque el 120 necesita 3

Qué pasa si enfocamos el problema a sortear a partir de la cantidad de gente que necesitan aplaudiendo ?
freq[i] <= a[i].second;

El problema con el enfoque actual es que estoy contando lo siguiente
120 2
120 3

freq[120] = 2

cuando proceso el 120 -> freq[120] >= 2 ? -> Sí !!
Eso está mal, por ende hay que plantearlo de otra forma, verlo con un mapa de frecuencias no me parece mal, pero de otra forma

Para cada número puedo ver la cantidad que verdaderamente me están aplaudiendo

*/

void solve(int n) {
    vector<pair<int, int>> a(n);
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int t, p;
        cin >> t >> p;

        freq[t]++;
        a[i].first = t;
        a[i].second = p;
    }

    sort(a.begin(), a.end());
    // Una vez sorteado el array
    int maximo = 0;

    int i = 0; // Me creo un iterador
    bool resuelto = false;
    while (i < n) {
        int j = i;
        pair<int, int> actual = a[i];
        int t = actual.first;
        int p = actual.second;
        int aplaudiendo = 0;
        while (j < n) {
            pair<int, int> nuevo = a[j];
            if (nuevo.first != t) {
                // Hacemos comprobaciones
                if (aplaudiendo >= nuevo.second) {
                    maximo = nuevo.first;
                    resuelto = true;
                    break;
                } else {
                    break;
                }
            } else {
                aplaudiendo++;
                j++; // Pasamos al próximo
            }
        }
        if (resuelto) break;
        i++;
    }

    cout << maximo << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        int n;
        cin >> n;
    
        if (n != 0) solve(n);
        else break;
    }

    return 0;
}