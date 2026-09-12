#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        double c, k;
        cin >> c >> k;

        double radio = c / (2 * M_PI); 
        double area = M_PI * radio * radio;

        cout << fixed << setprecision(2) << (k * c / area) << '\n';
    }

    return 0;
}