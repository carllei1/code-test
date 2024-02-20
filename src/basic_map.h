// basic_map.h
#ifndef BASIC_MAP_H // include guard
#define BASIC_MAP_H

#include "i_map.h"

class BasicMap : public IMap {
public:
    BasicMap() : dimensions({4, 4}) {};

    BasicMap(const Coordinates &map_size) : dimensions(map_size) {};

    BasicMap(int x, int y) : dimensions({x, y}) {};

    // Commented in base class.
    bool is_valid_move(const Coordinates &coordinates) const override;

private:
    // Dimension for map.
    Coordinates dimensions;
};

#endif /* BASIC_MAP_H */
