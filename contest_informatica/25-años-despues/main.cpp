#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll valores_ceros[18] = {
    1LL, 6LL, 31LL, 156LL, 781LL, 3906LL, 19531LL, 97656LL, 488281LL, 
    2441406LL, 12207031LL, 61035156LL, 305175781LL, 1525878906LL, 
    7629394531LL, 38146972656LL, 190734863281LL, 953674316406LL
};

const ll potencias[18] {
    5LL, 25LL, 125LL, 625LL, 3125LL, 15625LL, 78125LL, 390625LL, 1953125LL, 
    9765625LL, 48828125LL, 244140625LL, 1220703125LL, 6103515625LL, 
    30517578125LL, 152587890625LL, 762939453125LL, 3814697265625LL
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll div, ceros;

    while (cin >> div >> ceros && (div != 0 || ceros != 0)) {

        ll num = 0;
        ll restante = ceros;


        bool imposible = false;
        for (int i = 17; i >= 0; --i) {
            if (restante >= valores_ceros[i]) {
                ll cociente = restante / valores_ceros[i];

                if (cociente >= 5) {
                    imposible = true;
                    break;
                }

                num += cociente * potencias[i];
                restante %= valores_ceros[i];
            }
        }

        if (restante != 0) {
            imposible = true;
        }


        bool encontrado = false;
        if (!imposible) {
            for (ll i = num; i < num + 5; i++) {
                if (i % div == 0) {
                    if (i == 0) {
                        continue;
                    }
                    cout << i << '\n';
                    encontrado = true;
                    break;
                }
            }
        }
        if (!encontrado) {
            cout << "NINGUNO" << '\n';
        }
    }
    return 0;
}