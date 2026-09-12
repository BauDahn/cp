#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    double k;
    cin >> n >> k;
    
    double mejor = 0.0;

    for (int i = 0; i < n; i++) {
        double c, s;
        cin >> c >> s;
        mejor = max(mejor, s / c);
    }

    double maximo = k * mejor;

    cout << fixed << setprecision(1) << maximo << '\n';

    return 0;
}