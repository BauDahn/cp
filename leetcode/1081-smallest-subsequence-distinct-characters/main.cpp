#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    // Guardo las frecuencias de cada letra
    vector<int> freq(26, 0);
    for (char c : s) {
        int idx = c - 'a';
        freq[idx]++; 
    }
    // Recorremos s usando una pila y un vector<bool> visited
    vector<bool> visited(n, false);
    stack<char> pila;
    
    int i = 0;
    while (i < n) {
        char letra = s[i];
        // Si fue visitado
        if (visited[letra - 'a']) {
            i++; // Pasamos al siguiente
            freq[letra - 'a']--; // Restamos uno en su frecuencia
            continue;
        }
        // Si no fue visitado todavía
        while (!pila.empty() && letra < pila.top() && freq[pila.top() - 'a'] > 0) {
            visited[pila.top() - 'a'] = false;
            pila.pop();
        }
        pila.push(letra);
        visited[letra - 'a'] = true;
        freq[letra - 'a']--;
        i++;
    }

    // Ahora hay que reconstruir la cadena
    string subcadena = "";
    while (!pila.empty()) {
        subcadena += pila.top();
        pila.pop();
    }
    reverse(subcadena.begin(), subcadena.end());
    cout << subcadena;
}