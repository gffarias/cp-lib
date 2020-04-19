#include <iostream>
#include "../../util/fast-exponentiation.cpp"
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;  // TODO MOD value is defined on the problem statement
    
struct MB {
    int x;
    MB (int x = 0) : x(x) {}  // implicit conversion in assignment statements
    MB operator+ (MB o) {
        int y = x + o.x;
        return y >= MOD ? y - MOD : y;
    }
    MB operator- (MB o) {
        int y = x + MOD - o.x;
        return y >= MOD ? y - MOD : y;
    }
    MB operator* (MB o) { return (ll) x*o.x % MOD; }
    MB operator/ (MB o) { return *this*fastExp(o, MOD - 2); }
    void operator+= (MB o) { *this = *this + o; }
    void operator-= (MB o) { *this = *this - o; }
    void operator*= (MB o) { *this = *this * o; }
    void operator/= (MB o) { *this = *this / o; }
    operator int() { return x; }  // direct comparisons to int values
};

istream& operator>> (istream& is, MB& m) { return is >> m.x; }  // reading easily
ostream& operator<< (ostream& os, MB& m) { return os << m.x; }  // printing easily