#include <bits/stdc++.h>
using namespace std;

struct Value {
  vector<int> indices;
  int val;
};

struct SegTree {
  int n;
  vector<Value> tree;

  SegTree(vector<int> &a) {
    this->n = a.size();
    tree = vector<Value>(4 * n);

    build(0, n - 1, 1, a);
  }

  void build(int l, int r, int node, vector<int> &a) {
    if (l == r) {
      tree[node] = {{l}, a[l]};
      return;
    }

    int leftChild = 2 * node;
    int rightChild = 2 * node + 1;
    int mid = (r - l) / 2 + l;

    build(l, mid, leftChild, a);
    build(mid + 1, r, rightChild, a);

    if (tree[leftChild].val > tree[rightChild].val) {
      tree[node] = tree[leftChild];
    } else if (tree[leftChild].val < tree[rightChild].val) {
      tree[node] = tree[rightChild];
    } else {
      tree[node] = tree[leftChild];
      for (int x : tree[rightChild].indices) {
        tree[node].indices.push_back(x);
      }
    }
  }

  Value query(int l, int r) {
    return query(0, n - 1, l, r, 1);
  }

  Value query(int l, int r, int L, int R, int node) {
    if (L <= l && R >= r) {
      return tree[node];
    }
    
    if (r < L || l > R) {
      return {{}, INT_MIN};
    }

    int leftChild = 2 * node;
    int rightChild = 2 * node + 1;
    int mid = (r - l) / 2 + l;

    Value leftValue = query(l, mid, L, R, leftChild);
    Value rightValue = query(mid + 1, r, L, R, rightChild);

    if (leftValue.val > rightValue.val) {
      return leftValue;
    } else if (leftValue.val < rightValue.val) {
      return rightValue;
    } else {
      Value ans = leftValue;
      for (int x : rightValue.indices) {
        ans.indices.push_back(x);
      }
      return ans;
    }
  }
};

int solve(int i, vector<int> &dp, SegTree &segTree, vector<int> &prevGreater, vector<int> &nextGreater) {
  int n = dp.size();

  if (dp[i] != -1) return dp[i];
  dp[i] = 1;

  if (i > 0) { // izquierda
    int l = prevGreater[i] + 1;
    int r = i - 1;

    Value v = segTree.query(l, r);
    for (int cand : v.indices) {
      dp[i] = max(dp[i], 1 + solve(cand, dp, segTree, prevGreater, nextGreater));
    }
  }

  if (i < n - 1) { // derecha
    int l = i + 1;
    int r = nextGreater[i] - 1;

    Value v = segTree.query(l, r);
    for (int cand : v.indices) {
      dp[i] = max(dp[i], 1 + solve(cand, dp, segTree, prevGreater, nextGreater));
    }
  }

  return dp[i];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  SegTree segTree(a);

  vector<int> prevGreater(n, -1);
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && a[i] >= a[st.top()]) {
      st.pop();
    }

    if (!st.empty()) {
      prevGreater[i] = st.top();
    }

    st.push(i);
  }
  while (!st.empty()) st.pop();

  vector<int> nextGreater(n, n);
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && a[i] >= a[st.top()]) {
      st.pop();
    }

    if (!st.empty()) {
      nextGreater[i] = st.top();
    }

    st.push(i);
  }

  vector<int> dp(n, -1);
  int ans = 0;

  for (int i = 0; i < n; i++) {
    ans = max(ans, solve(i, dp, segTree, prevGreater, nextGreater));
  }

  cout << ans << "\n";
  return 0;
}