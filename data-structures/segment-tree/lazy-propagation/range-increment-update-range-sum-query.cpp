#include "../../../boilerplate.cpp"

struct RangeIncrement {
    vector<ll> tree, lazy;
    RangeIncrement (int n) : tree(n << 2), lazy(n << 2) {}
    void refresh (int p, int l, int r) {
        if (lazy[p] != 0) {
            tree[p] += lazy[p]*(r - l + 1);
            if (l < r) {
                int lc = p << 1, rc = lc + 1;
                lazy[lc] += lazy[p];
                lazy[rc] += lazy[p];
            }
            lazy[p] = 0;
        }
    }
    void update (int p, int l, int r, int ul, int ur, ll x) {
        refresh(p, l, r);
        if (r < ul || l > ur) {
            return;
        } else if (ul <= l && r <= ur) {
            lazy[p] += x;
            refresh(p, l, r);
        } else {
            int m = l + r >> 1, lc = p << 1, rc = lc + 1;
            update(lc, l, m, ul, ur, x);
            update(rc, m + 1, r, ul, ur, x);
            tree[p] = tree[lc] + tree[rc];
        }
    }
    ll query (int p, int l, int r, int ql, int qr) {
        refresh(p, l, r);
        if (r < ql || l > qr) {
            return 0;
        } else if (ql <= l && r <= qr) {
            return tree[p];
        } else {
            int m = l + r >> 1, lc = p << 1, rc = lc + 1;
            return query(lc, l, m, ql, qr) + query(rc, m + 1, r, ql, qr);
        }
    }
};