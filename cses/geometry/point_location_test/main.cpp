#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    ll cross_prod = (x2 - x1)*(y3 - y1) - (x3 - x1) * (y2 - y1);
    if (cross_prod == 0) {
        cout << "TOUCH" << endl;
    } else if (cross_prod > 0) {
        cout << "LEFT" << endl;
    } else {
        cout << "RIGHT" << endl;
    }
    
    return;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}