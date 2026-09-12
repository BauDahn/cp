#include <bits/stdc++.h>
using namespace std;

struct Remonte {
    int origen;
    int destino;
    int tiempo;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while (cin >> n && n) {
        vector<Remonte> remontes(n);    
        for (int i = 0; i < n; i++) {
            cin >> remontes[i].origen >> remontes[i].destino >> remontes[i].tiempo;
        }

        int inicio, destino, tiempo_maximo;
        cin >> inicio >> destino >> tiempo_maximo;
        
    }

    return 0;
}