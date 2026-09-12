#include <bits/stdc++.h>
using namespace std;

struct Cliente {
    long long llegada, salida, id;
    // Función para poder hacer el sort
    bool operator<(const Cliente& other) const {
        return llegada < other.llegada;
    }
};

typedef pair<int, int> pii;

void solve() {
    long n;
    cin >> n;
    vector<Cliente> a(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i].llegada >> a[i].salida;
        a[i].id = i;
    }

    sort(a.begin(), a.end()); 

    vector<int> habitaciones(n);
    int habitaciones_totales = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (auto& c : a) {
        if (!pq.empty() && c.llegada > pq.top().first) { // Indica que se puede reutilizar una habitación
            int id_viejo = pq.top().second;
            habitaciones[c.id] = habitaciones[id_viejo]; // El actual usa la misma habitación que el que se fue de esa habitación.
            pq.pop(); // La habitación queda ocupada
        } else {
            habitaciones_totales++; // Necesito usar una habitación más.
            habitaciones[c.id] = habitaciones_totales;
        }
        pq.push({c.salida, c.id}); // Añado al priority queue las características del nuevo inquilino
    }

    cout << habitaciones_totales << '\n';
    for (int i = 0 ; i < n ; i++) cout << habitaciones[i] << (i == n-1 ? "" : " ");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}