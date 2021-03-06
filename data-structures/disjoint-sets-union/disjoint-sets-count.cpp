#include "../../boilerplate.cpp"

struct DSU {       // union by size
    int n;
    vi par, sz;
    DSU (int n) : n(n), par(n), sz(n, 1) {  // 0-based
        iota(par.begin(), par.end(), 0);
    }
    int find (int u) {  // representative upon u's connected component
        return par[u] == u ? u : par[u] = find(par[u]);
    }
    bool connected (int u, int v) {  // whether u and v are in the same connected component
        return find(u) == find(v);
    }
    void merge (int u, int v) {     // unify (permanently) two connected components
        u = find(u), v = find(v);
        if (u != v) {
            n--;
            if (sz[u] < sz[v]) swap(u, v);
            par[v] = u;
            sz[u] += sz[v];
        }
    }
    int count (int u) { return sz[find(u)]; }  // number of members among u's connected component
};