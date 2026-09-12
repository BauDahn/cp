#include "testlib.h"
#include <set>
#include <utility>

using namespace std;

int main(int argc, char* argv[]) {
    // Inicializa la librería
    registerValidation(argc, argv);

    // 1. Validar N, M y K
    // inf.readInt(min, max, "nombre_variable") lee y valida el rango
    int n = inf.readInt(1, 100000, "N");
    inf.readSpace();
    int m = inf.readInt(0, 200000, "M");
    inf.readSpace();
    int k = inf.readInt(1, n, "K");
    inf.readEoln();

    // 2. Validar el array de tiempos T
    for (int i = 1; i <= n; i++) {
        inf.readInt(1, 10000, "T_i");
        if (i < n) inf.readSpace();
    }
    inf.readEoln();

    // 3. Validar los Recuerdos Dorados (que sean distintos y estén en rango)
    set<int> golden_nodes;
    for (int i = 1; i <= k; i++) {
        int d = inf.readInt(1, n, "D_i");
        // Asegurarse de que no haya dorados repetidos
        ensuref(golden_nodes.find(d) == golden_nodes.end(), "Los recuerdos dorados deben ser distintos");
        golden_nodes.insert(d);
        if (i < k) inf.readSpace();
    }
    inf.readEoln();

    // 4. Validar las aristas
    set<pair<int, int>> edges;
    for (int i = 1; i <= m; i++) {
        int u = inf.readInt(1, n, "U");
        inf.readSpace();
        int v = inf.readInt(1, n, "V");
        inf.readEoln();

        ensuref(u != v, "Un recuerdo no puede conectar consigo mismo (U != V)");
        ensuref(edges.find({u, v}) == edges.end(), "No pueden haber aristas duplicadas");
        edges.insert({u, v});
    }

    // 5. Asegurarse de que el archivo termina correctamente (sin basura al final)
    inf.readEof();

    return 0;
}