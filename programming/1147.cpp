#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class SegmentTree {
  private:
    vi st, A;
    int n;
    int left(int p) {
      return p << 1;
    }
    int right(int p) {
      return (p << 1) + 1;
    }

    void build(int p, int L, int R) {
      if (L == R) {
          st[p] = L;
      } else {
        build(left(p), L, (L+R)/2);
        build(right(p), (L+R)/2 + 1, R);
        int p1 = st[left(p)], p2 = st[right(p)];
        st[p] = A[p1] >= A[p2] ? p1 : p2;
      }
    }

    int rmq(int p, int L, int R, int i, int j) {
      if (i > R || j < L) return -1;
      if (L >= i && R <= j) return st[p];

      int p1 = rmq(left(p), L, (L+R)/2, i, j);
      int p2 = rmq(right(p), (L+R)/2 + 1, R, i, j);

      if (p1 == -1) return p2;
      if (p2 == -1) return p1;
      return (A[p1] >= A[p2]) ? p1 : p2;
    }

    void update(int p, int l, int r, int i, int val) {
      if (i < l || i > r) return;

      if (l == r) {
        A[i] = val;
        st[p] = i;
      } else {
        int mid = (l+r)/2;

        if (i <= mid) {
          update(left(p), l, mid, i, val);
        } else {
          update(right(p), mid + 1, r, i, val);
        }
        st[p] = (A[st[left(p)]] >= A[st[right(p)]]) ? st[left(p)] : st[right(p)];
      }
    }

  public:
    SegmentTree(const vi &_A) {
      A = _A;
      n = (int)A.size();
      st.assign(4 * n, 0);
      build(1, 1, n);
    }
    int rmq(int i, int j) {
      return rmq(1, 1, n, i, j);
    }
    void update(int i, int value) {
      update(1, 1, n, i, value);
    }
};


int main() {
  int n, q;

  scanf("%d %d", &n, &q);

  vi arr(n+1);
  arr.assign(n+1, 0);
  SegmentTree st(arr);

  while (q--) {
    char c[5];
    int a, b;
    scanf("%s %d %d", c, &a, &b);
    if (c[0] == 'U') {
      arr[a] = b;
      st.update(a, b);
    } else {
      printf("%d\n", arr[st.rmq(a, b)]);
    }
  }

  return 0;
}
