#include "basic_map.h"

bool BasicMap::is_valid_move(const Coordinates &coordinates) const {
    if (coordinates.x < 0 || coordinates.y < 0) {
        return false;
    } else if (coordinates.x > dimensions.x ||
               coordinates.y > dimensions.y) {
        return false;
    } else {
        return true;
    }
}
