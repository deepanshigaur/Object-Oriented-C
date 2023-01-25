#ifndef LINE_H
#define LINE_H
#include "coord.h"

typedef struct line_struct * line;

line line_create(float slope,float y_intercept);
line line_from_coords(coord from,coord to);
void line_move(line ln,float dx,float dy);
float line_length(line ln);
coord line_intersect(line l1,line l2);
char * line_format(line ln);
void line_delete(line ln);
void line_deep_delete(line ln);

#endif