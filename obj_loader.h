#include <stdio.h>

#ifndef __OBJ_LOADER_HEADER__
#define __OBJ_LOADER_HEADER__

/*
type list:

v (geometric vertices)
vt (texture vertices)
vn (normal vertices)
vp (parameter vertices for  beziers)
deg (degrees)
bmat (basis matrix) not often used
step (step size) ????
*/

/* elements

point (p)

line (l)

face (f)

curve (curv)

2D curve (curv2)

surface (surf)

*/
/* 
geometric vertices
*/


struct obj_vertex {
	float x;
	float y;
	float z;
};

struct obj_vertex_texure {
	float x;
	float y;
	float z;
};


struct obj_model {
	char name[56];
	unsigned long vertices_count;
	struct obj_vertex* vertices;
};


struct obj_model *obj_loadfile(const char *filename);





#endif