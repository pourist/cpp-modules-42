#include "Point.hpp"
#include "Fixed.hpp"
#include <cmath> // for std::abs

static float area(Point const& a, Point const& b, Point const& c) {
    const float x1 = a.getX();
    const float y1 = a.getY();
    const float x2 = b.getX();
    const float y2 = b.getY();
    const float x3 = c.getX();
    const float y3 = c.getY();

    return 0.5f * std::abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {
    const float eps = 1e-6f;

    const float T  = area(a, b, c);
    if (T <= eps)
        return false;

    const float T1 = area(p, b, c);
    const float T2 = area(a, p, c);
    const float T3 = area(a, b, p);

    const bool sums_match = std::abs(T - (T1 + T2 + T3)) <= eps;
    const bool on_edge = (T1 <= eps) || (T2 <= eps) || (T3 <= eps);

    return sums_match && !on_edge;
}
