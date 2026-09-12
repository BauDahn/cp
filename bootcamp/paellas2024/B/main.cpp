#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    vector<int, pair<ll, ll>> restaurantes;
    int id, i = 0;
    ll utiles, total;
    while (cin >> id >> utiles >> total) restaurantes.push_back((id, utiles, total));

    vector<double, pair<int, int>> orden(restaurantes.size());
    for (auto restaurante : restaurantes) {
        double efectividad = restaurante[1] / restaurante[2];
        orden.push_back((efectividad, i, restaurante[0]));
    }
    sort(orden.begin(), orden.end());
    for (auto elemento : orden) {
        cout << elemento[2] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}