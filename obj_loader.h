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


struct model_v {
	float x;
	float y;
	float z;
};

struct model_vt {
	float x;
	float y;
	float z;
};

struct object_model {
	char name[56];
	unsigned long vertex_count;
	unsigned long textures_count;
	unsigned long normals_count;
	struct model_v *vertex;
	struct model_vt *texture;
};

void obj_loader_Init();
struct object_model* obj_load_model(const char *filename);
void obj_copy_vertex(struct model_v* dest, struct object_model *orig);


#endif
