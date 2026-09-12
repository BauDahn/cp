#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // El límite para escribirlas a mano es 12 de longitud.
    cout << (n <= 12 ? n * 40 : 0) << '\n';
    
    return 0;
}