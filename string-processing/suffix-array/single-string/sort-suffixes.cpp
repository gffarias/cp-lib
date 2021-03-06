#include "../../../boilerplate.cpp"

template<class S>
vi sortSuffixes (const S& s, vi& ord) {  // O(n lg n)
    int n = s.size(), m = 1;
    ord.assign(n, 0);  // ord may come as an empty vector
    vi sa(n), cnt(n), aux(n);
    iota(sa.begin(), sa.end(), 0);
    sort(sa.begin(), sa.end(), [&] (int i, int j) { return s[i] < s[j]; });
    for (int i = 1; i < n; i++) {
        if (s[sa[i]] > s[sa[i - 1]]) m++;
        ord[sa[i]] = m - 1;
    }
    for (int h = 1; h < n && m < n; h <<= 1) {
        int l = 0, r = h;
        for (int i : sa) {
            if (i >= h) aux[r++] = i - h;
            if (i >= n - h) aux[l++] = i;
        }
        fill(cnt.begin(), cnt.begin() + m, 0);
        for (int i : aux) cnt[ord[i]]++;
        partial_sum(cnt.begin(), cnt.begin() + m, cnt.begin());
        for (auto it = aux.rbegin(); it != aux.rend(); it++) {
            sa[--cnt[ord[*it]]] = *it;
        }
        m = 1, aux[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            int d = ord[sa[i]] - ord[sa[i - 1]];
            if (d > 0 || d == 0 && (sa[i - 1] >= n - h
            || ord[sa[i] + h] > ord[sa[i - 1] + h])) m++;
            aux[sa[i]] = m - 1;
        }
        ord.swap(aux);
    }
    return sa;
}

template<class S>
vi sortSuffixes (const S& s) {
    vi ord;
    return sortSuffixes(s, ord);
}