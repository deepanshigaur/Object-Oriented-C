#include "coord.h"
#include <stdlib.h> // For malloc and free
#include <stdio.h> // For sprintf
#include <math.h> // for sqrt

struct coord_struct {
	float x;
	float y;
};

coord coord_create(float x,float y) {
	coord newxy=malloc(sizeof(struct coord_struct));
	newxy->x=x;
	newxy->y=y;
	return newxy;
}

float coord_getx(coord xy) { return xy->x; }
float coord_gety(coord xy) { return xy->y; }

void coord_move(coord xy,float dx,float dy) {
	xy->x+=dx;
	xy->y+=dy;
}

float coord_distance(coord from,coord to) {
	float xd=from->x-to->x;
	float yd=from->y-to->y;
	return sqrtf(xd*xd + yd*yd);
}

char * coord_format(coord xy) {
	static char buf[60]; // Big enough to hold the ASCII representation of a large coordinate
	if (xy==NULL) return "NULL";
	sprintf(buf,"(%f,%f)",xy->x,xy->y);
	return buf;
}

void coord_delete(coord xy) {
	if (xy!=NULL) free(xy);
}