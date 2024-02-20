// i_map.h
#ifndef I_MAP_H // include guard
#define I_MAP_H

#include "coordinates.h"

class IMap {
public:

    // Checks if the provided coordinates are within the maps dimensions.
    virtual bool is_valid_move(const Coordinates &coordinates) const = 0;
    virtual ~IMap() = default;

};

#endif /* I_MAP_H */
