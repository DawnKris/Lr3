#ifndef POINT_H
#define POINT_H

#include <ostream>

class Point {
public:
    int x, y, z;

    Point() = default;

    Point(int x, int y, int z) : x(x), y(y), z(z) {}

    inline Point operator+(const Point& rhs) const {
        return { x + rhs.x, y + rhs.y, z + rhs.z };
    }
};

std::ostream& operator<<(std::ostream& s, const Point& p) {
    return s << "[" << p.x << "," << p.y << "," << p.z << "]";
}

#endif //POINT_H
