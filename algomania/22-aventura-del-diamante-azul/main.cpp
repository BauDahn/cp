#include <bits/stdc++.h>
using namespace std;

// Demasiado para aprender con este problema, pero muy interesante

// Voy a crear un struct nodo para el árbol
struct Node {
    int value;
    Node* left;
    Node* right;

    Node() {
        value = 0;
        left = nullptr;
        right = nullptr;
    }
};

// Voy a hacer aca la función para hacer las consultas de tipo 1, que actualizan un valor del array
// La idea es hacer un árbol y que las actualizaciones se vuelvan logarítmicas
void update(Node* node, int start, int end, int pos, int change) {
    // Actualizo el valor del nodo actual
    node->value += change;

    // Caso base
    if (start == end) return;

    // Partimos rango
    int mid = (start + end) / 2;

    // Elegimos el camino que hay que tomar
    if (pos <= mid) {
        if (node->left == nullptr) node->left = new Node();
        update(node->left, start, mid, pos, change);
    } else {
        if (node->right == nullptr) node->right = new Node();
        update(node->right, mid + 1, end, pos, change);
    }
}

// Segundo tipo de consulta (la de rangos)
// Voy a crear una función que se encargue de resolver este tipo de query
int contar(Node* node, int start, int end, int l, int r) {
    // Node = nodo en el que estamos
    // [start, end] = Rango de posiciones que controla este nodo
    // [l, r] = Rango donde queremos encontrar los diamantes

    if (node == nullptr) return 0; // Esta línea se asegura de que el nodo exista

    if (l > end || r < start) return 0; // El nodo está completamente fuera del rango

    if (start >= l && end <= r) return node->value; // Este es el caso en el que el nodo está completamente dentro del rango
    
    // El último caso es un solapamiento parcial, esto lo resolvemos de forma recursiva
    int mid = (start + end) / 2;

    int left = contar(node->left, start, mid, l, r);
    int right = contar(node->right, mid + 1, end, l, r);

    return left + right;
}

// La última función se usa para las consultas
int consultar(int x, int l, int r, int N, map<int, Node*>& raices) {
    auto it = raices.find(x); // Miramos si existe un árbol para este valor de x

    if (it == raices.end()) return 0; // x nunca se añadió, así que no hay diamantes de ese tipo

    // Si existe
    Node* raiz_x = it->second;

    // Llamamos a la función contar
    return contar(raiz_x, 1, N, l, r);

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    map<int, Node*> raices;
    vector<int> vitrina(N + 1);

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        vitrina[i] = x;

        if (raices.find(x) == raices.end()) raices[x] = new Node();
        
        update(raices[x], 1, N, i, 1);
    }


    int suma_total = 0;
    while (Q--) {
        int tipo;
        cin >> tipo;

        if (tipo == 1) {
            int pos, x;
            cin >> pos >> x;

            int viejo = vitrina[pos];

            if (viejo != x) {
                update(raices[viejo], 1, N, pos, -1);

                if (raices.find(x) == raices.end()) raices[x] = new Node();
                
                update(raices[x], 1, N, pos, 1);

                vitrina[pos] = x;
            }
        } else if (tipo == 2) {
            int l, r, x;
            cin >> l >> r >> x;

            auto it = raices.find(x);
            if (!(it == raices.end())) suma_total += contar(it->second, 1, N, l, r);
        }
    }
    cout << suma_total << '\n';

    return 0;
}