#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    priority_queue<pair<int, pair<int, string>>> q;
    vector<string> res;

    int t = 0;
    while (n--) {
        char op;
        cin >> op;
        if (op == '+') {
            string nombre;
            int peso;
            cin >> nombre >> peso;

            t++;

            q.push({peso, {-t, nombre}});
        } else {
            if (!q.empty()) {
                string nombre = q.top().second.second;
                q.pop();
                res.push_back(nombre);
            } else {
                res.push_back("NADA");
            }
        }
    }

    for (string nombre : res) {
        cout << nombre << '\n';
    }

    return 0;
}