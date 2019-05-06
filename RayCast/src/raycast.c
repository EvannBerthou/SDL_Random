#include "raycast.h"
#include <stdio.h>
#include <math.h>
#include "dynarray.h"

Vec2 raycast(Line line, Line other){
    Vec2 pt = {0,0};
    double num = 
        (
         (line.start.x  - line.end.x   )*
         (other.start.y - other.end.y  )-
         (line.start.y  - line.end.y   )*
         (other.start.x - other.end.x  )
        );

    if (num == 0) return pt;

    double t = 
        ((line.start.x  - other.start.x)*
         (other.start.y - other.end.y  )-
         (line.start.y  - other.start.y)*
         (other.start.x - other.end.x  )
        )/num;

    t /= 20;

    double u = -
        ((line.start.x  - line.end.x   )*
         (line.start.y  - other.start.y)-
         (line.start.y  - line.end.y   )*
         (line.start.x  - other.start.x)
        )/num;

    if (u >= 0 && u <= 1 && t >= 0 && t <= 1){
        Vec2 newpt = {
            other.start.x + u * (other.end.x - other.start.x),
            other.start.y + u * (other.end.y - other.start.y)
        };
        return newpt;
    }
    return pt;
}

Vec2 get_closest_point(Vec2 startPt, Dynarray* pts){
    double record_distance = 0;
    Vec2 record_pt = {-1,-1};

    Vec2* points = array_data(pts);

    for(size_t i = 0; i < pts->count; i++){
            double distance = 
                pow((points[i].x - startPt.x), 2) + pow((points[i].y - startPt.y),2);
            if (record_distance == 0 || distance < record_distance){
                record_distance = distance;
                record_pt = points[i];
            }
    }
    return record_pt;
}
