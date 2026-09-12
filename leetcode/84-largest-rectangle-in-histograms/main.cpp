#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> st;  // Pila de índices

    // Precálculo de los de la izquierda
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) { // Si es mayor o igual la barra la saco de la pila
            st.pop();
        }
        // Si la pila queda vacia, no hay nadie menor a su izquierda
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // Limpiamos la pila
    while (!st.empty()) st.pop();

    // Precálculo de los de la derecha
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // Cálculo el área ahora
    int max_area = 0;
    for (int i = 0; i < n; i++) {
        int ancho = right[i] - left[i];
        int area = heights[i] * ancho;
        max_area = max(max_area, area);
    }

    return max_area;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);



    return 0;
}