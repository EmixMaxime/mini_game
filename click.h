#ifndef CLICK_H
#define CLICK_H

#include <stdbool.h>
#include "variables.h"

typedef struct Line Line;
struct Line {
   int x1;
   int x2;
   int y;
   int width;
};

typedef struct Zone Zone;
struct Zone {
    Line top;
	Line bottom;
};

bool isClicableZone (int x, int y, Zone zone);
void * createClicableZone (Zone *zone);

#endif // CLICK_H
