#include "line.h"
#include "coord.h"
#include <stdio.h>

int main(int argc,char **argv) {
	// First, try making an x/y coordinate
	coord point=coord_create(3.5,7.2);
	printf("I made a coordinate: %s\n",coord_format(point));

	// Next, make a line that goes to that coordinate
	coord lf=coord_create(-4.2,1.3);
	printf("The distance between %s and",coord_format(point));
	printf("%s is %f\n",coord_format(lf),coord_distance(point,lf));

	line l1=line_from_coords(lf,point);
	printf("The line between those points has the formula: %s\n",line_format(l1));

	line l2=line_create(0,2.5);
	printf("My second line is: %s\n",line_format(l2));

	coord intercept=line_intersect(l1,l2);
	printf("The interception of the two lines is %s\n",coord_format(intercept));

	line_delete(l1);
	coord_delete(intercept);
	line_delete(l2);
	coord_delete(point);
	coord_delete(lf);
	return 0;
}