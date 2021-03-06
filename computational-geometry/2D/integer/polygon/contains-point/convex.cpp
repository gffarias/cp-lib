#include "../../../../../problem-solving-paradigms/binary-search/monotonically-decreasing.cpp"
#include "../polygon.cpp"

// localizes point q with relation to this polygon
// returns 0, if q lies outside the polygon
// returns 1, if q lies on the boundaries of the polygon (on some edge or vertex)
// returns 2, if q lies strictly inside the polygon
// complexity: O(lg(sides))
// polygon must be convex, with at least 3 vertices, listed counterclockwise
int Polygon::contains (PT q) {
    PT u = q - p[0], v = p[1] - p[0], w = p[sides - 1] - p[0];
    if (v % u >= 0 && u % w >= 0) {
        int i = search(1, sides - 2, [&] (int i) {
            return (p[i] - p[0]) % u >= 0;
        });
        ll c = (p[i + 1] - p[i]) % (q - p[i]);
        if (c == 0) return 1;
        else if (c > 0) return u % v == 0 || u % w == 0 ? 1 : 2;
    }
    return 0;
}