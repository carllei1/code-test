// coordinates.h

#ifndef COORDINATES_H
#define COORDINATES_H

#include <tuple>

struct Coordinates {
    int x;
    int y;

    bool operator==(const Coordinates &a) const {
        if (this->x == a.x && this->y == a.y) {
            return true;
        } else {
            return false;
        }
    }
};

#endif //COORDINATES_H
