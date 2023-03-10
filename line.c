#include "line.h"
#include <stdlib.h> // For malloc and free
#include <stdio.h> // For sprintf

struct line_struct {
	// Specify all the fields required to make a line
  float slope;
  float y_intercept;
};

line line_create(float slope,float y_intercept) {
   // Replace this with code to create a new line "object" and return a pointer to that object
	// The returned line should have a slope and y_intercept, as specified in the arguments.
	line newslopey_intercept =malloc(sizeof(struct line_struct));
	newslopey_intercept->slope=slope;
	newslopey_intercept->y_intercept=y_intercept;
	return newslopey_intercept;
}

line line_from_coords(coord from,coord to) {
	//return NULL; // Replace this with code to create a enw line "object" and return a pointer to that object
	// The returned line should go through both the from and to coordinates specified in the argument
	// Return NULL if both from and to have the same x coordinate (which would make the slope infinity)
	//if (from->x == to->x) {
		if (coord_getx(from) == coord_getx(to)){
        return NULL;
    }
    line newline  = malloc(sizeof(line));
    newline->slope = (coord_gety(to) - coord_gety(from)) / (coord_getx(to) - coord_getx(from));
    newline->y_intercept = coord_gety(from) - (newline->slope * coord_getx(from));
    return newline;
}

coord line_intersect(line l1,line l2) {
	//return NULL; // Replace with code to return a new coordinate where lines l1 and l2 intersect
	// Return NULL if lines l1 and l2 have the same slope. They are parallel and never intersect
	 if (l1->slope == l2->slope) {
        return NULL;
    }
    coord newCoord;
    float x = (l2->y_intercept - l1->y_intercept) / (l1->slope - l2->slope);
    float y = (l1->slope * x) + l1->y_intercept;
    newCoord = coord_create(x,y);
    return newCoord;
}

char * line_format(line ln) {
	//return ""; // Replace with code to return the pointer to a string that contains the formatted description of a line.
	// If ln is NULL, return "NULL"
	// The result should be in the form: "y = <m>x + <b>", 
	// where <m> and <b> are replaced by the floating point representation (%f)
	// of the slope and y-intercept of the line.
	// You may use a static char buffer (see coord_format for an example) to hold the
	// result, based on the assumption that the result will be used before line_format is called again.
	  static char buffer[100];
    if (ln == NULL) {
        return "NULL";
    }
    sprintf(buffer, "y = %fx + %f", ln->slope, ln->y_intercept);
    return buffer;
}

void line_delete(line ln) {
	// Add code to free any memory consumed by the ln line "object"
	 if (ln != NULL) {
        free(ln);
    }
}
