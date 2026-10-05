#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    unordered_map<int, pair<int, int>> m;
    vector<int> p(n);

    for (int i = 0; i < n; i++) cin >> p[i];

    int inicio = p[0];
    int ultimo = p[n - 1];

    for (int i = 0; i < n; i++) {
        int anterior = (i == 0) ? -1 : p[i - 1];
        int siguiente = (i == n - 1) ? -1 : p[i + 1];
        m[p[i]] = {anterior, siguiente};
    }

    while (q--) {
        int a;
        cin >> a;

        // Voy a empezar por el caso de a = último elemento
        if (m[a].second == -1) continue; // En este caso no hay que hacer nada !!

        // Ahora va el caso en el que es el primer elemento de todos
        if (m[a].first == -1) {
            int siguiente_a = m[a].second; // Este va a pasar a ser el núevo primero
            inicio = siguiente_a; // Hay un nuevo inicio, el siguiente del que estamos moviendo al final
            m[siguiente_a].first = -1; // Lo volvemos el nuevo primero, ya no apunta a a.
            m[a].second = -1; // Tiene que apuntar a la nada el siguiente de a.
            m[a].first = ultimo; // El anterior del nuevo ultimo es el ultimo viejo
            m[ultimo].second = a; // Ahora el siguiente del anterior último es a, el nuevo último

            ultimo = a; // a pasa a ser el nuevo último.
            continue;
        }

        // Último caso:
        int anterior_a = m[a].first; // Nos quedamos con el anterior 
        int siguiente_a = m[a].second; // Nos quedamos con el siguiente

        m[anterior_a].second = siguiente_a;
        m[siguiente_a].first = anterior_a; 
        // Con esos cambios de ahi ya desconectamos el actual, ahora hay que conectarlo al final

        m[ultimo].second = a;
        m[a].first = ultimo;
        m[a].second = -1;
        // Ahi lo conectamos al final

        ultimo = a;
    }

    // Una vez procesadas las consultas, hay que devolver el array original.
    vector<int> res;
    res.push_back(inicio);
    int siguiente = m[inicio].second;
    while (siguiente != -1) {
        res.push_back(siguiente);
        siguiente = m[siguiente].second;
    }

    for (int i : res) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}