#include "../../../template.cpp"

// v: vector of strings
// n: sum of lengths of strings in v
// sorts lexicographically the suffixes from all the strings,
// at a time complexity of O(n lg^2 n)
// returns sa: the multi-string suffix array,
// a succession of pairs (i, j), representing the suffix of the
// ith string in v with starting position j
template<class S>
vector<ii> sortSuffixes (vector<S>& v) {
    vector<ii> sa;
    int lim = 0, h = 1, m = 1;
    vector<vi> ord, aux;
    for (int i = 0; i < v.size(); i++) {
        int sz = v[i].size();
        lim = max(lim, sz);
        ord.emplace_back(sz + 1, -1);
        aux.emplace_back(sz + 1, -1);
        for (int j = 0; j < sz; j++) {
            sa.emplace_back(i, j);
        }
    }
    sort(sa.begin(), sa.end(), [&] (const ii& p, const ii& q) {
        return v[p.first][p.second] < v[q.first][q.second];
    });
    ord[sa[0].first][sa[0].second] = 0;
    for (int i = 1; i < sa.size(); i++) {
        if (v[sa[i - 1].first][sa[i - 1].second]
        < v[sa[i].first][sa[i].second]) m++;
        ord[sa[i].first][sa[i].second] = m - 1;
    }
    auto comp = [&] (const ii& p, const ii& q) {
        return ii(ord[p.first][p.second],
        ord[p.first][min(int(v[p.first].size()), p.second + h)])
        < ii(ord[q.first][q.second],
        ord[q.first][min(int(v[q.first].size()), q.second + h)]);
    };
    while (h < lim) {
        sort(sa.begin(), sa.end(), comp);
        m = 1;
        ord[sa[0].first][sa[0].second] = 0;
        for (int i = 1; i < sa.size(); i++) {
            if (comp(sa[i - 1], sa[i])) m++;
            aux[sa[i].first][sa[i].second] = m - 1;
        }
        ord.swap(aux);
        h <<= 1;
    }
    return sa;
}