#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, bolita;
    while (cin >> N >> bolita && (N || bolita)) {
        int primero, segundo;
        while (cin >> primero >> segundo && (primero || segundo)) {
            if (bolita != primero && bolita != segundo) continue;
            if (bolita == primero) bolita = segundo;
            else bolita = primero; 
        }
        cout << bolita << '\n';
    }

    return 0;
}