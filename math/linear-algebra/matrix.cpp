#include "../../boilerplate.cpp"
 
typedef valarray<ld> VR;
 
struct MX : public vector<VR> {
    int m, n;
    MX (int m, int n) : m(m), n(n), vector<VR>(m, VR(n)) {}
};
 
// identity matrix of order n, scaled by k
MX identity (int n, ld k = 1.0L) {
    MX a(n, n);
    for (int i = 0; i < n; i++) a[i][i] = k;
    return a;
}