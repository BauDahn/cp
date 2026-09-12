#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll actual = 5;
        ll contador = 0;

        while (true) {
            ll num = n/actual;
            if (num != 0) {
                contador += num;
                actual *= 5;
            }
            else {
                break;
            }
        }

        cout << contador << "\n";

    }

    return 0;
}