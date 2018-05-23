#include <bits/stdc++.h>

#define ab(x) x<0?100000-x:x

using namespace std;

typedef vector<int> vi;

int value[200010], cnt[200010], r[200010], l[200010];

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
};



int main() {
    int n, c;
    while (scanf("%d", &n) && n) {
        scanf("%d", &c);
        vi arr2(n+1);
        vi arr(n+1);
        int m = 0;
        for (int i = 1; i <= n; i++){
            scanf("%d",&arr[i]);
            if (!m || value[m] != arr[i]){
                value[++m] = arr[i];
                cnt[m] = 1;
            }
            else cnt[m]++;
        }

        for (int i = 2; i <= m; ++i) cnt[i] += cnt[i-1];
        m = 0;
        cnt[0] = 0;
        l[ab(arr[1])] = 1;
        for (int i = 0; i <= n; ++i) {
            if (i <= cnt[m] && i > 0) {
                r[ab(arr[i])] = i;
                arr2[i] = cnt[m] - cnt[m-1];
            }
            if (i == cnt[m]) {
                l[ab(arr[i+1])]  = i+1;
                ++m;
            }
        }
        SegmentTree st(arr2);
        while (c--) {
            int a, b;
            scanf("%d %d", &a, &b);
            int left = min(r[ab(arr[a])] - a + 1, b - a + 1);
            int right = min(b - l[ab(arr[b])] + 1, b - a + 1);
            int middle = st.rmq(r[ab(arr[a])]+1, l[ab(arr[b])]-1);
            middle = middle == -1 ? -1 : arr2[middle];
            printf("%d\n", max(middle, max(left,right)));
        }
    }

    return 0;
}
