#ifndef COORD_H
#define COORD_H

typedef struct coord_struct * coord;

coord coord_create(float x,float y);
float coord_getx(coord xy);
float coord_gety(coord xy);
void coord_move(coord xy,float dx,float dy);
float coord_distance(coord from,coord to);
char * coord_format(coord xy);
void coord_delete(coord xy);

#endif