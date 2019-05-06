#ifndef RAYCAST_H
#define RAYCAST_H

#include "vector.h"
#include "line.h"
#include <stdio.h>
#include "dynarray.h"

Vec2 raycast(Line line, Line other);
Vec2 get_closest_point(Vec2 startPt, Dynarray* pts);

#endif
